#include <gtest/gtest.h>
#include "roman_number.hpp"
using namespace std;

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

