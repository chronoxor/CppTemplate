/*!
    \file template_class.cpp
    \brief Template class example
    \author Ivan Shynkarenka
    \date 26.05.2016
    \copyright MIT License
*/

#include "template/class.h"

#include <iostream>

int main(int argc, char** argv)
{
    CppTemplate::Template template(10);
    std::cout << "template.field() = " << template.field() << std::endl;
    std::cout << "template.Method(100) = " << template.Method(100) << std::endl;
    std::cout << "CppTemplate::Template::StaticMethod(1000) = " << CppTemplate::Template::StaticMethod(1000) << std::endl;
    return 0;
}
