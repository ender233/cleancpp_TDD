#include "roman_number.hpp"
#include <array>
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
const std::size_t numberOfMapping = 13;
struct ArabicToRomanMapping {
    unsigned  int arabicNumber;
    std::string romanNumberal;
};
using ArabicToRomanMappings = std::array<ArabicToRomanMapping, numberOfMapping>;
const ArabicToRomanMappings arabicToRomanMappings =
        {{
                 {1000, "M"},
                 {900, "CM"},
                 {500, "D"},
                 {400, "CD"},
                 {100, "C"},
                 {90, "XC"},
                 {50, "L"},
                 {40, "XL"},
                 {10, "X"},
                 {9, "IX"},
                 {5, "V"},
                 {4, "IV"},
                 {1, "I"}
         }};

std::string convertArabicNumberToRomanNumeral(unsigned int arabicNumber) {
    std::string romanNumeral;
    for(auto &mapping : arabicToRomanMappings) {
        while(arabicNumber >= mapping.arabicNumber) {
            romanNumeral += mapping.romanNumberal;
            arabicNumber -= mapping.arabicNumber;
        }
    }
    return romanNumeral;
}

