#include <iostream>
#include "ACTest.h"

using namespace std;

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

INSTANTIATE_TEST_CASE_P(Default, ACTest_ac, ::testing::Values(
        test_type_ac("abcdefabc", string_array(new vector<string>{"abc", "de"})),
        test_type_ac("1123123331123", string_array(new vector<string>{"123", "33", "333", "11", "3331"})),
        test_type_ac("aaa", string_array(new vector<string>{"bbb"})),
        test_type_ac("ababab", string_array(new vector<string>{"abab"}))
));

TEST_P(ACTest_ac, test_eq) {
    cout << COUT_GTEST_MGT << "Checking text \"" << text << "\" and patterns \"";
    for(const auto pattern : *patterns) {
        cout << pattern << " ";
    }
    cout << "\"" << ANSI_TXT_DFT << endl;
    auto result = aho_corasick->find(text);
    auto exp_result = findAllOccurrences();
    EXPECT_EQ(result->size(), exp_result->size());
    auto iter_1 = result->begin();
    auto iter_2 = exp_result->begin();
    for(; iter_1 != result->end() && iter_2 != exp_result->end(); iter_1++, iter_2++) {
        EXPECT_EQ(*iter_1, *iter_2);
    }
}