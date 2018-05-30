#ifndef PIAA_LAB6_ACTEST_H
#define PIAA_LAB6_ACTEST_H

#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "../src/ACAlgorithm.h"

#define ANSI_TXT_GRN "\033[0;32m"
#define ANSI_TXT_MGT "\033[0;35m"
#define ANSI_TXT_DFT "\033[0;0m"
#define GTEST_BOX "[          ] "
#define COUT_GTEST ANSI_TXT_GRN << GTEST_BOX
#define COUT_GTEST_MGT COUT_GTEST << ANSI_TXT_MGT

using namespace std;

typedef shared_ptr<vector<wstring>> wstring_array;
typedef shared_ptr<vector<string>> string_array;
typedef tuple<wstring, wstring_array, string_array> test_type_ac;
typedef tuple<wstring, wstring, wchar_t, string_array> test_type_joker;

class ACTest : public ::testing::Test {
public:
protected:
    virtual void SetUp() = 0;

    ACAlgorithm* aho_corasick;
    wstring text;
    wchar_t skip_symbol;
    wstring_array patterns;
    string_array exp_result;
};

class ACTest_joker : public ACTest, public testing::WithParamInterface<test_type_joker> {
protected:
    void SetUp() override;
};

class ACTest_ac : public ACTest, public testing::WithParamInterface<test_type_ac> {
protected:
    void SetUp() override;
};

#endif //PIAA_LAB6_ACTEST_H
