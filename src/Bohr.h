#ifndef PIAA_LAB6_BOHR_H
#define PIAA_LAB6_BOHR_H

#include <vector>
#include <list>
#include <string>
#include "Node.h"

class Bohr {
public:
    Bohr(char skip_symbol = 0);

    void addToBohr(const std::string& pattern);

    int getSuffixLink(int node);

    int getMove(int node, char symb);

    void check(int node, int i, std::list<std::pair<int, int>>& result);

    std::shared_ptr<std::list<std::pair<int, int>>> find(const std::string& text);

private:
    char skip;
    std::vector<Node*> bohr;
    std::vector<std::string> patterns;
};


#endif //PIAA_LAB6_BOHR_H
