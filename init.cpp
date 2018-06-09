#include "pattern.h"
#include <iostream>
#include <fstream>

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

  //std::string DNA_pattern_2          = "AATCGTAACCGTTGACAGTA";
  //std::string DNA_pattern_2_comp     = pattern_one->findCompliment(DNA_pattern_2);

  std::cout << DNA_pattern
            << "'s compliment is "
            << DNA_pattern_compliment
            << std::endl;

  //std::cout << DNA_pattern_2
  //          << "'s compliment is "
  //          << DNA_pattern_2_comp
  //          << std::endl;

  return 0;
}
