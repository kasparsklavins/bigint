#include <string>
#include <sstream>
#include <map>
#include "Bigint.h"

namespace Dodecahedron {

    //Constructor
    Bigint::Bigint() {
        positive = true;
        base = 1000000000;
        skip = 0;
    }

    Bigint::Bigint(long long value) {
        base = 1000000000;
        skip = 0;
        if (value < 0) {
            positive = false;
            value *= -1;
        } else {
            positive = true;
        }

        while (value) {
            number.push_back(value % base);
            value /= base;
        }
    }

    //Adding
    Bigint Bigint::operator+(Bigint const &b) const {
        Bigint c = *this;
        return c += b;
    }

    Bigint &Bigint::operator+=(Bigint const &b) {
        if (!b.positive) {
            return *this -= b;
        }
        if (!b.positive && positive) {
            positive = false;
        }
        std::vector<int>::iterator
            it1 = number.begin();
        std::vector<int>::const_iterator
            it2 = b.number.begin();
        int sum = 0;
        while (it1 != number.end() || it2 != b.number.end()) {
            if (it1 != number.end()) {
                sum += *it1;
            } else {
                number.push_back(0);
            }
            if (it2 != b.number.end()) {
                sum += *it2;
                ++it2;
            }
            *it1 = sum % base;
            ++it1;
            sum /= base;
        }
        if (sum) number.push_back(1);
        return *this;
    }

    Bigint Bigint::operator+(long long const &b) const {
        Bigint c = *this;
        c += b;

        return c;
    }

    Bigint &Bigint::operator+=(long long b) {
        std::vector<int>::iterator it = number.begin();
        if (skip > number.size()) {
            number.insert(number.end(), skip - number.size(), 0);
        }
        it += skip;
        while (b) {
            if (it != number.end()) {
                *it += b % base;
                b /= base;
                b += *it / base;
                *it %= base;
                ++it;
            } else {
                number.push_back(0);
                it = number.end() - 1;
            }
        }
        return *this;
    }

    //Subtraction
    Bigint Bigint::operator-(Bigint const &b) const {
        Bigint c = *this;
        c -= b;

        return c;
    }

    Bigint &Bigint::operator-=(Bigint const &b) {
        std::vector<int>::iterator
            it1 = number.begin();
        std::vector<int>::const_iterator
            it2 = b.number.begin();
        int dif = 0;
        while (it1 != number.end() || it2 != b.number.end()) {
            if (it1 != number.end()) {
                dif += *it1;
                ++it1;
            }
            if (it2 != b.number.end()) {
                dif -= *it2;
                ++it2;
            }
            if (dif < 0) {
                *(it1 - 1) = (dif * (-1)) % base;
                dif = -1;
            } else {
                *(it1 - 1) = dif % base;
                dif /= base;
            }
        }
        if (dif < 0) positive = false;
        return *this;
    }

    //Multiplication
    Bigint Bigint::operator*(Bigint const &b) {
        if (b.number.size() == 1) return *this *= b.number[0];
        std::vector<int>::iterator it1;
        std::vector<int>::const_iterator it2;
        Bigint c;
        for (it1 = number.begin(); it1 != number.end(); ++it1) {
            for (it2 = b.number.begin(); it2 != b.number.end(); ++it2) {
                c.skip = (int) (it1 - number.begin()) + (int) (it2 - b.number.begin());
                c += (long long) (*it1) * (*it2);
            }
        }
        c.skip = 0;
        return c;
    }

    Bigint &Bigint::operator*=(Bigint const &b) {
        *this = *this * b;

        return *this;
    }

    Bigint Bigint::operator*(long long const &b) {
        Bigint c = *this;
        c *= b;

        return c;
    }

    Bigint &Bigint::operator*=(int const &b) {
        std::vector<int>::iterator it = number.begin();
        long long sum = 0;
        while (it != number.end()) {
            sum += (long long) (*it) * b;
            *it = sum % base;
            sum /= base;
            ++it;
        }
        if (sum) number.push_back(sum);
        return *this;
    }

    //Power
    Bigint Bigint::pow(int const &power, std::map<int, Bigint> &lookup) {
        if (power == 1) return *this;
        if (lookup.count(power)) return lookup[power];

        int closestPower = 1;
        while (closestPower < power) closestPower <<= 1;
        closestPower >>= 1;

        if (power == closestPower) lookup[power] = pow(power / 2, lookup) * pow(power / 2, lookup);
        else lookup[power] = pow(closestPower, lookup) * pow(power - closestPower, lookup);

        return lookup[power];
    }

