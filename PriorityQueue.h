#pragma once

#include "DynamicContainer.h"

using std::swap;

template < typename T>
class Less
{
public:
    bool operator()(const T &a, const T &b) const { return a < b; }
};

template <typename T, typename Compare = Less<T>>
class PriorityQueue
{
public:
    PriorityQueue() = default;
    PriorityQueue(const PriorityQueue& pq);
    PriorityQueue(PriorityQueue && pq);
    ~PriorityQueue();

    PriorityQueue& operator=(const PriorityQueue &pq);
    PriorityQueue& operator=(PriorityQueue &&pq);

    bool empty() const;
    size_t size() const;
    const T& top() const;
    void push(const T& val);
    void pop();

private:

    size_t getParentIndex(size_t childIndex);
    size_t getLeftChildIndex(size_t parentIndex);
    size_t getRightChildIndex(size_t parentIndex);

    void fixUp();
    void fixDown();

    DynamicContainer<T> mData;
};

template<typename T, typename Compare>
PriorityQueue<T, Compare>::PriorityQueue(const PriorityQueue& pq):mData(pq.mData)
{}

template<typename T, typename Compare>
PriorityQueue<T, Compare>::PriorityQueue(PriorityQueue&& pq):mData(std::move(pq.mData))
{}

template<typename T, typename Compare>
PriorityQueue<T, Compare>::~PriorityQueue()
{
    mData.clear();
}

template<typename T, typename Compare>
PriorityQueue<T, Compare>& PriorityQueue<T, Compare>::operator=(const PriorityQueue& pq)
{
    if (this == &pq)
        return *this;

    mData = pq.mData;

    return *this;
}

template<typename T, typename Compare>
PriorityQueue<T, Compare>& PriorityQueue<T, Compare>::operator=(PriorityQueue&& pq)
{
    if (this == &pq)
        return *this;

    mData = std::move(pq.mData);

    return *this;
}

template <typename T, typename Compare>
bool PriorityQueue<T, Compare>::empty() const
{
    return mData.size() == 0;
}

template <typename T, typename Compare>
size_t PriorityQueue<T, Compare>::size() const
{
    return mData.size();
}

template <typename T, typename Compare>
const T& PriorityQueue<T, Compare>::top() const
{
    return mData.front();
}

template <typename T, typename Compare>
void PriorityQueue<T, Compare>::push(const T& val)
{
    mData.push_back(val);

    fixUp();
}

template <class T, typename Compare>
void PriorityQueue<T, Compare>::pop()
{
    swap(mData[0], mData[size()-1]);

    mData.pop_back();

    fixDown();
}

template <class T, typename Compare>
size_t PriorityQueue<T, Compare> ::getParentIndex(size_t childIndex)
{
    return childIndex <= 0 ? 0 : (childIndex - 1) / 2;
}

template <class T, typename Compare>
size_t PriorityQueue<T, Compare> ::getLeftChildIndex(size_t parentIndex)
{
    return 2 * parentIndex + 1;
}

template <class T, typename Compare>
size_t PriorityQueue<T, Compare> ::getRightChildIndex(size_t parentIndex)
{
    return 2 * parentIndex + 2;
}

template <class T, typename Compare>
void PriorityQueue<T, Compare>::fixUp()
{
    Compare compare;
    size_t childIndex = mData.size() - 1;
    size_t parentIndex = getParentIndex(childIndex);

    while (childIndex >= 0 && parentIndex >= 0 && compare(mData[parentIndex], mData[childIndex]))
    {
        swap(mData[childIndex], mData[parentIndex]);
        childIndex = parentIndex;
        parentIndex = getParentIndex(childIndex);
    }
}

template <class T, typename Compare>
void PriorityQueue<T, Compare>::fixDown()
{
    Compare compare;
    size_t parentIndex = 0;

    while (getLeftChildIndex(parentIndex)  < size() || getRightChildIndex(parentIndex) < size())
    {
        size_t leftChildIndex = getLeftChildIndex(parentIndex);
        size_t rightChildIndex = getRightChildIndex(parentIndex);
        size_t largestIndex = parentIndex;

        if (leftChildIndex < size() && compare(mData[largestIndex], mData[leftChildIndex]))
        {
            largestIndex = leftChildIndex;
        }

        if (rightChildIndex < size() && compare(mData[largestIndex], mData[rightChildIndex]))
        {
            largestIndex = rightChildIndex;
        }

        if (largestIndex != parentIndex)
        {
            swap(mData[largestIndex], mData[parentIndex]);
            parentIndex = largestIndex;
        }
        else
        {
            break;
        }
    }
}