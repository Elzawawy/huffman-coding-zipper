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

//    for (const auto &item : codeMap)
//        cout <<item.first <<item.second<<endl;

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
    outputStream.open(fileName,ios::out);
    inputStream.open("../input.txt", ios::in);
    writeHeader(outputStream);
    while(inputStream.get(character))
        file += codeMap[character];
    inputStream.close();

    stringstream stringStream(file);

    while(stringStream.good())
    {

        bitset<8> bits;
        stringStream >> bits;

        if(bits==0)
            break;
        char c = char(bits.to_ulong());

        outputStream << c;
    }


    outputStream.flush();
    outputStream.close();
}

void Huffman::writeHeader(ofstream &outputStream) {
    for (const auto &item : codeMap)
       outputStream << item.first << ':' << item.second << ' ';
    outputStream << '|';
}

void Huffman::deHuffer(string compressedFileName,string decompressedFileName) {
    char character;
    string codeString;
    ifstream inputStream;
    inputStream.open(compressedFileName, ios::in);
    readHeader(inputStream);
    while(inputStream.get(character))
    {
        bitset<8> bits(character);
        cout<<bits.to_ulong()<<endl;
        codeString+=bits.to_string();


    }
    Node *rootNode=buildDecodingTree(codeMap);
    decompressToFile(codeString,rootNode,decompressedFileName);


}

void Huffman::readHeader(ifstream &inputStream) {
    codeMap.clear();
    char character;
    inputStream.get(character);
    char key = character;
    while(character != '|'){
        if(character == ':')
        {
            while(character != ' ')
            {
                inputStream.get(character);
                codeMap[key] += character;
            }
        }
        else
            key = character;
        inputStream.get(character);
    }

        for (const auto &item : codeMap)
        cout <<item.first <<item.second<<endl;
}

Node* Huffman::buildDecodingTree(unordered_map<char, string> encodingMap) {

    Node* rootNode=new Node('|');
    Node* previousNode;

    for (const auto &item : encodingMap){
        previousNode=rootNode;


        Node*newNode=new Node(item.first);

        string characterCode=item.second;

        for (int i = 0; i < characterCode.size(); ++i) {
            if(characterCode[i]=='0') {
                if (i == characterCode.size() - 1)
                    previousNode->setLeft(newNode);
                else {
                    if (!previousNode->getLeft()) {
                        previousNode->setLeft(new Node('|'));
                        previousNode = previousNode->getLeft();
                    }
                    else previousNode = previousNode->getLeft();
                }
            } else{
                if (i == characterCode.size() - 1)
                    previousNode->setRight(newNode);
                else {
                    if (!previousNode->getRight()) {
                        previousNode->setRight(new Node('|'));
                        previousNode = previousNode->getRight();
                    }
                    else previousNode = previousNode->getRight();
                }
            }
        }

    }
    return rootNode;
}

void Huffman::decompressToFile(string codeString, Node *rootNode,string decompressedFileName) {
    ofstream outputStream;
    outputStream.open(decompressedFileName,ios::out);
    Node *traversingPointer=rootNode;
    //cout<<codeString;

    for (int i = 0; i < codeString.size(); ++i){
        cout<<traversingPointer->getCharacter()<<endl;
        if(traversingPointer->getCharacter()!='|') {
            outputStream << traversingPointer->getCharacter();
            traversingPointer=rootNode;
        } else{
            if(codeString[i] == 0)
                traversingPointer = traversingPointer->getLeft();
            else
                traversingPointer = traversingPointer->getRight();

        }

    }
    outputStream.flush();
    outputStream.close();

}

