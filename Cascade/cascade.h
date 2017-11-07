#ifndef CASCADE_H
#define CASCADE_H


#include "classifier.h"
#include "node.h"

class Cascade {
public:
  Cascade(Classifier root, std::vector<Classifier> firstLevel,
          std::vector<std::vector<Classifier>> secondLevel);

  std::vector<Node> run(std::vector<Node>& imgsNodes);

private:
  Classifier root;
  std::vector<Classifier> firstLevel;
  std::vector<std::vector<Classifier>> secondLevel;

public:
  void setRoot(Classifier c);
  void setFirstLevel(std::vector<Classifier> fl);
  void setSecondLevel(std::vector<std::vector<Classifier>> sl);
  std::vector<Node> results;


};

#endif // CASCADE_H
