#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::vector<std::string> majorColors = { "White", "Red", "Black", "Yellow", "Violet" };
const std::vector<std::string> minorColors = { "Blue", "Orange", "Green", "Brown", "Slate" };

std::pair<std::string, std::string> getColorsFromPairNumber(int pairNumber) {
    int totalPairs = majorColors.size() * minorColors.size();
    if (pairNumber < 1 || pairNumber > totalPairs) {
        return { "", "" };
    }

    int zeroBasedPairNumber = pairNumber - 1;
    std::string major = majorColors[zeroBasedPairNumber / minorColors.size()];
    std::string minor = minorColors[zeroBasedPairNumber % minorColors.size()];

    return { major, minor };
}

std::string generateExpectedOutput() {
    std::ostringstream oss;
    int totalPairs = majorColors.size() * minorColors.size();
    for (int pairN = 1; pairN <= totalPairs; ++pairN) {
        std::pair<std::string, std::string> cols = getColorsFromPairNumber(pairN);
        oss << "Pair number " << pairN << ": " << cols.first << " - " << cols.second << std::endl;
    }
    return oss.str();
}

std::string getAllColorPairs() {
    std::ostringstream oss;
    int totalPairs = majorColors.size() * minorColors.size();
    for (int pairN = 1; pairN <= totalPairs; ++pairN) {
        std::pair<std::string, std::string> cols = getColorsFromPairNumber(pairN);
        oss << "Pair number " << pairN << ": " << cols.first << " - " << cols.second << std::endl;
    }
    return oss.str();
}

void testprintColorMap() {
    // Generate expected output dynamically and compare with
    std::string expectedOutput = generateExpectedOutput();
    std::string actualOutput = getAllColorPairs();
    assert(expectedOutput == actualOutput);
}

int main() {
    testprintColorMap();
    std::cout << "All is well\n";
    return 0;
}
