#include "pattern.h"

/*Compiler complains about not initializing this vector. There is nothing useful
  that I can put inside the vector at this point, and I wish it would shut up.*/
DNAPattern::DNAPattern(std::string DNA) : DNA(DNA) {}

/*
================================================================================
Input:   A string that will be compared against the existing DNA strand.

Return:  Integer representing the total matches found in the DNA strand.
================================================================================
*/
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

  std::vector<char> temp_pattern_storage;              //temporary pattern made
                                                       //from vector push_back.

  std::unordered_map<std::string, int> pattern_storage;//unordered_map replicates
                                                       //dictionary from Python.
                                                       //All patterns and their
                                                       //occurences end up here.

  std::unordered_map<std::string, int>::iterator it;   //How we iterate through
                                                       //the unordered_map.

  int j = 0;                                           //j has to be declared
                                                       //here for the loop
                                                       //conditional to work.
  for ( unsigned int i = 0; i+j <= DNA.length(); i++ ){

    //Look ahead kmer amount of times to form a 'pattern', then
    //push that pattern into the temp_pattern_storage.
    for ( j = 0; j < kmer; j++ ){
      temp_pattern_storage.push_back (DNA[i+j]);
    }

    bool unique_pattern = true;                               //Used to control
                                                              //when the while
                                                              //loop breaks.

    std::string DNA_pattern_name(temp_pattern_storage.begin(),//Restructuring
                                 temp_pattern_storage.end()); //the vector of
                                                              //chars as a
                                                              //string.

    it = pattern_storage.begin();                             //Set the iterator.

    //CHECKS DNA FOR REPEATS
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
  kmer_patterns.push_back(pattern_storage);
}

/*
================================================================================
Input:   an integer of the kmer you want the frequency of.

Return:  Void. Outputs a print statement of the specified kmer.
================================================================================
*/
void DNAPattern::printUnorderedMap ( unsigned int kmer ){

  //Loop through all pushed patterns.
  for ( unsigned int i = 0; i < kmer_patterns.size(); i++ ){
    for ( auto it = kmer_patterns[i].begin(); it != kmer_patterns[i].end(); it++ ){
      if ( it->first.size() == kmer) {
        std::cout << it->first << ' ' << it->second << std::endl;
      }
    }
  }
}

/*
================================================================================
Input:   an integer of the kmer you want to start the search at.

Return:  Void. Outputs a print statement of the kmer with the highest 'score'.
================================================================================
*/
std::string DNAPattern::findSuspiciousKmer (unsigned int starting_point){

  long double max = 0;     //stores the currently most suspicious kmer.
  std::string name;        //stores name of the suspicious kmer.
  int occurences = 0;      //stores the amount of times the kmer occured.

  /*Loop through the vector and the elements within the unordered map*/
  for ( unsigned int i = 0; i < kmer_patterns.size(); i++ ){
    for ( auto it = kmer_patterns[i].begin(); it != kmer_patterns[i].end(); it++ ){

      /*We can't assume the vector is storing the maps in order. Therefore, we
        have to check for the starting point.*/

      if ( it->first.size() > starting_point ){
        long double val = pow(.25, it->first.size()) * it->second * DNA.length();

        /*If a more suspicious kmer is found, store it.*/
        if ( val > max ) {
          max = val;
          name = it->first;
          occurences = it->second;
        }

      }
    }
  }

  /*Output findings to console.*/
  std::cout << name
            << " occured "
            << occurences
            << " times, with a score of "
            << max
            << "."
            << std::endl;

  return name;
}

/*
================================================================================
Input:   a string that you want to find the compliment of.

Return:  The compliment of the string inputed.
================================================================================
*/

std::string DNAPattern::findCompliment(std::string DNA_strand){

  std::string DNA_strand_compliment;
  DNA_strand_compliment.resize(DNA_strand.size());

  for ( unsigned int i = 0; i < DNA_strand.size(); i++ ){
    if ( DNA_strand[i] == 'A') { DNA_strand_compliment[i] = 'T'; }
    if ( DNA_strand[i] == 'T') { DNA_strand_compliment[i] = 'A'; }
    if ( DNA_strand[i] == 'C') { DNA_strand_compliment[i] = 'G'; }
    if ( DNA_strand[i] == 'G') { DNA_strand_compliment[i] = 'C'; }
  }

  std::reverse(DNA_strand_compliment.begin(), DNA_strand_compliment.end());

  /*
    This part is the reason this is a method of DNAPattern. Every pattern and
    its compliment that is put into this method is stored inside of the object
    so that it can be used for any number of things.
  */

  std::unordered_map<std::string, std::string> DNA_pattern_storage;
  DNA_pattern_storage.insert(make_pair(DNA_strand, DNA_strand_compliment));
  kmer_compliments.push_back (DNA_pattern_storage);

  return DNA_strand_compliment;
}

/*
================================================================================
Input:   Range (low and high, integers), which will be used to parse a specific part of
         the DNA string associated with this object.

Return:  string stream of the text of the results.
================================================================================
*/
int DNAPattern::findSkew(int range_low, int range_high){

  int skew = 0;
  int minimum = 0;

  for ( int i = range_low; i < range_high; i++ ){
    ( DNA[i] == 'C' ) ? skew -= 1 : skew += 1;
    if ( skew <= minimum ) { std::cout << i << std::endl; minimum = skew; }


  }

  return minimum;

}
/*
================================================================================
Input:   Two strings that will be compared for their number of mismatches.

Return:  string stream of the text of the results.
================================================================================
*/

int DNAPattern::findMismatches(std::string first, std::string second){

  int mismatches = 0;

  /*If they aren't equal, they won't be compared.*/
  if ( first.size() != second.size() ) {
    std::cout << "Inequal size."
              << std::endl;
    return 0;
  }

  for ( unsigned int i = 0; i < first.size(); i++ ){
    if ( first[i] != second[i] ) { mismatches++; }
  }
  return mismatches;
}

/*
================================================================================
Input:   A string to be compared against the currently stored DNA object, and an
         integer that represents the maximum amount of mutations that can be
         tolerated.

Return:  Integer that represents the number of matches found.
================================================================================
*/
int DNAPattern::findApproxMatches(std::string DNA_strand, int max_mutations){

  int approximate_matches = 0;
  for ( unsigned int i = 0; i < DNA.length(); i++ ){
    int found_mutations = 0;
    for ( unsigned int j = 0; j < DNA_strand.length(); j++ ){
      if ( DNA[i+j] != DNA_strand[j] ) { found_mutations++; }
    }
    if ( found_mutations <= max_mutations ) { approximate_matches++; }
  }
  return approximate_matches;



}

//GETTERS & SETTERS=============================================================
int DNAPattern::getDNALength(){ return DNA.length(); }
