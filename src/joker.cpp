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
    wchar_t skip_symbol;
    wcin >> text;
    wcin >> input;
    wcin >> skip_symbol;
    patterns.push_back(input);

    auto alg = new ACAlgorithm(patterns, skip_symbol);
    auto result = alg->find(text);
    for(auto elem : *result) {
        cout << elem.substr(0, elem.find(' ')) << endl;
    }
    return 0;
}