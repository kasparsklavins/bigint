[![Build Status](https://travis-ci.org/kasparsklavins/bigint.svg)](https://travis-ci.org/kasparsklavins/bigint)

* [Description](#description)   
* [Operators](#operators)
  * [Addition](#addition)
  * [Subtraction](#subtraction)
  * [Multiplication](#multiplication)
  * [Modulo](#modulo)
  * [Allocation](#allocation)
  * [Comparison](#comparison)
  * [Access](#access)
  * [Streaming operators](#streaming-operators)
* [Methods](#methods)
  * [clear](#clear)
  * [abs](#abs)
  * [pow](#powint)
  * [digits](#digits)
  * [trailing_zeros](#trailing_zeros)
* [Functions](#functions)
  * [abs](#absbigint)
  * [to_string](#to_stringbigint)
  * [factorial](#factorialint)

# Description
Bigint class provides math operations for arbitrarily large numbers. You know the limit is reached when your computer freezes.

# Operators
## Addition
```C++
Dodecahedron::Bigint a,b,c;
c = a + b;
c += a;
c = a + 6;
c += 6;
```
## Subtraction
```C++
Dodecahedron::Bigint a,b,c;
c = a - b;
c -= a;
```
## Multiplication
```C++
Dodecahedron::Bigint a,b,c;
c = a * b;
c *= a;
c = a * 6;
c *= 6;
```
## Modulo
```C++
Dodecahedron::Bigint a;
int b;
b = a % 31415;
```
## Allocation
```C++
Dodecahedron::Bigint a = 12345;
Dodecahedron::Bigint b;
b = 159753;
```
##Comparison
```C++
Dodecahedron::Bigint a = 159753;
Dodecahedron::Bigint b = 1634687496;

if(a == b) cout << "A is the same as B";
if(a < b) cout << "A is less than B";
if(a > b) cout << "A is larger than B";
if(a >= b) cout << "A is larger than B or equal to it";
if(a <= b) cout << "A is smaller than B or equal to it";
```
## Access
```C++
Dodecahedron::Bigint a = 159753;
a.pow(15); //a^15, 1126510743106482...
cout << a[3]; // 6 is the 4th digit
```
## Stream operators
```C++
Dodecahedron::Bigint a,b;
cin >> a >> b;
cout << a*b;
```
# Methods
## clear()
Clears the Dodecahedron::Bigint, essentially making it equal to 0.
```C++
Dodecahedron::Bigint a = 4558;
cout << a.pow(486);;  // ~1.46 * 10^1778
a.clear();
cout << a; //0
```
## abs()
Absolute value.
```C++
Dodecahedron::Bigint a = -4558;
cout << a.abs() // 4558
```
## pow(int)
Raises to the power of N.
```C++
Dodecahedron::Bigint a = 4558;
cout << a.pow(486); // ~1.46 * 10^1778
```
## digits()
Returns the number of digits.
```C++
Dodecahedron::Bigint a = 4558;
cout << a.pow(486).digits(); // 4558^486 = 1779 digit number
```
## trailing_zeros()
Returns the number of trailing zeros.
```C++
Dodecahedron::Bigint a = 4558;
a.pow(486);
cout << a.trailing_zeros(); //972
```
# Functions
## abs(Bigint)
Same as [abs](#abs), but returns a new instance;
```C++
Dodecahedron::Bigint a = -455897864531248;
cout << abs(a) // 455897864531248
```
## to_string(Bigint)
Converts the big integer to a string.
```C++
string str;
Dodecahedron::Bigint a = 455897864531248;
str = to_string(a);
```
## factorial(int)
Returns a factorial of an integer, aka n!
```C++
cout << Dodecahedron::factorial(20000); //70`000+ digit number
```
