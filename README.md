# MoveSemantic_VS2013
It contains a Visual Studio 2013 solution with ilustrating examples about C++ copy and move semantics.

## Motivation
While working in a project, I tried to work effectively with move and copy semantics included in C++11. In that project we were restricted to use Visual Studio 2013 C++ compiler, which partially implemented the C++11 standard. With this project I wanted to experiment and illustrate myself how to effectively work in those conditions.

One of the restrictions that I discovered with this exercise is that by Visual Studio 2013 C++ compiler did not implement the default move constructor and assignment operator (=) so, if you do not implement it, is quite possible that you has some cumbersome behaviours.

## What you will find here
This is a simple solution with a single C++ project (MoveSemantic_VS2013).

### Classes managing some resource:
That project defines two classes that manage a variable memory resource, and implements move and copy constructors/assignment operators:

- **ClassWithRawArray:** the resource managed in this class is a classic raw array, maging memory allocation and deallocation. This class explicitly must fullfill the "rule of five", and thus implements destructor, copy and move constructors, copy and move assigmnent operators.

- **ClassWithStdVector:** in this case it has a std::vector member in wich memory management is delagated. In this case, as the std::vector class already fullfils the requirements for a proper move and copy semantics, ideally we can see that we can delegate on default implemetations of copy and move constructors and assigment operators. As VS2013 do not implements C++11 standard completely, we can see that we need to explicitly implement move constructor and assignment operator.

### Use cases using that classes:
In Main.cpp you can find the main() entry point of the program. There are 4 blocks of examples using that two clases, in which you can trace moving and creation of resources



