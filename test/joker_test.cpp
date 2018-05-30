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

INSTANTIATE_TEST_CASE_P(Default, ACTest_joker, ::testing::Values(
        test_type_joker(L"abcdefabcd", L"abc*", '*', string_array(new vector<string>{"1", "7"})),
        test_type_joker(L"абвгдеабвг", L"бв*", '*', string_array(new vector<string>{"2", "8"})),
        test_type_joker(L"112312333112311", L"*3**", '*', string_array(new vector<string>{"3", "6", "12"})),
        test_type_joker(L"abacdabae", L"aba*", '*', string_array(new vector<string>{"1", "6"}))
)
);

TEST_P(ACTest_joker, test_eq) {
    wcout << COUT_GTEST_MGT << "Checking text \"" << text << "\" and patterns \"";
    for(const auto pattern : *patterns) {
        wcout << pattern << " ";
    }
    cout << "\"" << ANSI_TXT_DFT << endl;
    auto result = aho_corasick->find(text);
    EXPECT_EQ(result->size(), exp_result->size());
    auto iter_1 = result->begin();
    auto iter_2 = exp_result->begin();
    for(; iter_1 != result->end() && iter_2 != exp_result->end(); iter_1++, iter_2++) {
        EXPECT_EQ((*iter_1).substr(0, (*iter_1).find(' ')), *iter_2);
    }
}