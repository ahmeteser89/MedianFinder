#pragma once

#include <stdexcept>

using std::swap;

template <class T>
class  DynamicContainer
{
public:

    DynamicContainer();
    DynamicContainer(size_t size);
    DynamicContainer(size_t size, const T & initial);
    DynamicContainer(const DynamicContainer<T>& dc);
    DynamicContainer(DynamicContainer<T> && dc);
    ~DynamicContainer();

    DynamicContainer<T> & operator=(const DynamicContainer<T> &dc);
    DynamicContainer<T> & operator=(DynamicContainer<T> &&dc);

    T & operator[](size_t index);
    const T &operator[](size_t index) const;

    size_t capacity() const;
    size_t size() const;
    bool empty() const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    void push_back(const T& value);
    void pop_back();

    void reserve(size_t capacity);
    void resize(size_t size);

    void clear();

private:

    size_t mSize;
    size_t mCapacity;
    T* mBuffer;
};


template<class T>
DynamicContainer<T>::DynamicContainer() :mSize(0), mCapacity(10), mBuffer(new T[mCapacity])
{}

template<class T>
DynamicContainer<T>::DynamicContainer(size_t size): mSize(size)
{
    if (mSize < 1)
    {
        throw std::exception("Size should be at least 1!");
    }

    if (mSize < 10)
    {
        mCapacity = 10;
    }
    else
    {
        mCapacity = static_cast<size_t>(mSize * 1.5);
    }

    mBuffer = new T[mCapacity];
}

template<class T>
DynamicContainer<T>::DynamicContainer(size_t size, const T& initial): mSize(size)
{
    if (mSize < 1)
    {
        throw std::exception("Size should be at least 1!");
    }

    if (mSize < 10)
    {
        mCapacity = 10;
    }
    else
    {
        mCapacity = static_cast<size_t>(mSize * 1.5);
    }

    mBuffer = new T[mCapacity];

    for (size_t i = 0; i < mSize; i++)
    {
        mBuffer[i] = initial;
    }
}

template<class T>
DynamicContainer<T>::DynamicContainer(const DynamicContainer<T> & dc): mSize(dc.mSize), mCapacity(dc.mCapacity), mBuffer(new T[mCapacity])
{
    for (size_t i = 0; i < mSize; i++)
    {
        mBuffer[i] = dc.mBuffer[i];
    }
}

template<typename T>
DynamicContainer<T>::DynamicContainer(DynamicContainer<T> &&dc) : mSize(dc.mSize), mCapacity(dc.mCapacity), mBuffer(dc.mBuffer)
{
    dc.mBuffer = nullptr;
    dc.mSize = 0;
    dc.mCapacity = 0;
}

template<class T>
DynamicContainer<T>::~DynamicContainer()
{
    delete[] mBuffer;
}

template<class T>
DynamicContainer<T>& DynamicContainer<T>::operator=(const DynamicContainer<T> & dc)
{
    if (this == &dc)
        return *this;

    size_t size = dc.mSize;
    size_t capacity = dc.mCapacity;
    T* buffer = new T[capacity];

    for (size_t i = 0; i < size; i++)
    {
        buffer[i] = dc.mBuffer[i];
    }

    swap(size, mSize);
    swap(capacity, mCapacity);
    swap(buffer, mBuffer);

    delete[] buffer;

    return *this;
}

template<typename T>
DynamicContainer<T> &DynamicContainer<T>::operator=(DynamicContainer<T> &&dc)
{
    if (this == &dc)
        return *this;

    delete[] mBuffer;

    mSize = dc.mSize;
    mCapacity = dc.mCapacity;
    mBuffer = dc.mBuffer;

    dc.mSize = 0;
    dc.mCapacity = 0;
    dc.mBuffer = nullptr;

    return *this;
}

template<class T>
T& DynamicContainer<T>::operator[](size_t index)
{
    if (index > mSize - 1 || index < 0)
    {
        throw std::out_of_range("Out of range!");
    }
    else
    {
        return mBuffer[index];
    }
}

template<typename T>
const T &DynamicContainer<T>::operator[](size_t index) const
{
    if (index > mSize - 1 || index < 0)
    {
        throw std::out_of_range("Out of range!");
    }
    else
    {
        return mBuffer[index];
    }
}

template<class T>
size_t DynamicContainer<T>::capacity() const
{
    return mCapacity;
}

template<class T>
size_t DynamicContainer<T>::size() const
{
    return mSize;
}

template <class T>
bool DynamicContainer<T>::empty() const 
{
    return mSize == 0;
}

template<class T>
T& DynamicContainer<T>::front()
{
    return mBuffer[0];
}

template<class T>
const T& DynamicContainer<T>::front() const
{
    return mBuffer[0];
}

template<class T>
T& DynamicContainer<T>::back()
{
    return mBuffer[mSize - 1];
}

template<class T>
const T& DynamicContainer<T>::back() const
{
    return mBuffer[mSize - 1];
}

template<class T>
void DynamicContainer<T>::push_back(const T & value)
{
    if (mSize >= mCapacity)
    {
        reserve(static_cast<size_t>(mSize*1.5));
    }

    mBuffer[mSize++] = value;
}

template<class T>
void DynamicContainer<T>::pop_back()
{
    if (mSize > 0)
    {
        mBuffer[mSize-1].~T();
        mSize--;
    }
}

template<class T>
void DynamicContainer<T>::reserve(size_t capacity)
{
    T* newBuffer = new T[capacity];

    for (size_t i = 0; i < mSize; i++)
    {
        newBuffer[i] = mBuffer[i];
        mBuffer[i].~T();
    }

    mCapacity = capacity;
    delete[] mBuffer;
    mBuffer = newBuffer;
}

template<class T>
void DynamicContainer<T>::resize(size_t size)
{
    reserve(static_cast<size_t>(size*1.5));
    mSize = size;
}

template <class T>
void DynamicContainer<T>::clear()
{
    mSize = 0;
    mCapacity = 0;
    delete[] mBuffer;
    mBuffer = nullptr;
}