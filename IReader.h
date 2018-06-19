#pragma once

#include <string>

class IReader
{
public:

    virtual void read(std::string& str) = 0;

};