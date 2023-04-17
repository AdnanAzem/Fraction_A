#include "Fraction.hpp"

/*

*/

namespace ariel{

    // ======================= Constructors =======================

    Fraction::Fraction(){}

    Fraction::Fraction(int num1, int num2): numerator(num1), denominator(num2){}

    Fraction::Fraction(float num): numerator(num), denominator(num){}

    // ======================= Setters =======================

    void Fraction::setNumerator(int num){
        this->numerator = num;
    }

    void Fraction::setDenominator(int num){
        this->denominator = num;
    }

    // ======================= Getters =======================

    int Fraction::getNumerator(){
        return this->numerator;
    }

    int Fraction::getDenominator(){
        return this->denominator;
    }

    // ======================= Helper Functions =======================

    string Fraction::toString(){
        string res;
        return res;
    }

    int Fraction::GCD(){ // find the gcd between the numerator & the denominator
        int gcd = 1;
        for(int i = 1; i <= this->numerator || i <= this->denominator; i++) {
            if(this->numerator % i == 0 && this->denominator % i == 0)
            gcd = i;
        }
        return gcd;
    }
        
    void Fraction::reduce(){ // to reduce the fraction to his reduced form
        int gcd = this->GCD();
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd; 
    }

    void convertFloatToFraction(float num){ // convert from float to fraction

    }

	float convertFractionToFloat(){ // convert from fraction to float
        return 0;
    }

    // ======================= Operators =======================

    Fraction Fraction::operator+(const Fraction &other)const{ // Fraction + Fraction
        Fraction result;
        result = Fraction(this->numerator * other.denominator + this->denominator * other.numerator,this->denominator * other.denominator);
        result.reduce();
        return result;
    }

    Fraction Fraction::operator-(const Fraction &other)const{ // Fraction - Fraction
        Fraction result;
        result = Fraction(this->numerator * other.denominator - this->denominator * other.numerator,this->denominator * other.denominator);
        result.reduce();
        return result;  
    }

    Fraction Fraction::operator*(const Fraction &other)const{ // Fraction * Fraction
        Fraction result;
        result = Fraction(this->numerator * other.numerator,this->denominator * other.denominator);
        result.reduce();
        return result;
    }

    Fraction Fraction::operator/(const Fraction &other)const{ // Fraction / Fraction
        Fraction result;
        result = Fraction(this->numerator * other.denominator,this->denominator * other.numerator);
        result.reduce();
        return result;
    }

    Fraction operator+(float num,Fraction & fraction){
        return fraction;
    }

    Fraction operator-(float num,Fraction & fraction){
        return fraction;
    }

    Fraction operator*(float num,Fraction & fraction){
        return fraction;
    }

    Fraction operator/(float num,Fraction & fraction){
        return fraction;
    }

    // ======================= Equalations =======================

    bool Fraction::operator==(const Fraction&frac)const{return true;}
    bool Fraction::operator>(const Fraction &frac)const{return true;}
    bool Fraction::operator>=(const Fraction &frac)const{return true;}
    bool Fraction::operator<(const Fraction &frac)const{return true;}
    bool Fraction::operator<=(const Fraction &frac)const{return true;}


    // ======================= Increasement & Decreasment =======================

    Fraction& Fraction::operator++(){ // pre-Increasement
        Fraction franction;
        return *this;
    }
    Fraction Fraction::operator++(int num){ // post-Increasement
        Fraction franction;
        return franction;
    }
    Fraction& Fraction::operator--(){ // pre-Decreasment
        Fraction franction;
        return *this;
    }
    Fraction Fraction::operator--(int num){ // post-Decreasment
        Fraction franction;
        return franction;
    }

    // ======================= input & output =======================

    istream& operator>> (istream &input ,const Fraction& frac){
        return input;
    }

    ostream& operator<<(ostream &out ,const Fraction &Fraction){
        return out;
    }


}