#include "pattern.h"
#include <iostream>
#include <fstream>
/*
================================================================================
This main is a demo reel of the program. It showcases the majority of the
functionality of the class DNA, which can be found in 'pattern.h'.
================================================================================
*/

int main(int argc, char const *argv[]) {

  if (argc != 2) { std::cout << "Incorrect amount of arguments."
                             << std::endl
                             << "Correct usage: "
                             << std::endl
                             << "./PATTERN DNA_input_file.txt"
                             << std::endl;
                             return 1; }

  std::ifstream DNA_input_file(argv[1]);

  std::string DNA_string;



  char c; //We use this char to determine when NULL is reached.

  while (DNA_input_file.get(c)){ //Make sure next value isn't NULL.
     DNA_input_file >> DNA_string;
   }

  DNAPattern *pattern_one = new DNAPattern(DNA_string);

  for ( int i = 1; i <= 3; i++ ){
    pattern_one->mostOccuringKmer(i);
    pattern_one->printUnorderedMap(i);
  }

  std::string DNA_pattern            = pattern_one->findSuspiciousKmer(2);
  std::string DNA_pattern_compliment = pattern_one->findCompliment(DNA_pattern);

  int         DNA_skew               = pattern_one->findSkew(0, pattern_one->getDNALength());

  std::cout << DNA_skew << std::endl;

  std::cout << DNA_pattern
            << "'s compliment is "
            << DNA_pattern_compliment
            << std::endl;


  std::string first  = "AABAB";
  std::string second = "AABAA";

  int mismatches = pattern_one->findMismatches(first, second); //This is a test,
                                                               //and not how this
                                                               //would be used in
                                                               //any realistic
                                                               //setting.

  std::cout << "Number of mismatches between "
            << first
            << " and "
            << second
            << " is "
            << mismatches
            << "."
            << std::endl;

  std::string small_DNA = "AAB";

  int approximate_matches = pattern_one->findApproxMatches(small_DNA, 2);

  std::cout << "Approximate matches of"
            << small_DNA
            << "found in DNA is "
            << approximate_matches
            << "."
            << std::endl;

  return 0;

}
