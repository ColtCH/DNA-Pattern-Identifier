#ifndef _PATTERN_H_
#define _PATTERN_H_

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

class DNAPattern {

private:

  std::string DNA;

  /*NOTE:
          all kmer frequency tables are pushed into this vector. Any element
          within this vector can be printed out. This keeps things tidy.*/
  std::vector<std::unordered_map<std::string, int>> kmer_patterns;

public:

       DNAPattern        (std::string); //MUST have some sort of string associated with it.
  int  checkForKmer      (std::string);
  void printUnorderedMap (unsigned int kmer);
  void mostOccuringKmer  (int);
  int  getDNALength      ();
  void findSuspiciousKmer(unsigned int);

};

#endif //PATTERN_H_
