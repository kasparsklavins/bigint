* [Description](#description)
* [Operators](#operators)
  * [Addition](#addition)
  * [Subtraction](#subtraction)
  * [Multiplication](#multiplication)
  * [Allocation](#allocation)
  * [Comparison](#comparison)
  * [Access](#access)
  * [Streaming operators](#streaming-operators)
* [Methods](#methods)
  * [clear](#clear)
  * [to_string](#toString)
  * [abs](#abs)
  * [pow](#pown)
  * [digits](#digits)
  * [trailing_zeros](#trailingZeros)

#Description
Bigint class provides math operations for arbitrarily large numbers. You know the limit is reached when your computer freezes.

#Operators
##Addition
```C++
Bigint a,b,c;
c = a + b;
c += a;
c = a + 6;
c += 6;
```
##Subtraction
```C++
Bigint a,b,c;
c = a - b;
c -= a;
```
##Multiplication
```C++
Bigint a,b,c;
c = a * b;
c *= a;
c = a * 6;
c *= 6;
```
##Allocation
```C++
Bigint a = 12345;
Bigint b;
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
##Access
```C++
Dodecahedron::Bigint a = 159753;
a.pow(15); //a^15, 1126510743106482...
cout << a[3]; // 6 is the 4th digit
```
##Streaming operators
```C++
Dodecahedron::Bigint a,b;
cin >> a >> b;
cout << a*b;
```
#Methods
##clear()
Clears the Dodecahedron::Bigint, essentially making it equal to 0.
```C++
Dodecahedron::Bigint a = 4558;
cout << a.pow(486);;  //1459889316343...
a.clear();
cout << a; //0
```
##to_string()
Convers Dodecahedron::Bigint to a string.
```C++
string str;
Dodecahedron::Bigint a = 4558;
str = a.pow(486).to_string();
```
##abs()
Absolute value.
```C++
Dodecahedron::Bigint a = -4558;
cout << a.abs() // 4558
```
##pow(n)
Raises to the power of N.
```C++
Dodecahedron::Bigint a = 4558;
cout << a.pow(486);
```
##digits()
Returns the number of digits.
```C++
Dodecahedron::Bigint a = 4558;
a.pow(486);
cout << a.digits(); //1779
```
##trailing_zeros()
Returns the number of trailing zeros.
```C++
Dodecahedron::Bigint a = 4558;
a.pow(486);
cout << a.trailing_zeros(); //972
```