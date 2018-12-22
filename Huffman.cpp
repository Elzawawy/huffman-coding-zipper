//
// Created by zawawy on 12/22/18.
//

#include "Huffman.h"

int Huffman::myCompartor::operator()(Node *node1, Node *node2) {
    return node1->getFrequency() > node2->getFrequency();
}
