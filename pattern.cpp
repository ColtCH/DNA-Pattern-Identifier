#include "pattern.h"
#include <iostream>

DNAPattern::DNAPattern(std::string DNA) : DNA(DNA) {}

int DNAPattern::checkForKmer(std::string pattern) {

  int number_of_matches = 0;
  bool correct_match = true;

  for ( unsigned int i = 0; i < DNA.length(); i++ ){

    if (DNA[i] == pattern[0]){

      for ( unsigned int j = 1; j < pattern.length(); j++ ){
        if (DNA[i+j] == pattern[j]) { correct_match = true;   }
        if (DNA[i+j] != pattern[j]) { correct_match = false;  }

      } if (correct_match) { number_of_matches++; }
    }
  }
  return number_of_matches;
}
