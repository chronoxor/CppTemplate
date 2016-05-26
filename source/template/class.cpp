/*!
    \file class.cpp
    \brief Template class implementation
    \author Ivan Shynkarenka
    \date 26.05.2016
    \copyright MIT License
*/

#include "class.h"

#include <cstdlib>

namespace CppTemplate {

int Template::Method(int parameter) const noexcept
{
    return _field + rand() % parameter;
}

} // namespace CppTemplate
