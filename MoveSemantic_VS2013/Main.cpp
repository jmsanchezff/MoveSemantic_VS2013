#include <iostream>

#include "ClassWithStdVector.h"
#include "ClassWithRawArray.h"
#include "PrintingFunctions.h"


template<typename T>
void movingByAssignment()
{
    {
        std::cout << std::endl << "(1) obj1 created in outer scope" << std::endl;
        T obj1(3);
        printValues("obj1", obj1);
        std::cin.get();
        {
            std::cout << std::endl << "(2) obj2 created in inner scope and set values" << std::endl;
            T obj2(5);
            obj2.SetValue(0, 1);
            obj2.SetValue(1, 2);
            obj2.SetValue(2, 3);
            obj2.SetValue(3, 4);
            obj2.SetValue(4, 5);
            printValues("obj1", obj1);
            printValues("obj2", obj2);
            std::cin.get();

            std::cout << std::endl << "(3) Moving by assignment: obj1 = std::move(obj2)" << std::endl;
            obj1 = std::move(obj2);
            printValues("obj1", obj1);
            printValues("obj2", obj2);
            std::cin.get();

            std::cout << std::endl << "(4) obj2 about to be out of the scope" << std::endl;
        }
        printValues("obj1", obj1);
        std::cin.get();
        std::cout << std::endl << "(5) obj1 about to be out of the scope" << std::endl;
    }
    std::cin.get();
}


template<typename T>
void movingByConstruction()
{
    {
        std::cout << std::endl << "(1) obj1 created in outer scope and values set" << std::endl;
        T obj1(3);
        obj1.SetValue(0, 1);
        obj1.SetValue(1, 2);
        obj1.SetValue(2, 3);

        printValues("obj1", obj1);

        std::cin.get();

        {
            std::cout << std::endl << "(2) Moving obj1 to obj2 by construction in an inner scope: obj2(std::move(obj1))" << std::endl;
            T obj2(std::move(obj1));
            printValues("obj1", obj1);
            printValues("obj2", obj2);
            std::cin.get();

            std::cout << std::endl << "(3) obj2 about to be out of the scope" << std::endl;
        }

        printValues("obj1", obj1);
        std::cin.get();
        std::cout << std::endl << "(4) obj1 about to be out of the scope" << std::endl;
    }
    std::cin.get();
}


template<typename T>
void copyingByConstrution()
{
    {
        std::cout << std::endl << "(1) obj1 created in outer scope and values set" << std::endl;
        T obj1(3);
        obj1.SetValue(0, 1);
        obj1.SetValue(1, 2);
        obj1.SetValue(2, 3);
        printValues("obj1", obj1);
        std::cin.get();

        {
            std::cout << "(2) Copy-construction of obj2 in an inner scope: obj2(obj1) " << std::endl;
            T obj2(obj1);
            printValues("obj1", obj1);
            printValues("obj2", obj2);
            std::cin.get();

            std::cout << "(3) obj2 values set to 5 " << std::endl;
            obj2.SetValue(0, 5);
            obj2.SetValue(1, 5);
            obj2.SetValue(2, 5);
            printValues("obj1", obj1);
            printValues("obj2", obj2);
            std::cin.get();

            std::cout << std::endl << "(4) obj2 about to be out of the scope" << std::endl;
        }

        printValues("obj1", obj1);
        std::cin.get();
        std::cout << std::endl << "(5) obj1 about to be out of the scope" << std::endl;
    }
    std::cin.get();
}


template<typename T>
void copyingByAssignment()
{
    {
        std::cout << std::endl << "(1) obj1 and obj2 created independently in same scope" << std::endl;
        T obj1(3);
        T obj2(5);
        obj2.SetValue(0, 1);
        obj2.SetValue(1, 2);
        obj2.SetValue(2, 3);
        obj2.SetValue(3, 4);
        obj2.SetValue(4, 5);
        printValues("obj1", obj1);
        printValues("obj2", obj2);
        std::cin.get();

        std::cout << "(2) Copy Assignement obj1 = obj2" << std::endl;
        obj1 = obj2;
        printValues("obj1", obj1);
        printValues("obj2", obj2);
        std::cin.get();

        std::cout << "(3) Change all values of obj1 to 5" << std::endl;
        obj1.SetValue(0, 5);
        obj1.SetValue(1, 5);
        obj1.SetValue(2, 5);
        obj1.SetValue(3, 5);
        obj1.SetValue(4, 5);
        printValues("obj1", obj1);
        printValues("obj2", obj2);
        std::cin.get();

        std::cout << std::endl << "(4) obj1 and obj2 about to be out of the scope" << std::endl;
    }
    std::cin.get();
}


void examplesMovingByConstruction()
{
    printHeader("MOVING BY CONSTRUCTION");

    printSubHeader("CLASS WITH RAW ARRAY");
    movingByConstruction<ClassWithRawArray>();

    printSubHeader("CLASS WITH STD VECTOR");
    movingByConstruction<ClassWithStdVector>();
}


void examplesMovingByAssignment()
{
    printHeader("MOVING BY ASSIGNEMENT");

    printSubHeader("CLASS WITH RAW ARRAY");
    movingByAssignment<ClassWithRawArray>();

    printSubHeader("CLASS WITH STD VECTOR");
    movingByAssignment<ClassWithStdVector>();
}


void examplesCopyingByConstruction()
{
    printHeader("COPYING BY CONSTRUCTION");

    printSubHeader("CLASS WITH RAW ARRAY");
    copyingByConstrution<ClassWithRawArray>();

    printSubHeader("CLASS WITH STD VECTOR");
    copyingByConstrution<ClassWithStdVector>();
}


void examplesCopyingByAssignment()
{
    printHeader("COPYING BY ASSIGNEMENT");

    printSubHeader("CLASS WITH RAW ARRAY");
    copyingByAssignment<ClassWithRawArray>();

    printSubHeader("CLASS WITH STD VECTOR");
    copyingByAssignment<ClassWithStdVector>();
}


int main(int argc, char* argv[])
{
    examplesMovingByConstruction();
    examplesCopyingByConstruction();
    examplesMovingByAssignment();
    examplesCopyingByAssignment();

    return 0;
}

