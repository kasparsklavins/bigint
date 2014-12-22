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
  * [toString](#toString)
  * [abs](#abs)
  * [pow](#pown)
  * [digits](#digits)
  * [trailingZeros](#trailingZeros)

#Description
Bigint class provides math operations for arbitrarily large numbers. You know the limit is reached when your computer freezes.

#Operators
##Addition
```C++
bigint a,b,c;
c = a + b;
c += a;
c = a + 6;
c += 6;
```
##Subtraction
```C++
bigint a,b,c;
c = a - b;
c -= a;
```
##Multiplication
```C++
bigint a,b,c;
c = a * b;
c *= a;
c = a * 6;
c *= 6;
```
##Allocation
```C++
bigint a;
a = 159753;
```
##Comparison
```C++
bigint a,b;
a = 159753;
b = 1634687496;
if(a == b) cout << "A is the same as B";
else if(a < b) cout << "A is smaller than B";
else cout << "A is larger than B;
```
##Access
```C++
bigint a;
a = 159753;
a.pow(15); //a^15, 1126510743106482...
cout << a[3]; // 6 is the 4th digit
```
##Streaming operators
```C++
bigint a,b;
cin >> a >> b;
cout << a*b;
```
#Methods
##clear()
Clears the bigint, essentially making it equal to 0.
```C++
bigint a;
a = 4558;
cout << a.pow(486);;  //1459889316343...
a.clear();
cout << a; //0
```
##toString()
Convers bigint to a string.
```C++
string str;
bigint a;
a = 4558;
str = a.pow(486).toString();
```
##abs()
Absolute value.
```C++
bigint a;
a = -4558;
cout << a.abs() // 4558
```
##pow(n)
Raises to the power of N.
```C++
bigint a;
a = 4558;
cout << a.pow(486);
```
##digits()
Returns the number of digits.
```C++
bigint a;
a = 4558;
a.pow(486);
cout << a.digits(); //1779
```
##trailingZeros()
Returns the number of trailing zeros.
```C++
bigint a;
a = 4558;
a.pow(486);
cout << a.trailingZeros(); //972
```
