
#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>


using std::ostream, std::ifstream;



/**
 * @brief The fraction class is a type-class that adds the Fraction type
 * to any programs that implement it.
 *
 * @details The fraction class should be used when support for fractions
 * is needed. Fractions are supported by allowing the creation of
 * fractions using the overloaded Fraction constructors, the allocation
 * of fractions using the assignment opperator, performing mathamatics
 * with them using the 4 typical binary arithmetic operators, and the
 * arithmetic assignment hybrid operators, plus the 4 unary post/pre
 * increment, and post/pre decrement operators. Also supported are the
 * bitwise operators for "ostream" and "ifstream". Also added is a copy
 * constructor.
 *
 */
namespace cs_fraction
{
class Fraction
{
    public:
    /*
 # FRACTION CLASS CONSTRUCTORS (OVERLOADED +4) */
    Fraction();
    Fraction(int integer);
    Fraction(const Fraction &frac);
    Fraction(int _numerator, int _denominator);
    /*

 # OVERLOADED FRACTION OPERATORS @ (FRACTION|FRACTION) */
    // |> ARITHMETIC OPERATORS (Frac | Frac)
    friend Fraction operator+(const Fraction &ls, const Fraction &rs);
    friend Fraction operator-(const Fraction &ls, const Fraction &rs);
    friend Fraction operator*(const Fraction &ls, const Fraction &rs);
    friend Fraction operator/(const Fraction &ls, const Fraction &rs);

    // |> BIN OPERATORS (Frac | Frac)
    friend bool operator>(const Fraction &ls, const Fraction &rs);
    friend bool operator<(const Fraction &ls, const Fraction &rs);
    friend bool operator>=(const Fraction &ls, const Fraction &rs);
    friend bool operator<=(const Fraction &ls, const Fraction &rs);
    friend bool operator==(const Fraction &ls, const Fraction &rs);
    friend bool operator!=(const Fraction &ls, const Fraction &rs);
    /*

 # OVERLOADED FRACTION OPERATORS @ (FRACTION|INTEGER)               */
    // |> ARITHMETIC OPERATORS (frac|int)
    friend Fraction operator+(const Fraction &ls, const int &rs);
    friend Fraction operator-(const Fraction &ls, const int &rs);
    friend Fraction operator*(const Fraction &ls, const int &rs);
    friend Fraction operator/(const Fraction &ls, const int &rs);

    // |> BIN OPERATORS (frac|int)
    friend bool operator>(const Fraction &ls, const int &rs);
    friend bool operator<(const Fraction &ls, const int &rs);
    friend bool operator>=(const Fraction &ls, const int &rs);
    friend bool operator<=(const Fraction &ls, const int &rs);
    friend bool operator==(const Fraction &ls, const int &rs);
    friend bool operator!=(const Fraction &ls, const int &rs);
    /*

 # OVERLOADED FRACTION OPERATORS @ (INTEGER|FRACTION)               */
    // |> ARITHMETIC OPERATORS (int|frac)
    friend Fraction operator+(const int &ls, const Fraction &rs);
    friend Fraction operator-(const int &ls, const Fraction &rs);
    friend Fraction operator*(const int &ls, const Fraction &rs);
    friend Fraction operator/(const int &ls, const Fraction &rs);

    // |> BIN OPERATORS (int|frac)
    friend bool operator>(const int &ls, const Fraction &rs);
    friend bool operator<(const int &ls, const Fraction &rs);
    friend bool operator>=(const int &ls, const Fraction &rs);
    friend bool operator<=(const int &ls, const Fraction &rs);
    friend bool operator==(const int &ls, const Fraction &rs);
    friend bool operator!=(const int &ls, const Fraction &rs);
    /*

    # FRACTION CLASS OPERATOR-MEMBERS                        */
    // |> BITWISE BIT-SHIFTING OPERATORS
    friend ostream & operator<<(ostream &out, const Fraction &fr);
    friend ifstream &operator>>(ifstream &in, Fraction &fr);

    // |> ASSIGNMENT/ALLOCATION OPERATORS (Frac | Frac)
    Fraction &operator=(const Fraction &fr);
    Fraction  operator+=(const Fraction &frac);
    Fraction  operator-=(const Fraction &frac);
    Fraction  operator*=(const Fraction &frac);
    Fraction  operator/=(const Fraction &frac);

    // |> UNARY OPERATORS
    Fraction operator++();
    Fraction operator--();
    Fraction operator++(int);
    Fraction operator--(int);

    private:
    int numerator   = 0;
    int denominator = 1;

    void simplify();
};
} // namespace cs_fraction