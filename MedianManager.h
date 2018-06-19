#pragma once

#include "Median.h"

class IReader;
class IWriter;

class MedianManager
{
public:

    void start();

    void setReader(IReader* reader);
    void setWriter(IWriter* writer);

private:

    Median mMedian;
    IReader* mReader;
    IWriter* mWriter;
};