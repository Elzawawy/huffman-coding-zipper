//
// Created by zawawy on 12/22/18.
//

#ifndef HUFFMANCODING_NODE_H
#define HUFFMANCODING_NODE_H


class Node {
    char charcter;
    int frequency;
public:
    int getFrequency() const;

private:
    Node * left, * right;
public:
    Node(char character, int frequency);

    Node *getLeft() const;

    Node *getRight() const;

};


#endif //HUFFMANCODING_NODE_H
