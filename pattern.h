#ifndef _PATTERN_H_
#define _PATTERN_H_

#include <string>

class DNAPattern {

private:

  std::string DNA;

public:

       DNAPattern       (std::string); //MUST have some sort of string associated with it.
  int  checkForKmer     (std::string);
  void mostOccuringKmer (int);

};

#endif //PATTERN_H_
