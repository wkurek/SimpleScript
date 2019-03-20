#include <include/primitive.h>

template <class T>
T Primitive<T>::getValue()
{
    return this->value;
}

template <class T>
bool operator==(const Primitive<T> &primitiveA, const Primitive<T> &primitiveB)
{
    return primitiveA.value == primitiveB.value;
}

template <class T>
bool operator!=(const Primitive<T> &primitiveA, const Primitive<T> &primitiveB)
{
    return primitiveA.value != primitiveB.value;
}

template <class T>
bool operator>(const Primitive<T> &primitiveA, const Primitive<T> &primitiveB)
{
    return primitiveA.value > primitiveB.value;
}

template <class T>
bool operator>=(const Primitive<T> &primitiveA, const Primitive<T> &primitiveB)
{
    return primitiveA.value >= primitiveB.value;
}

template <class T>
bool operator<(const Primitive<T> &primitiveA, const Primitive<T> &primitiveB)
{
    return primitiveA.value < primitiveB.value;
}

template <class T>
bool operator<=(const Primitive<T> &primitiveA, const Primitive<T> &primitiveB)
{
    return primitiveA.value <= primitiveB.value;
}

template <class T>
Primitive<T> Primitive<T>::operator+(const Primitive<T> &primitiveA) const
{
    return Primitive<T>(this->value + primitiveA.value);
}

template <class T>
Primitive<T> Primitive<T>::operator-(const Primitive<T> &primitiveA) const
{
    return Primitive<T>(this->value - primitiveA.value);
}

template <class T>
Primitive<T> Primitive<T>::operator*(const Primitive<T> &primitiveA) const
{
    return Primitive<T>(this->value * primitiveA.value);
}

template <class T>
Primitive<T> Primitive<T>::operator/(const Primitive<T> &primitiveA) const
{
    return Primitive<T>(this->value / primitiveA.value);
}

template <class T>
Primitive<T> Primitive<T>::operator-() const
{
    return Primitive<T>(-this->value);
}

template <class T>
bool const Primitive<T>::operator!() const
{
    return Primitive<T>(!value);
}