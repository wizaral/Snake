#include <iostream>

void tests();

int main() {
#if defined(DEBUG)
    tests();
#else
    std::cout << "Hello world!" << std::endl;
#endif
}
