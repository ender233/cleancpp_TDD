#include <iostream>
#include <gtest/gtest.h>
using namespace std;

// test for gtest
class Test : public ::testing::Test {
protected:
    Test() = default;
    virtual ~Test() = default;
    virtual  void SetUp() {}
    virtual  void TearDown() {}
};

TEST_F(Test, test2) {
    EXPECT_EQ(1, 1);
}

/* 规则:
 * 1 -> I
 * 5 -> V
 * 10 -> X
 * 50 -> L
 * 100 -> C
 * 500 -> D
 * 1000 -> M
 *
 */
string convertArabicNumberToRomanNumeral(const unsigned int arabicNumber) {
    return "I";
}


TEST(ArabicToRomanNumeralsConverterTestCase, 1_isConvertedTo_I) {
    EXPECT_EQ("I", convertArabicNumberToRomanNumeral(1));
}


