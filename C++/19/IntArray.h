#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray
{
private:
    int m_length;
    int *m_pointer;
public:
    IntArray(int len);
    IntArray(const IntArray& obj);
    int length();
    bool get(int index, int& value);
    bool set(int index, int value);
    void free();
};

#endif