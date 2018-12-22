//
// Created by zawawy on 12/22/18.
//

#include "Node.h"

Node::Node(char character, int frequency) {

    this->left = this->right = nullptr;
    this->charcter = character;
    this->frequency = frequency;

}

int Node::getFrequency() const {
    return frequency;
}

Node *Node::getLeft() const {
    return left;
}

Node *Node::getRight() const {
    return right;
}
