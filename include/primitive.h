#include <include/value.h>

template <class T>
class Primitive : public Value
{
  private:
    T value;

  public:
    Primitive(T value);

    T getValue();

    friend bool operator==(const Primitive<T> &, const Primitive<T> &);
    friend bool operator!=(const Primitive<T> &, const Primitive<T> &);
    friend bool operator>(const Primitive<T> &, const Primitive<T> &);
    friend bool operator>=(const Primitive<T> &, const Primitive<T> &);
    friend bool operator<(const Primitive<T> &, const Primitive<T> &);
    friend bool operator<=(const Primitive<T> &, const Primitive<T> &);

    Primitive<T> operator+(const Primitive<T> &) const;
    Primitive<T> operator-(const Primitive<T> &) const;
    Primitive<T> operator*(const Primitive<T> &)const;
    Primitive<T> operator/(const Primitive<T> &) const;
    Primitive<T> operator-() const;
    bool const operator!() const;
}