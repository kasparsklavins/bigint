#ifndef BIGINT_H_
#define BIGINT_H_

#include <vector>
#include <iostream>
#include <map>

class bigint {
private:
	std::vector<int> number;
    bool positive;
    int base;
    unsigned int skip;

public:
	//Magic methods
	bigint();

	//Adding
	bigint operator+(bigint const &b);
	bigint& operator+=(bigint const &b);
	bigint operator+(long long const &b);
	bigint& operator+=(long long b);

	//Subtraction
	bigint operator-(bigint const &b);
	bigint& operator-=(bigint const &b);

	//Multiplication
	bigint operator*(bigint const &b);
	bigint& operator*=(bigint const &b);
	bigint operator*(long long const &b);
	bigint& operator*=(int const &b);

	//Mod
	bigint operator%(bigint const &b); //NOP, nav pabeigts.

	//Compare
	bool operator<(const bigint &a) const;
	bool operator==(const bigint &a) const;

	//Allocation
	bigint operator=(const long long &a);

	//Access
	int operator[](int const &b);

	//Input&Output
    friend std::istream &operator>>(std::istream &in, bigint &a);
    friend std::ostream &operator<<(std::ostream &out, bigint a);

    //Helpers
    void clear();
    std::string toString();
    bigint& abs();

	//Power
	bigint& pow(int const &power);
	bigint pow(int const &power, std::map<int, bigint> &lookup);

    //Trivia
	int digits();
	int trailingZeros();

private:
	int segmentLength(int segment);
};

#endif
