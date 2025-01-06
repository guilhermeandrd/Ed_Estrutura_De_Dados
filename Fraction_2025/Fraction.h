#ifndef FRACTION_H
#define FRACTION_H

#include <numeric>
#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int m_numerator;
    int m_denominator;

    // Método privado para garantir que o denominador seja sempre positivo

public:
    //construtor default
    Fraction()
        : Fraction(1,1)
    {

    }

    // Construtor que recebe numerador e denominador e cria a fração
    Fraction(int numerator, int denominator)
        : m_numerator{numerator}, m_denominator{denominator} // lista de inicialização
    {
        if (m_denominator == 0)
            throw std::runtime_error("Denominador não pode ser zero");
        reduce();
    }

    // Método que simplifica a fração
    void reduce() {
        int gcd = std::gcd(m_numerator, m_denominator);
        m_numerator /= gcd;
        m_denominator /= gcd;
    }

    // Getters
    int getNumerator() const {
        return m_numerator;
    }

    int getDenominator() const {
        return m_denominator;
    }

    // Setters
    void setNumerator(int newNumerator) {
        m_numerator = newNumerator;
        reduce();
    }

    void setDenominator(int newDenominator) {
        if (newDenominator == 0)
            throw std::runtime_error("Denominador não pode ser zero");
        m_denominator = newDenominator; // Atualiza o denominador
        reduce();
    }

    /*ja que a função é amiga, eu posso acessasr diretamente os atributos e métodos privados

    friend Fraction operator+(const Fraction& f1, const Fraction& f2);*/


    //Sobrecarga do operador+ como função membro da classe Fraction
    Fraction operator+(const Fraction& f2){
        //cout << f1.operator+(f2);//como funcao membro
        int newDenominator =m_denominator*f2.m_denominator;
        int newNumerator = f2.m_numerator*m_denominator + m_numerator*f2.m_denominator;
        return Fraction(newNumerator, newDenominator);//uso do método construtor
    }

    friend std::ostream& operator<<(std::ostream&out, const Fraction& f );//o primeiro parametro é o cout como objeto
    friend std::istream& operator>>(std::istream&in, Fraction& f );

    Fraction& operator+=(const Fraction& f){
        //todo objeto tem como ponteiro *this

        /*setDenominator(m_denominator*f.m_denominator);
        setNumerator(m_numerator*f.m_denominator+m_denominator*f.m_numerator);
        reduce();*/
        *this = *this+f;
        return *this;
    }

    bool operator==(const Fraction& f2){
        return m_denominator==f2.m_denominator&&m_numerator==f2.m_numerator;
    }

    bool operator!=(const Fraction& f2){
        return !(*this==f2);
    }

    bool operator>(const Fraction& f2){
        //ver se um é maior que o outro, como?
        float a= m_numerator/m_denominator;
        float b= f2.m_numerator/f2.m_denominator;
        return a>b;
    }

    bool operator<(const Fraction& f2){
        return !(*this>f2);
    }

    bool operator>=(const Fraction& f2){
        return (*this>f2)||(*this==f2);
    }

    bool operator<=(const Fraction& f2){
        return (*this<f2)||(*this==f2);
    }

    Fraction operator-(const Fraction& f2){
        int newDenominator = m_denominator*f2.m_denominator;
        int newNumerator =  m_numerator*f2.m_denominator-f2.m_numerator*m_denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction& operator-=(const Fraction& f2){
        *this = *this - f2;
        return *this;
    }

    Fraction operator*(const Fraction& f2){
        int newDenominator =m_denominator*f2.m_denominator;
        int newNumerator = f2.m_numerator*m_numerator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator/(const Fraction& f2){
        int newNumerator =m_numerator*f2.m_denominator;
        int newDenominator = f2.m_numerator*m_denominator;
        return Fraction(newNumerator, newDenominator);
    }


};

//sobrecarga do operador<< como funcção global amiga
std::ostream& operator<<(std::ostream&out, const Fraction& f ){
    out << f.m_numerator << "/" << f.m_denominator;
    return out;
}

//sobrecarga do operador>> como função global amiga
std::istream& operator>>(std::istream&in, Fraction& f ){
    in >> f.m_numerator;
    in.ignore();//vai ignorar a barra
    in >> f.m_denominator;
    f.reduce();
    return in;
}


/*Sobrecarga do operador + como uma função global
Fraction operator+(const Fraction& f1, const Fraction& f2){
    int newDenominator = f1.getDenominator()*f2.getDenominator();
    int newNumerator = f2.getNumerator()*f1.getDenominator ()+ f1.getNumerator()*f2.getDenominator();
    return Fraction(newNumerator, newDenominator);//uso do método construtor
}*/

#endif
