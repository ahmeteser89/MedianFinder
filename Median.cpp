#include "Median.h"

void Median::insert(const int& val)
{
    if (mMinHeap.empty())
    {
        mMinHeap.push(val);
    }
    else
    {
        int minTop = mMinHeap.top();

        if (val > minTop)
        {
            if (mMaxHeap.size() < mMinHeap.size())
            {
                mMinHeap.pop();

                mMinHeap.push(val);
                mMaxHeap.push(minTop);
            }
            else
            {
                mMinHeap.push(val);
            }
        }
        else
        {
            if (mMaxHeap.size() == mMinHeap.size())
            {
                int maxTop = mMaxHeap.top();

                mMaxHeap.pop();

                mMaxHeap.push(val);
                mMinHeap.push(maxTop);
            }
            else
            {
                mMaxHeap.push(val);
            }
        }
    }
}

double Median::median()
{
    if (mMinHeap.empty())
    {
        throw std::exception("Called median on empty list!");
    }

    int size = mMinHeap.size() + mMaxHeap.size();

    if (0 == size % 2)
    {
        return (mMinHeap.top() + mMaxHeap.top()) / 2.0;
    }

    return mMinHeap.top();
}
