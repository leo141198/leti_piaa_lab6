#ifndef PIAA_LAB6_NODE_H
#define PIAA_LAB6_NODE_H

#include <map>

struct Node {
    Node(int parent, wchar_t symb) : parent(parent), symb(symb), flag(false), sfx_link(-1), sfx_good_link(-1) {}
    std::map<wchar_t, int> next_nodes;
    std::map<wchar_t, int> move;
    bool flag;
    int pattern_index;
    int sfx_link;
    int sfx_good_link;
    int parent;
    wchar_t symb;
};


#endif //PIAA_LAB6_NODE_H
