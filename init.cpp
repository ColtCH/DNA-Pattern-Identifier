#include "pattern.h"
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {

  if (argc != 3) { std::cout << "Incorrect amount of arguments."
                             << std::endl
                             << "Correct usage: "
                             << std::endl
                             << "./PATTERN DNA_input_file.txt kmer_string"
                             << std::endl;
                             return 1; }

  std::ifstream DNA_input_file(argv[1]);

  std::string DNA_string;

  char c; //We use this char to determine when NULL is reached.

  while (DNA_input_file.get(c)){ //Make sure next value isn't NULL.
     DNA_input_file >> DNA_string;
   }

  DNAPattern *pattern_one = new DNAPattern(DNA_string); //test case

  std::cout << "Number of matches with pattern "
            << argv[2]
            << ": "
            << pattern_one->checkForKmer(argv[2])
            << std::endl;

  return 0;
}