    Bigint &Bigint::pow(int const &power) {
        std::map<int, Bigint> lookup;
        if (power % 2 == 0 && !positive) {
            positive = true;
        }
        *this = pow(power, lookup);
        return *this;
    }

    //Compare
    int Bigint::compare(const Bigint &a) const {  //0 this == a || -1 this < a || 1 this > a
        if (positive && !a.positive) return 1;
        if (!positive && a.positive) return -1;

        int check = 1;
        if (!positive && !a.positive) check = -1;

        if (number.size() < a.number.size()) return -1 * check;
        if (number.size() > a.number.size()) return check;
        for (unsigned int i(number.size() - 1); i >= 0; --i) {
            if (number[i] < a.number[i]) return -1 * check;
            if (number[i] > a.number[i]) return check;
        }
        return 0; // ==
    }

    bool Bigint::operator<(Bigint const &b) const {
        return compare(b) == -1;
    }

    bool Bigint::operator<=(const Bigint &b) const {
        int compared = compare(b);

        return compared == 0 || compared == -1;
    }

    bool Bigint::operator>(const Bigint &b) const {
        return compare(b) == 1;
    }

    bool Bigint::operator>=(const Bigint &b) const {
        int compared = compare(b);

        return compared == 0 || compared == 1;
    }

    bool Bigint::operator==(Bigint const &b) const {
        return compare(b) == 0;
    }

    //Allocation
    Bigint Bigint::operator=(const long long &a) {
        number.clear();
        long long t = a;
        do {
            number.push_back(t % base);
            t /= base;
        } while (t != 0);
        return *this;
    }

    //Access
    int Bigint::operator[](int const &b) {
        return to_string(*this)[b] - '0';
    }

    //Trivia
    int Bigint::digits() const {
        int segments = number.size();
        if (segments == 0) return 0;
        int digits = 9 * (segments - 1);
        digits += segment_length(number.back());
        return digits;
    }

    int Bigint::trailing_zeros() const {
        if (number.empty() || (number.size() == 1 && number[0] == 0)) return 1;
        int zeros = 0;
        std::vector<int>::const_iterator it = number.begin();
        if (number.size() > 1) {
            for (; it != number.end() - 1 && *it == 0; ++it) {
                zeros += 9;
            }
        }
        int a = *it;
        while (a % 10 == 0 && a) {
            ++zeros;
            a /= 10;
        }
        return zeros;
    }

    //Helpers
    void Bigint::clear() {
        number.clear();
        positive = true;
        skip = 0;
    }

    Bigint &Bigint::abs() {
        positive = true;
        return *this;
    }

    //Input&Output
    std::ostream &operator<<(std::ostream &out, Bigint a) {
        while (a.number.size() && a.number.back() == 0) a.number.pop_back();
        if (!a.number.size()) return out << 0;
        if (!a.positive) out << '-';
        std::vector<int>::const_reverse_iterator it = a.number.rbegin();
        out << *it;
        if (it != a.number.rend()) ++it;
        for (; it != a.number.rend(); ++it) {
            for (int i(0), len = a.segment_length(*it); i < 9 - len; ++i) out << '0';
            if (*it) out << *it;
        }
        return out;
    }

    std::istream &operator>>(std::istream &in, Bigint &a) {
        std::string str;
        in >> str;
        int size = str.length();
        if (str[0] == '-') a.positive = false;
        while (true) {
            if (size <= 0) break;
            if (!a.positive && size <= 1) break;

            int length = 0;
            int num = 0;
            int prefix = 1;
            for (int i(size - 1); i >= 0 && i >= size - 9; --i) {
                if (str[i] < '0' || str[i] > '9') break;
                num += (str[i] - '0') * prefix;
                prefix *= 10;
                ++length;
            }
            a.number.push_back(num);
            size -= length;
        }
        return in;
    }

    int Bigint::segment_length(int segment) const {
        int length = 0;
        while (segment) {
            segment /= 10;
            ++length;
        }
        return length;
    }

    Bigint abs(Bigint value) {
        return value.abs();
    }

    std::string to_string(Bigint value) {
        std::ostringstream stream;
        stream << value;
        return stream.str();
    }

    Bigint factorial(int n) {
        Bigint result = 1;
        if (n % 2) {
            result = n;
            --n;
        }
        int last = 0;
        for (; n >= 2; n -= 2) {
            result *= n + last;
            last += n;
        }
        return result;
    }
}
