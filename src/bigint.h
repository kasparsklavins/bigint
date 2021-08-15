#ifndef DODECAHEDRON_BIGINT_H_
#define DODECAHEDRON_BIGINT_H_

#include <vector>
#include <cstddef>
#include <iostream>
#include <map>

namespace Dodecahedron
{
class Bigint
{
private:
    std::vector<int> number;
    // don't modify this directly through const. use flip_positive
    mutable bool positive;
    int base;
    unsigned int skip;
    static const int default_base=1000000000;

public:
    //Constructors
    Bigint();
    Bigint(long long);
    Bigint(std::string);
    Bigint(const Bigint& b);

    //Adding
    Bigint operator+(Bigint const &) const;
    Bigint &operator+=(Bigint const &);
    Bigint operator+(long long const &) const;
    Bigint &operator+=(long long);

    //Subtraction
    Bigint operator-(Bigint const &) const;
    Bigint &operator-=(Bigint const &);

    //Multiplication
    Bigint operator*(Bigint const &);
    Bigint &operator*=(Bigint const &);
    Bigint operator*(long long const &);
    Bigint &operator*=(long long const &);

    //Modulo
    Bigint operator%(Bigint const &);
    int operator%(int);

    //Division
	Bigint operator/(Bigint const &);

    //Compare
    bool operator<(const Bigint &) const;
    bool operator>(const Bigint &) const;
    bool operator<=(const Bigint &) const;
    bool operator>=(const Bigint &) const;
    bool operator==(const Bigint &) const;
    bool operator!=(const Bigint &) const;

    //Allocation
    Bigint operator=(const long long &);

    //Access
    int operator[](int const &);

    //Input&Output
    friend std::istream &operator>>(std::istream &, Bigint &);
    friend std::ostream &operator<<(std::ostream &, Bigint const &);

    //Helpers
    void clear();
    Bigint &abs();

    //Power
    Bigint &pow(int const &);

    //Trivia
    int digits() const;
    int trailing_zeros() const;
private:
    int segment_length(int) const;
    Bigint pow(int const &, std::map<int, Bigint> &);
    int compare(Bigint const &) const; //0 a == b, -1 a < b, 1 a > b
    void flip_positive() const;
};

Bigint abs(Bigint);
std::string to_string(Bigint const &);
Bigint factorial(int);
}

#endif
