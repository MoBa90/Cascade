#include <classifier.h>
#include <cascade.h>

Cascade::Cascade(Classifier root, std::vector<Classifier> firstLevel,
                 std::vector<std::vector<Classifier>> secondLevel){

    this->root = root;
    this->firstLevel = firstLevel;
    this->secondLevel = secondLevel;

}

std::vector<Node> Cascade::run(std::vector<Node>& imgsNodes){

    std::vector<std::vector<Node>> firstLevelResults;
    std::vector<std::vector<Node>> secondLevelResults;
    std::vector<Node> tmpRootResults;
    tmpRootResults = root.Classify(imgsNodes, 2);


    for(int i = 0; i < firstLevel.size();i++){
        std::vector<Node> tmpFirstLevelResult;
        tmpFirstLevelResult = firstLevel[i].Classify(tmpRootResults);
        for(int j=0; j<secondLevel[i].size(); j++){
            std::vector<Node> tmpSecondLevelResult;
            tmpSecondLevelResult = secondLevel[i][j].Classify(tmpFirstLevelResult,2);
            secondLevelResults.push_back(tmpSecondLevelResult);
        }
        firstLevelResults.push_back(tmpFirstLevelResult);
    }


    for(int i =0; i<secondLevelResults.size();i++){
        results.insert(results.end(), secondLevelResults[i].begin(), secondLevelResults[i].end());
    }

    return results;
//    for (int i =0; i<imgsNodes.size(); i++){
//        Node tmpNode = results[i];
//        tmpNode.predictions = root.Classify()




//    }


}

void Cascade::setRoot(Classifier c){
    this->root = c;
}
void Cascade::setFirstLevel(std::vector<Classifier> fl){
    this->firstLevel = fl;
}
void Cascade::setSecondLevel(std::vector<std::vector<Classifier>> sl){
    this->secondLevel = sl;
}
