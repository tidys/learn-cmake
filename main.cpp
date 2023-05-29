#include <iostream>
#include "lib.h"
#include "dll.h"
#include "test.h"
#include <time.h>
#include <Windows.h>
using namespace std;
void getRunTime()
{
    clock_t t1 = clock();
    int len = 700 * 700;
    unsigned char *arr = new unsigned char[len];
    memset(arr, 100, len);
    // for (int i = 0; i < len; i++)
    // {
    //     arr[i] = 100;
    // }
    clock_t diff = clock() - t1; // ms
    std::cout << "\ntime: " << diff << "ms\n";
    delete[] arr;
}
int main(int, char **)
{
    // auto lib = new Lib();
    // lib->test();
    auto dll = new Dll();
    dll->test();
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
    getRunTime();
    system("pause");
}
