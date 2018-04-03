#pragma once
#include <vector>
#include <iostream>

class ClassWithStdVector
{
public:
    ClassWithStdVector(int numOfInts)
    {
        m_Ints.resize(numOfInts, 0);
    }

    ClassWithStdVector(const ClassWithStdVector& other) = default;
    ~ClassWithStdVector() = default;
    ClassWithStdVector& operator=(const ClassWithStdVector& other) = default;


    // Unfortunately vs2013 do not implement default for move assignement and move constructor,
    // so this must be implemented by hand
    // ClassWithStdVector(ClassWithStdVector&& other) = default;
    // ClassWithStdVector& operator=(ClassWithStdVector&& other) = default;

    ClassWithStdVector(ClassWithStdVector&& other) : m_Ints(std::move(other.m_Ints))
    {}

    ClassWithStdVector& operator=(ClassWithStdVector&& other)
    {
        m_Ints = std::move(other.m_Ints);
        return *this;
    };


    void SetValue(int index, int value)
    {
        m_Ints[index] = value;
    }

    void PrintValues() const
    {
        for (auto integer : m_Ints)
        {
            std::cout << integer << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> m_Ints;
};
