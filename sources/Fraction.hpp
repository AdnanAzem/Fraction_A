#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

namespace ariel{

    class Fraction
    {
    private:
        int numerator;
        int denominator;
        

    public:
        // const
        Fraction();
        Fraction(int , int);
        Fraction(float);
        
        //setters
        void setNumerator(int);
        void setDenominator(int);

        //getters
        int getNumerator();
        int getDenominator();

        //helper functions
        void reduce();
        int GCD();
        string toString();
        void convertFloatToFraction(float);
		float convertFractionToFloat();

        // Overloaded operators 
        Fraction operator+(const Fraction&) const;
        Fraction operator-(const Fraction&) const;
        Fraction operator*(const Fraction&) const;
        Fraction operator/(const Fraction&) const;

        friend Fraction operator+(float ,Fraction &);
        friend Fraction operator-(float ,Fraction &);
        friend Fraction operator*(float ,Fraction &);
        friend Fraction operator/(float ,Fraction &);
        
        bool operator==(const Fraction&) const;
        bool operator<(const Fraction&) const;
        bool operator<=(const Fraction&) const;
        bool operator>(const Fraction&) const;
        bool operator>=(const Fraction&) const;

        Fraction& operator++();
        Fraction operator++( int );
        Fraction& operator--();
        Fraction operator--( int );

        friend ostream & operator<<(ostream&, const Fraction&);
        friend istream& operator>> (istream&,const Fraction& );

    };    
    
}