#ifndef BIGINT_H
#define BIGINT_H


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

class bigint {
private:
	vector<int> number;
    bool positive;
    int base = 1000000000;
    int skip = 0;

public:
	//Magic methods
	bigint();

	//Adding
	bigint operator+(bigint const &b);
	bigint& operator+=(bigint const &b);
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
    friend istream &operator>>(istream &in, bigint &a);
    friend ostream &operator<<(ostream &out, bigint a);

    //Helpers
    void clear();
    string toString();

	//Power
	bigint& pow(int const &power);
	bigint pow(int const &power, map<int, bigint> &lookup);

    //Trivia
	int digits();
	int trailingZeros();

private:
	int segmentLength(int segment);
};


#endif
