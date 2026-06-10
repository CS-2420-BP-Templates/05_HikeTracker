//
// Created by kmurphy on 6/10/2026.
//

#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T, int MAX_SIZE>
class Collection
{
private:
    T items[MAX_SIZE];
    int size;

public:
    // Constructor
    Collection();

    // Add item to end
    void add(const T& item);

    // Remove at index
    void removeAt(int index);

    // Access operator
    T& operator[](int index);

    // Get size
    int getSize() const;

    // Output operator
    template <typename U, int S>
    friend ostream& operator<<(ostream& out,
                               const Collection<U, S>& collection);
};

// ---------------- IMPLEMENTATION ----------------

template <typename T, int MAX_SIZE>
Collection<T, MAX_SIZE>::Collection()
{
    size = 0;
}

template <typename T, int MAX_SIZE>
void Collection<T, MAX_SIZE>::add(const T& item)
{
    if (size >= MAX_SIZE)
    {
        throw overflow_error("Collection is full");
    }

    items[size] = item;
    size++;
}

template <typename T, int MAX_SIZE>
void Collection<T, MAX_SIZE>::removeAt(int index)
{
    if (size == 0)
    {
        throw underflow_error("Collection is empty");
    }

    if (index < 0 || index >= size)
    {
        throw out_of_range("Invalid index");
    }

    for (int i = index; i < size - 1; i++)
    {
        items[i] = items[i + 1];
    }

    size--;
}

template <typename T, int MAX_SIZE>
T& Collection<T, MAX_SIZE>::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("Invalid index");
    }

    return items[index];
}

template <typename T, int MAX_SIZE>
int Collection<T, MAX_SIZE>::getSize() const
{
    return size;
}

// Output operator
template <typename T, int MAX_SIZE>
ostream& operator<<(ostream& out,
                    const Collection<T, MAX_SIZE>& collection)
{
    for (int i = 0; i < collection.size; i++)
    {
        out << collection.items[i] << endl;
    }
    return out;
}

#endif