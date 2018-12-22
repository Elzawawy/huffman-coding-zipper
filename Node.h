//
// Created by zawawy on 12/22/18.
//

#ifndef HUFFMANCODING_NODE_H
#define HUFFMANCODING_NODE_H


class Node {
    char character;
    int frequency;
public:
    int getFrequency() const;

private:
    Node * left, * right;
public:
    Node(char character, int frequency);
    Node(char character);

    Node *getLeft() const;

    Node *getRight() const;

    void setLeft(Node *left);

    void setRight(Node *right);

    char getCharacter() const;

};


#endif //HUFFMANCODING_NODE_H
