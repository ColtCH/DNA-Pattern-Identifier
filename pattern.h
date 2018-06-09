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

  /*NOTE:
          all DNA strands and their corresponding compliments that have been
          processed through the findCompliment method are stored here for later
          comparisons.*/

  std::vector<std::unordered_map<std::string, std::string>> kmer_compliments;

public:

              DNAPattern        (std::string); //MUST have some sort of string associated with it.
  int         checkForKmer      (std::string);
  void        printUnorderedMap (unsigned int kmer);
  void        mostOccuringKmer  (int);
  int         getDNALength      ();
  std::string findSuspiciousKmer(unsigned int);
  std::string findCompliment    (std::string);

};

#endif //PATTERN_H_
