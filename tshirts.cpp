#include <assert.h>
#include <iostream>

char size(int cms) {
    char sizeName = '\0';
    if (cms < 38) {
        sizeName = 'S';
    } else if (cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if (cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}
void sizetest(int cms, char sizename) {
    assert(size(cms) == sizename);
}

int main() {
    sizetest(37, 'S');
    sizetest(40, 'M');
    sizetest(43, 'L');
    sizetest(38, 'S');
    std::cout << "All is well (maybe!)\n";
    return 0;
}
