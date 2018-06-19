#include <iostream>
#include <string>

#include "ConsoleWriter.h"

void ConsoleWriter::write(std::string& str)
{
    std::cout << str << std::endl;
}
