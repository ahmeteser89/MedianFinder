#pragma once

#include <string>

class IWriter
{
public:

    virtual void write(std::string& str) = 0;

};