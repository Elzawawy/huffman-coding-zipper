//
// Created by zawawy on 12/22/18.
//
#include <string.h>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

#ifndef HUFFMANCODING_HUFFER_H
#define HUFFMANCODING_HUFFER_H


class Huffman {

    unordered_map<char,string> codeMap;
    void encodeCharacters(Node * rootNode, string codeString);
    class myCompartor{
    public :
        int operator() (Node* node1, Node* node2);
    };
public :
    void huffer(unordered_map<char, int> frequencyMap);
    void compressTofile(string fileName);


};



#endif //HUFFMANCODING_HUFFER_H
