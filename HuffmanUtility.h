//
// Created by zawawy on 12/25/18.
//
#include <string.h>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
#ifndef HUFFMANCODING_HUFFMANUTILITY_H
#define HUFFMANCODING_HUFFMANUTILITY_H


class HuffmanUtility {
public:
    void writeHeader(ofstream &outputStream,unordered_map<char,string> codeMap);
    unordered_map<char,string> readHeader(ifstream &inputStream);
};


#endif //HUFFMANCODING_HUFFMANUTILITY_H
