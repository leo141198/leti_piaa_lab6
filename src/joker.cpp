#include <iostream>
#include "ACAlgorithm.h"

using namespace std;

int main() {
    vector<string> patterns;
    string text;
    string input;
    char skip_symbol;
    cin >> text;
    cin >> input;
    cin >> skip_symbol;
    patterns.push_back(input);

    auto alg = new ACAlgorithm(patterns, skip_symbol);
    auto result = alg->find(text);
    for(auto elem : *result) {
        cout << elem.substr(0, elem.find(' ')) << endl;
    }
    return 0;
}