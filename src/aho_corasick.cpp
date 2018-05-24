#include <iostream>
#include "ACAlgorithm.h"

using namespace std;

int main() {
    vector<string> patterns;
    string text;
    string input;
    int num;
    cin >> text;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> input;
        patterns.push_back(input);
    }

    auto alg = new ACAlgorithm(patterns);
    auto result = alg->find(text);
    for(auto elem : *result) {
        cout << elem << endl;
    }
    return 0;
}