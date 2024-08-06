#include <assert.h>
#include <iostream>
#include <string>
#include <sstream>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

std::string printColorMap() {
    std::stringstream ss;
    std::cout << "printed output : "<< "\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ss << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return ss.str();
}

void testprintColorMap() {
    // Generate expected output dynamically and compare with
    std::string printed_output = printColorMap();
    std::stringstream expectedOutput;
    int p_Num = 1;
    std::cout << "expected output : "<< "\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << p_Num << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
            expectedOutput << p_Num++ << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
        }
    }
    assert(printed_output == expectedOutput.str());
}

int main() {
    testprintColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
