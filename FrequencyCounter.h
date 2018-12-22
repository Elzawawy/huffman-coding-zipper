/*
*
* FrequencyCounter module is to read input file and count frequency for each character.
*
*/
#include <string.h>
#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;
#ifndef FREQUENCY_COUNTER_H_
#define FREQUENCY_COUNTER_H_



class FrequencyCounter {
    unordered_map<char,int> frequencyMap;

public:
    const unordered_map<char, int> &getFrequencyMap() const;
    void readFile(string fileName);


};


#endif  /*FREQUENCY_COUNTER_H_*/