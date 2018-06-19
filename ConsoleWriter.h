#pragma once

#include "IWriter.h"

class ConsoleWriter: public IWriter
{
public:

    void write(std::string& str) override;

};