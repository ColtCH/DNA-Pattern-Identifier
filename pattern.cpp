#include "pattern.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

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



/*
================================================================================
Input:   an integer that represents the length of kmer you want to find the
         greatest frequency of.

Return:  Void. Outputs a print statement with the most occuring kmer.
================================================================================
*/

void DNAPattern::mostOccuringKmer(int kmer){

  std::vector<char> temp_pattern_storage;
  std::unordered_map<std::string, int> pattern_storage;
  std::unordered_map<std::string, int>::iterator it;

  //Loop through every inidividual character in the DNA strand.
  for ( unsigned int i = 0; i < (DNA.length() -1); i++ ){
    //Look ahead kmer amount of times to form a 'pattern', then
    //push that pattern into the temp_pattern_storage.
    for ( int j = 0; j < kmer; j++ ){
      temp_pattern_storage.push_back (DNA[i+j]);
    }
    bool unique_pattern = true;

    std::string DNA_pattern_name(temp_pattern_storage.begin(), temp_pattern_storage.end());

    it = pattern_storage.begin();
    //If it's not empty, we've gotta check the existing patterns.
    while (unique_pattern == true && it != pattern_storage.end()){
      if ( it->first == DNA_pattern_name ) {
        it->second += 1;
        unique_pattern = false;
      }
      it++;
    }
    if (unique_pattern) {
      pattern_storage.insert( make_pair(DNA_pattern_name, 1));
    }

    temp_pattern_storage.clear();
    DNA_pattern_name.clear();
    unique_pattern = true;
  }



 //this handles getting the max from all_pattern and the name of the kmer ------

 for ( it = pattern_storage.begin(); it != pattern_storage.end(); it++ ){
   std::cout << it->first << ' ' << it->second << std::endl;
 }

  //----------------------------------------------------------------------------
}
