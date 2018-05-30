#ifndef PIAA_LAB6_KMPALGORITHM_H
#define PIAA_LAB6_KMPALGORITHM_H

#include <string>
#include <vector>
#include <list>
#include <cwchar>
#include "Bohr.h"

using namespace std;

class ACAlgorithm {
public:
    ACAlgorithm(const vector<wstring>& patterns, wchar_t skip_symbol = 0);

    shared_ptr<vector<string>> find(wstring& text);

private:
    Bohr* bohr;
};

#endif