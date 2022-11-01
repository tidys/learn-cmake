#include <iostream>
#include "lib.h"
#include "test.h"
int main(int, char **)
{
    auto lib = new Lib();
    lib->test();
#ifdef TEST
    if (TEST == 1)
    {
        std::cout << "define TEST = 1";
    }
    else
    {

        std::cout << "define TEST";
    }
#else
    std::cout << "no define TEST";
#endif
}
