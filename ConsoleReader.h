#pragma once

#include "IReader.h"

class ConsoleReader: public IReader
{
public:

    void read(std::string& str) override;

};