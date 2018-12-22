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

    void Huffer(unordered_map<char,int> frequencyMap);

    class myCompartor{
    public :
        int operator() (Node* node1, Node* node2);
    };

    priority_queue<Node*, vector<Node*>, myCompartor> minHeap;
};



#endif //HUFFMANCODING_HUFFER_H
