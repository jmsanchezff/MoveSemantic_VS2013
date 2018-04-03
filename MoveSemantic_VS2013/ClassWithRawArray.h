#pragma once

#include <iostream>

class ClassWithRawArray
{
    int* m_Ints;
    int m_NumOfInts;

public:
    ClassWithRawArray(int numberOfInts)
    {
        std::cout << "... Called ClassWithRawArray CONSTRUCTOR" << std::endl;
        m_Ints = new int[numberOfInts];
        std::fill_n(m_Ints, numberOfInts, 0);
        m_NumOfInts = numberOfInts;
    }

    ClassWithRawArray(const ClassWithRawArray& other) : m_Ints(nullptr), m_NumOfInts(0)
    {
        std::cout << "... Called ClassWithRawArray COPY CONSTRUCTOR" << std::endl;
        copyInts(other);
    }


    ClassWithRawArray(ClassWithRawArray&& other) : m_Ints(nullptr), m_NumOfInts(0)
    {
        std::cout << "... Called ClassWithRawArray MOVE CONSTRUCTOR" << std::endl;
        moveInts(other);
    }


    ~ClassWithRawArray()
    {
        std::cout << "... Called ClassWithRawArray DESTRUCTOR" << std::endl;
        deleteInts();
    }

    ClassWithRawArray& operator=(const ClassWithRawArray& other)
    {
        std::cout << "... Called ClassWithRawArray COPY ASSIGNEMENT" << std::endl;
        if (this == &other)
            return *this;

        copyInts(other);

        return *this;
    }

    ClassWithRawArray& operator=(ClassWithRawArray&& other)
    {
        std::cout << "... Called ClassWithRawArray MOVE ASSIGNEMENT" << std::endl;
        if (this == &other)
            return *this;

        moveInts(other);

        return *this;
    }

    void SetValue(int index, int value)
    {
        checkIndex(index);
        m_Ints[index] = value;
    }

    void PrintValues() const
    {
        for (int index = 0; index < m_NumOfInts; index++)
        {
            std::cout << m_Ints[index] << " ";
        }
        std::cout << std::endl;
    }

private:
    void checkIndex(int index) const
    {
        if (index < 0 || index >= m_NumOfInts)
            throw std::invalid_argument("Invalid index");
    }

    void deleteInts()
    {
        if (!m_Ints)
            std::cout << "[NOTHING DELETED]" << std::endl;
        else
            std::cout << "[DELETED " << m_NumOfInts << " ELEMENTS]" << std::endl;

        delete[] m_Ints;
        m_NumOfInts = 0;
    }

    void moveInts(ClassWithRawArray& other)
    {
        deleteInts();

        m_Ints = other.m_Ints;
        m_NumOfInts = other.m_NumOfInts;
        other.m_Ints = nullptr;
        other.m_NumOfInts = 0;

        std::cout << "[TRANSFERRED OWNERSHIP OF " << m_NumOfInts << " INTEGERS]" << std::endl;
    }

    void copyInts(const ClassWithRawArray& other)
    {
        deleteInts();

        m_NumOfInts = other.m_NumOfInts;
        m_Ints = new int[m_NumOfInts];
        std::copy(other.m_Ints, other.m_Ints + m_NumOfInts, m_Ints);

        std::cout << "[COPIED " << m_NumOfInts << " INTEGERS]" << std::endl;
    }

};

