#include "Bohr.h"

using namespace std;

Bohr::Bohr(char skip_symbol) : skip(skip_symbol) {
    bohr.push_back(new Node(0, '$'));
}

void Bohr::addToBohr(const string& pattern) {
    int num = 0;
    for(char symb : pattern) {
        if(bohr[num]->next_nodes.find(symb) == bohr[num]->next_nodes.end()) {
            bohr.push_back(new Node(num, symb));
            bohr[num]->next_nodes[symb] = bohr.size() - 1;
        }
        num = bohr[num]->next_nodes[symb];
    }
    bohr[num]->flag = true;
    patterns.push_back(pattern);
    bohr[num]->pattern_index = patterns.size() - 1;
}

int Bohr::getSuffixLink(int node) {
    if(bohr[node]->sfx_link == -1) {
        if(node == 0 || bohr[node]->parent == 0) {
            bohr[node]->sfx_link = 0;
        } else {
            bohr[node]->sfx_link = getMove(
                    getSuffixLink(bohr[node]->parent), bohr[node]->symb);
        }
    }
    return bohr[node]->sfx_link;
}

int Bohr::getMove(int node, char symb) {
    if(bohr[node]->move.find(symb) == bohr[node]->move.end()) {
        if(bohr[node]->next_nodes.find(symb) != bohr[node]->next_nodes.end()) {
            bohr[node]->move[symb] = bohr[node]->next_nodes[symb];
        } else if(bohr[node]->next_nodes.find(skip) != bohr[node]->next_nodes.end()) {
            bohr[node]->move[symb] = bohr[node]->next_nodes[skip];
        } else if(node == 0) {
            bohr[node]->move[symb] = 0;
        } else {
            bohr[node]->move[symb] = getMove(getSuffixLink(node), symb);
        }
    }
    return bohr[node]->move[symb];
}

void Bohr::check(int node, int i, list<pair<int, int>>& result) {
    for(int u = node; u != 0; u = getSuffixLink(u)) {
        if(bohr[u]->flag) {
            auto a = i + 2 - patterns[bohr[u]->pattern_index].length();
            auto b = bohr[u]->pattern_index + 1;
            result.emplace_front(i + 2 - patterns[bohr[u]->pattern_index].length(), bohr[u]->pattern_index + 1);
        }
    }
}

shared_ptr<list<pair<int, int>>> Bohr::find(const string& text) {
    shared_ptr<list<pair<int, int>>> result(new list<pair<int, int>>);
    int u = 0;
    for(int i = 0; i < text.length(); i++) {
        u = getMove(u, text[i]);
        check(u, i, *result);
    }
    return result;
}
