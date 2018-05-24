#ifndef PIAA_LAB6_KMPALGORITHM_H
#define PIAA_LAB6_KMPALGORITHM_H

#include <string>
#include <vector>
#include <list>
#include "Bohr.h"

using namespace std;

class ACAlgorithm {
public:
    ACAlgorithm(const vector<string>& patterns, char skip_symbol = 0);

    shared_ptr<vector<string>> find(string& text);

private:
    Bohr* bohr;
};

#endif