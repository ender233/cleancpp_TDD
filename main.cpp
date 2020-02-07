#include <iostream>
#include <gtest/gtest.h>
using namespace std;

/* 规则:
 * 1 -> I
 * 5 -> V
 * 10 -> X
 * 50 -> L
 * 100 -> C
 * 500 -> D
 * 1000 -> M
 */
string convertArabicNumberToRomanNumeral(unsigned int arabicNumber) {
    string romanNumeral;
    while(arabicNumber >= 100) {
        romanNumeral += "C";
        arabicNumber -= 100;
    }
    while(arabicNumber >= 10) {
        romanNumeral += "X";
        arabicNumber -= 10;
    }
    while(arabicNumber-- > 0) {
        romanNumeral += "I";
    }
    return romanNumeral;
}

// 支持assertThat(3).isConvertedToRomanNumeral("XXXII")语法
class RomanNumberalAssert {
public:
    RomanNumberalAssert() = delete;
    RomanNumberalAssert(const unsigned int number) : number_(number) {}
    void isConvertedToRomanNumeral(const std::string &expectedRomanNumeral) const {
        EXPECT_EQ(expectedRomanNumeral, convertArabicNumberToRomanNumeral(number_));
    }

private:
    const unsigned int number_;
};
// RomanNumberalAssert help function
RomanNumberalAssert assertThat(const unsigned int arabicNumber) {
    return RomanNumberalAssert(arabicNumber);
}

TEST(ArabicToRomanNumeralsConverterTestCase, conversionOfArabicNumbersToRomanNumerls_Works) {
    assertThat(1).isConvertedToRomanNumeral("I");
    assertThat(2).isConvertedToRomanNumeral("II");
    assertThat(3).isConvertedToRomanNumeral("III");
    assertThat(10).isConvertedToRomanNumeral("X");
    assertThat(20).isConvertedToRomanNumeral("XX");
    assertThat(30).isConvertedToRomanNumeral("XXX");
    assertThat(33).isConvertedToRomanNumeral("XXXIII");
    assertThat(100).isConvertedToRomanNumeral("C");
    assertThat(200).isConvertedToRomanNumeral("CC");
    assertThat(300).isConvertedToRomanNumeral("CCC");
}

