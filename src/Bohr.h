#ifndef PIAA_LAB6_BOHR_H
#define PIAA_LAB6_BOHR_H

#include <vector>
#include <list>
#include <string>
#include "Node.h"

class Bohr {
public:
    Bohr(wchar_t skip_symbol = 0);

    void addToBohr(const std::wstring& pattern);

    int getSuffixLink(int node);

    int getMove(int node, wchar_t symb);

    void check(int node, int i, std::list<std::pair<int, int>>& result);

    std::shared_ptr<std::list<std::pair<int, int>>> find(const std::wstring& text);

private:
    wchar_t skip;
    std::vector<Node*> bohr;
    std::vector<std::wstring> patterns;
};


#endif //PIAA_LAB6_BOHR_H
