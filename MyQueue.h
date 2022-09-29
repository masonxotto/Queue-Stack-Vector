#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#include <iostream>
#include <algorithm>

#include "MyVector.h"

template <typename DataType>
class MyQueue : private MyVector<DataType>
{
  private:
    size_t dataStart, dataEnd;

    // changes the size of the array to newSize
    void resize(size_t newSize)
    {
        // code begins
        MyVector<DataType>::resize(newSize);
        // code ends
    }

    // requests for newCapacity amount of space
    void reserve(size_t newCapacity)
    {
        // code begins
        MyVector<DataType>::reserve(newCapacity);
        // code ends
    }

  public:

    // default constructor
    explicit MyQueue(size_t initSize = 0) : MyVector<DataType>{initSize}
    {
        // code begins
        dataStart = 0;
        dataEnd = 0;
        // code ends
    }

    // copy constructor
    MyQueue(const MyQueue & rhs) :
        dataStart{rhs.dataStart},
        dataEnd{rhs.dataEnd}
    {
        // code begins
        for (int i = dataStart; i < rhs.size(); i++) {
          enqueue(rhs.front());
          rhs.dequeue();
        }
        // code ends
    }

    // move constructor
    MyQueue(MyQueue && rhs) :
        MyVector<DataType>(rhs),
        dataStart{rhs.dataStart},
        dataEnd{rhs.dataEnd}
    {
        // code begins
        rhs.dataStart = 0;
        rhs.dataEnd = 0;
        // code ends
    }

    // destructor
    ~MyQueue()
    {
        // code begins
        while (!empty()) {
          dequeue();
        }
        // code ends
    }

    // copy assignment
    MyQueue & operator= (const MyQueue & rhs)
    {
        // code begins
        MyQueue copy = rhs;
        std::swap(*this, rhs);
        return *this;
        // code ends
    }

    // move assignment
    MyQueue & operator= (MyQueue && rhs)
    {
        // code begins
        std::swap(MyVector<DataType>::theSize, rhs.theSize);
        std::swap(MyVector<DataType>::theCapacity, rhs.theCapacity);
        std::swap(MyVector<DataType>::data, rhs.data);
        std::swap(dataStart, rhs.dataStart);
        std::swap(dataEnd, rhs.dataEnd);
        // code ends
    }

    // insert x into the queue
    void enqueue(const DataType & x)
    {
        // code begins
        MyVector<DataType>::push_back(x);
        dataEnd++;
        // code ends
    }

    // insert x into the queue
    void enqueue(DataType && x)
    {
        // code begins
        MyVector<DataType>::push_back(std::move(x));
        dataEnd++;
        // code ends
    }

    // remove the first element from the queue
    void dequeue(void)
    {
        // code begins

        if (!empty()) {
          MyVector<DataType>::pop_front();
          //dataStart++;
        }
        // code ends
    }

    // access the first element of the queue
    const DataType & front(void) const
    {
        // code begins
        return MyVector<DataType>::at(dataStart);
        // code ends
    }

    // check if the queue is empty; return TRUE is empty; FALSE otherwise
    bool empty(void) const
    {
        // code begins
        return MyVector<DataType>::empty();
        // code ends
    }

    // access the size of the queue
    size_t size() const
    {
        // code begins
        return (MyVector<DataType>::size());
        // code ends
    }

    // access the capacity of the queue
    size_t capacity(void) const
    {
        // code begins
        return (MyVector<DataType>::capacity());
        // code ends
    }

};


#endif // __MYQUEUE_H__
