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
const std::size_t numberOfMapping = 3;
struct ArabicToRomanMapping {
    unsigned  int arabicNumber;
    std::string romanNumberal;
};
using ArabicToRomanMappings = std::array<ArabicToRomanMapping, numberOfMapping>;
const ArabicToRomanMappings arabicToRomanMappings =
        {{
                 {100, "C"},
                 {10, "X"},
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

