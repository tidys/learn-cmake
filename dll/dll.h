#include <iostream>
#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __attribute__((visibility("default")))
#endif
class DLL_EXPORT Dll
{
public:
    void test();
};