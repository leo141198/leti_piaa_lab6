#include <iostream>
#include <codecvt>
#include "ACTest.h"

using namespace std;

int main(int argc, char* argv[]) {
    std::locale::global(std::locale(std::locale(""), new std::codecvt_utf8<wchar_t>));
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());
    std::wcerr.imbue(std::locale());
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

INSTANTIATE_TEST_CASE_P(Default, ACTest_ac, ::testing::Values(
        test_type_ac(L"abcdefabc", wstring_array(new vector<wstring>{L"abc", L"de"}),
                     string_array(new vector<string>{"1 1", "4 2", "7 1"})),
        test_type_ac(L"абвгдеабв", wstring_array(new vector<wstring>{L"абв", L"гд"}),
                     string_array(new vector<string>{"1 1", "4 2", "7 1"})),
        test_type_ac(L"1123123331123", wstring_array(new vector<wstring>{L"123", L"33", L"333", L"11", L"3331"}),
                     string_array(new vector<string>{"1 4", "2 1", "5 1", "7 2", "7 3", "7 5", "8 2", "10 4", "11 1"})),
        test_type_ac(L"ababab", wstring_array(new vector<wstring>{L"abab"}),
                     string_array(new vector<string>{"1 1", "3 1"}))
));

TEST_P(ACTest_ac, test_eq) {
    wcout << COUT_GTEST_MGT << "Checking text \"" << text << "\" and patterns \"";
    for(const auto pattern : *patterns) {
        wcout << pattern << " ";
    }
    wcout << "\"" << ANSI_TXT_DFT << endl;
    auto result = aho_corasick->find(text);
    EXPECT_EQ(result->size(), exp_result->size());
    auto iter_1 = result->begin();
    auto iter_2 = exp_result->begin();
    for(; iter_1 != result->end() && iter_2 != exp_result->end(); iter_1++, iter_2++) {
        EXPECT_EQ(*iter_1, *iter_2);
    }
}