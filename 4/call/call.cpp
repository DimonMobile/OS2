#include <iostream>
#include <Windows.h>

typedef int (*Sum)(int, int);
typedef int (*Mult)(int, int);
typedef double (*Divide)(double, double);

int main()
{
    HINSTANCE hDll = LoadLibrary(L"dll.dll");
    if (!hDll)
    {
        std::cerr << "Library load error" << std::endl;
        return EXIT_FAILURE;
    }
    Sum sum = (Sum)GetProcAddress(hDll, "sum");
    std::cout << sum(10, 3) << std::endl;
    
    Mult mult = (Mult)GetProcAddress(hDll, "mult");
    std::cout << mult(10, 3) << std::endl;

    Divide divide = (Divide)GetProcAddress(hDll, "divide");
    std::cout << divide(10, 3) << std::endl;

    FreeLibrary(hDll);
}
