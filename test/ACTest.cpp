#include "ACTest.h"

void ACTest_joker::SetUp() {
    auto params = GetParam();
    patterns = wstring_array(new vector<wstring>{std::get<1>(params)});
    skip_symbol = std::get<2>(params);
    aho_corasick = new ACAlgorithm(*patterns, skip_symbol);
    text = std::get<0>(params);
    exp_result = std::get<3>(params);
}

void ACTest_ac::SetUp() {
    auto params = GetParam();
    patterns = std::get<1>(params);
    aho_corasick = new ACAlgorithm(*patterns);
    skip_symbol = 0;
    text = std::get<0>(params);
    exp_result = std::get<2>(params);
}