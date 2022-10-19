#include <iostream>
#include "lib.h"
#include "test.h"
int main(int, char**) {
    auto lib=new Lib();
    lib->test();
    std::cout << "Hello, world!\n"<< test::getN();
}
