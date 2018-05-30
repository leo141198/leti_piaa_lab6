#include <iostream>
#include <codecvt>
#include "ACAlgorithm.h"

using namespace std;

int main() {
    std::locale::global(std::locale(std::locale(""), new std::codecvt_utf8<wchar_t>));
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());
    std::wcerr.imbue(std::locale());
    vector<wstring> patterns;
    wstring text;
    wstring input;
    int num;
    wcin >> text;
    cin >> num;
    for(int i = 0; i < num; i++) {
        wcin >> input;
        patterns.push_back(input);
    }

    auto alg = new ACAlgorithm(patterns);
    auto result = alg->find(text);
    for(auto elem : *result) {
        cout << elem << endl;
    }
    return 0;
}