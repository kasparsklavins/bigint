#ifndef DODECAHEDRON_BIGINT_H_
#define DODECAHEDRON_BIGINT_H_

#include <vector>
#include <iostream>
#include <map>

namespace Dodecahedron
{
class Bigint
{
private:
    std::vector<int> number;
    bool positive;
    int base;
    unsigned int skip;

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
    Bigint &operator*=(int const &);

    //Division
    bool is_even();
    private:
    std::vector<Bigint> divide(Bigint q);   // returns quotient(index[0]) and remainder(index[1]).
    public:
    std::vector<Bigint> operator/(Bigint q); // interface for divide() function.
    //Compare
    bool operator<(const Bigint &) const;
    bool operator>(const Bigint &) const;
    bool operator<=(const Bigint &) const;
    bool operator>=(const Bigint &) const;
    bool operator==(const Bigint &) const;

    //Allocation
    Bigint operator=(const long long &);

    //Access
    int operator[](int const &);

    //Input&Output
    friend std::istream &operator>>(std::istream &, Bigint &);
    friend std::ostream &operator<<(std::ostream &, Bigint);

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
    Bigint sub_number(Bigint &p, Bigint &q); // used in the division function
};

Bigint abs(Bigint);
std::string to_string(Bigint);
Bigint factorial(int);
}

#endif
