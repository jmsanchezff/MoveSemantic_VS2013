#pragma once

#include <iostream>

inline void printHeader(const char* header)
{
    std::cout << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "---------- " << header << " ---------" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
}

inline void printSubHeader(const char* header)
{
    std::cout << std::endl << "**********************" << std::endl;
    std::cout << header << std::endl;
    std::cout << "**********************" << std::endl;
}

template<typename T>
void printValues(const char* objectName, const T& object)
{
    std::cout << "Values of " << objectName << ": ";
    object.PrintValues();
}