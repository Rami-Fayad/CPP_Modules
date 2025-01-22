#include <stddef.h>
#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *array, size_t length, void (*func)(T &))
{
    for (size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

#endif
