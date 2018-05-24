#ifndef PIAA_LAB6_NODE_H
#define PIAA_LAB6_NODE_H

#include <map>

struct Node {
    Node(int parent, char symb) : parent(parent), symb(symb), flag(false), sfx_link(-1), sfx_good_link(-1) {}
    std::map<char, int> next_nodes;
    std::map<char, int> move;
    bool flag;
    int pattern_index;
    int sfx_link;
    int sfx_good_link;
    int parent;
    char symb;
};


#endif //PIAA_LAB6_NODE_H
