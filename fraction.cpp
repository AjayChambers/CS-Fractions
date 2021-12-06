#include "fraction.h"


using namespace std;

namespace cs_fraction
{

Fraction::Fraction() = default;




Fraction::Fraction(int integer) : numerator(integer) { simplify(); }




Fraction::Fraction(const Fraction &frac)
{
    numerator   = frac.numerator;
    denominator = frac.denominator;
}




Fraction::Fraction(int _numerator, int _denominator)
: numerator(_numerator), denominator(_denominator)
{
    simplify();
}



// MEMBER FUNCTION: SIMPLIFY
void Fraction::simplify()
{
    if (numerator == 0)
    {
        return;
    }

    int lrgNum = numerator;
    int smNum  = denominator;

    if (denominator > numerator)
    {
        lrgNum = denominator;
        smNum  = numerator;
    }

    bool valid_GCF = false;

    int factorOf = 2;
    int factor   = 2;

    if (lrgNum % smNum == 0)
    {
        numerator   = numerator / smNum;
        denominator = denominator / smNum;

        return;
    }
    else
    {
        while (factor >= 2 && !valid_GCF)
        {
            factor = smNum / factorOf;

            if (smNum % factorOf == 0 && 0 == lrgNum % factor)
            {
                numerator   = numerator / factor;
                denominator = denominator / factor;

                valid_GCF = true;
            }

            factorOf++;
        }
    }
}




ostream &operator<<(ostream &out, const Fraction &fr)
{
    if (fr.numerator > fr.denominator)
    {
        out << fr.numerator << '/' << fr.denominator;
    }
    else
    {
        cout << fr.numerator / fr.denominator << '+'
             << fr.numerator % fr.denominator << '/' << fr.denominator;
    }


    return out;
}


ifstream &operator>>(ifstream &in, Fraction &fr)
{
    char ch;

    if (in.peek() != ' ')
    {
        in >> fr.numerator >> ch >> fr.denominator;
    }

    return in;
}

/*



      *-----------------(FRACTION*FRACTION)-----------------*/
Fraction operator+(const Fraction &ls, const Fraction &rs)
{
    return Fraction(ls.denominator * rs.numerator +
                      ls.numerator * rs.denominator,
                    ls.denominator * rs.denominator);
}





Fraction operator-(const Fraction &ls, const Fraction &rs)
{
    return Fraction(ls.denominator * rs.numerator -
                      ls.numerator * rs.denominator,
                    ls.denominator * rs.denominator);
}





Fraction operator*(const Fraction &ls, const Fraction &rs)
{
    return Fraction(ls.numerator * rs.numerator,
                    ls.denominator * rs.denominator);
}





Fraction operator/(const Fraction &ls, const Fraction &rs)
{
    return Fraction(ls.denominator * rs.numerator,
                    ls.numerator * rs.denominator);
}


bool operator>(const Fraction &ls, const Fraction &rs)
{
    return (ls.denominator * rs.numerator >
            ls.numerator * rs.denominator);
}



bool operator<(const Fraction &ls, const Fraction &rs)
{
    return (ls.denominator * rs.numerator <
            ls.numerator * rs.denominator);
}





bool operator>=(const Fraction &ls, const Fraction &rs)
{
    return (ls.denominator * rs.numerator >=
            ls.numerator * rs.denominator);
}





bool operator<=(const Fraction &ls, const Fraction &rs)
{
    return (ls.denominator * rs.numerator <=
            ls.numerator * rs.denominator);
}





bool operator==(const Fraction &ls, const Fraction &rs)
{
    return ls.numerator == rs.numerator &&
           ls.denominator == rs.denominator;
}





bool operator!=(const Fraction &ls, const Fraction &rs)
{
    return !(ls.numerator == rs.numerator &&
             ls.denominator == rs.denominator);
}


/*














      *-----------------(FRACTION*INTEGER)-----------------*/
Fraction operator+(const Fraction &ls, const int &rs)
{
    const int _numerator = (ls.denominator * rs) + ls.numerator;

    return Fraction(_numerator, ls.denominator);
}





Fraction operator-(const Fraction &ls, const int &rs)
{
    return Fraction(ls.denominator * rs - ls.numerator, ls.denominator);
}





Fraction operator*(const Fraction &ls, const int &rs)
{

    return Fraction(rs * ls.numerator, ls.denominator);
}





Fraction operator/(const Fraction &ls, const int &rs)
{
    return Fraction(ls.denominator * rs, ls.numerator);
}





bool operator>(const Fraction &ls, const int &rs)
{
    return ls.numerator > (rs * ls.denominator);
}





bool operator<(const Fraction &ls, const int &rs)
{
    return ls.numerator < (rs * ls.denominator);
}





bool operator>=(const Fraction &ls, const int &rs)
{
    return ls.numerator >= (rs * ls.denominator);
}





bool operator<=(const Fraction &ls, const int &rs)
{
    return ls.numerator <= (rs * ls.denominator);
}





bool operator==(const Fraction &ls, const int &rs)
{
    return ls.numerator == (rs * ls.denominator);
}





bool operator!=(const Fraction &ls, const int &rs)
{
    return !(ls.numerator * ls.denominator == rs);
}




/*

      *-----------------(INTEGER*FRACTION)-----------------*/

Fraction operator+(const int &ls, const Fraction &rs)
{
    //          1   1
    //      =    _ + _
    //          6   3
    return Fraction(rs.denominator * ls + rs.numerator, rs.denominator);
}




Fraction operator-(const int &ls, const Fraction &rs)
{
    return Fraction(rs.denominator * ls - rs.numerator, rs.denominator);
}




Fraction operator*(const int &ls, const Fraction &rs)
{
    return Fraction(ls * rs.numerator, rs.denominator);
}




Fraction operator/(const int &ls, const Fraction &rs)
{
    return Fraction(rs.numerator, rs.denominator * ls);
}





bool operator>(const int &ls, const Fraction &rs)
{
    return rs.numerator > (ls * rs.denominator);
}





bool operator<(const int &ls, const Fraction &rs)
{
    return rs.numerator < (ls * rs.denominator);
}





bool operator>=(const int &ls, const Fraction &rs)
{
    return rs.numerator >= (ls * rs.denominator);
}





bool operator<=(const int &ls, const Fraction &rs)
{
    return rs.numerator <= (ls * rs.denominator);
}





bool operator==(const int &ls, const Fraction &rs)
{

    return rs.numerator == (ls * rs.denominator);
}



bool operator!=(const int &ls, const Fraction &rs)
{
    return !(ls * rs.denominator == rs.numerator);
}

/*







    # # # # # ASSIGNMENT OPERATORS # # # # #             */
Fraction &Fraction::operator=(const Fraction &fr)
{
    this->numerator = fr.numerator;
    denominator     = fr.denominator;

    return *this;
}





Fraction Fraction::operator+=(const Fraction &frac)
{
    *this = *this + frac;

    return *this;
}





Fraction Fraction::operator-=(const Fraction &frac)
{
    *this = *this - frac;

    return *this;
}





Fraction Fraction::operator*=(const Fraction &frac)
{
    *this = *this * frac;

    return *this;
}





Fraction Fraction::operator/=(const Fraction &frac)
{
    *this = *this / frac;

    return *this;
}





/*






        # # # # # ASSIGNMENT OPERATORS # # # # #             */
Fraction Fraction::operator++()
{
    numerator = numerator + denominator;

    return *this;
}





Fraction Fraction::operator--()
{
    numerator = numerator - denominator;

    return *this;
}





Fraction Fraction::operator++(int)
{
    Fraction wait(numerator, denominator);
    ++wait;

    return wait;
}





Fraction Fraction::operator--(int)
{
    Fraction wait(numerator, denominator);
    --wait;

    return wait;
}





} // namespace cs_fraction
