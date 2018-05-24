#include "ACTest.h"

void ACTest_joker::SetUp() {
    auto params = GetParam();
    patterns = std::get<1>(params);
    skip_symbol = std::get<2>(params);
    aho_corasick = new ACAlgorithm(*patterns, skip_symbol);
    text = std::get<0>(params);
}

void ACTest_ac::SetUp() {
    auto params = GetParam();
    patterns = params.second;
    aho_corasick = new ACAlgorithm(*patterns);
    skip_symbol = 0;
    text = params.first;
}

string_array ACTest::findAllOccurrences() {
    list<pair<int, int>> positions;
    int i = 0;
    for(auto iter = patterns->begin(); iter != patterns->end(); iter++, i++) {
        findOccurrences(positions, *iter, i);
    }
    positions.sort([](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });
    string_array result(new vector<string>);
    for(auto elem : positions) {
        result->push_back(to_string(elem.first) + " " + to_string(elem.second));
    }
    return result;
}

void ACTest::findOccurrences(list<pair<int, int>>& positions, string& pattern, int k) {
    bool flag;
    for(int i = 0; i < text.length(); i++) {
        flag = false;
        if((text[i] == pattern[0] || pattern[0] == skip_symbol) && (text.length() - i >= pattern.length())) {
            for(int j = 1; j < pattern.length(); j++) {
                if(text[i + j] != pattern[j] && pattern[j] != skip_symbol) {
                    flag = true;
                    break;
                }
            }
            if(flag) {
                continue;
            }
            positions.emplace_back(i + 1, k + 1);
        }
    }
}