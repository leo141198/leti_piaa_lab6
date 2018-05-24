#include "ACAlgorithm.h"

using namespace std;

ACAlgorithm::ACAlgorithm(const vector<string>& patterns, char skip_symbol) : bohr(new Bohr(skip_symbol)) {
    for(auto pattern : patterns) {
        bohr->addToBohr(pattern);
    }
}

shared_ptr<vector<string>> ACAlgorithm::find(std::string& text) {
    auto positions = bohr->find(text);
    positions->sort([](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    shared_ptr<vector<string>> result(new vector<string>);
    for(auto elem : *positions) {
        result->push_back(to_string(elem.first) + " " + to_string(elem.second));
    }
    return result;
}