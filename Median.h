#pragma once

#include <iostream>
#include <functional>

#include "PriorityQueue.h"

class Median
{
public:

    void insert(const int& val);
    double median();

private:

    PriorityQueue<int, std::greater<int> > mMinHeap;
    PriorityQueue<int> mMaxHeap;
};