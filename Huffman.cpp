//
// Created by zawawy on 12/22/18.
//

#include "Huffman.h"

int Huffman::myCompartor::operator()(Node *node1, Node *node2) {
    return node1->getFrequency() > node2->getFrequency();
}

void Huffman::huffer(unordered_map<char, int> frequencyMap) {
    priority_queue<Node*, vector<Node*>, myCompartor> HufferQueue;
    string tempString;
    Node * leftNode , * rightNode, * newNode;
    for (const auto &item : frequencyMap)
        HufferQueue.push(new Node(item.first,item.second));

    while(HufferQueue.size() != 1)
    {
        leftNode = HufferQueue.top();
        HufferQueue.pop();
        rightNode = HufferQueue.top();
        HufferQueue.pop();
        newNode = new Node('|',leftNode->getFrequency() + rightNode->getFrequency());
        HufferQueue.push(newNode);
        newNode->setLeft(leftNode);
        newNode->setRight(rightNode);
    }
    encodeCharacters(HufferQueue.top(),tempString);

    for (const auto &item : codeMap)
        cout <<item.first <<item.second<<endl;

}

void Huffman::encodeCharacters(Node *rootNode, string codeString) {

    if (!rootNode)
        return;
    if (rootNode->getCharacter()!= '|'){
        codeMap[rootNode->getCharacter()] = codeString;

    }
    encodeCharacters(rootNode->getLeft(), codeString + "0");
    encodeCharacters(rootNode->getRight(), codeString + "1");
}

void Huffman::compressTofile(string fileName) {
    char character;
    string file;
    ifstream inputStream;
    ofstream outputStream;
    outputStream.open(fileName,ios::in);
    inputStream.open("../input.txt", ios::in);
    while(inputStream.get(character))
        file += codeMap[character];
    inputStream.close();

    stringstream stringStream(file);
    while(stringStream.good())
    {
        bitset<8> bits;
        stringStream >> bits;
        char c = char(bits.to_ulong());
        outputStream << c;
        cout << c;
    }


    outputStream.flush();
    outputStream.close();
}
