#include <iostream>
#include <cstring>
#include "fun.h"

#define LOG(x) std::cout << x << std::endl;

int main() {
    int a;
//    std::cin >> a ;
//    std::cout << "Hello World " <<  a << std::endl;

    // ------------------- Header file ------------------------
    fun();

    // ------------------- Pointers ------------------------
    // On stack
    int var = 100;
    int* ptr = &var;
    *ptr = 10;
    LOG(var);

    // In Heap
    char* buffer = new char[8];
    memset(buffer, 0, 8);
    buffer[4] = 'b';

    char** double_ptr = &buffer;

    delete[] buffer;
    return 0;
}
