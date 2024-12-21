#include <iostream>
#include "Box.h"

/**
 * @brief Classe que implementa uma Caixa 
 */
class Box {
private:
    double height {1.0}; // altura
    double width  {1.0}; // largura
    double length {1.0}; // comprimento

public:
    // Construtor default: esse construtor invoca o construtor com 3 parametros
    //-Box~
    Box() 
        : Box(7.0, 7.0, 7.0) 
    {}

    // Construtor com um parametro
    Box(double h) {
        height = h;
    }

    // Construtor com dois parametros
    Box(double h, double w) {
        height = h;
        width = w;
    }

    // Construtor com tres parametros
    Box(double h, double w, double l) {
        height = h;
        width = w;
        length = l;
        std::cout << "Caixa criada\n";
    }

    // Retorna o volume da caixa
    double volume() {
        return height*width*length;
    }

    // setter, modifica a altura da caixa somente se o valor for nao-negativo.
    // Essa funcao tem um detalhe adicional feito durante a aula: ela retorna uma referencia
    // para o objeto que foi modificado, isso permite invocar funcoes encadeadas no programa principal.
    Box& set_height(double height) {
        if(height >= 0) {
            this->height = height;
        }
        return *this;
    }

    // setter, modifica a largura da caixa somente se o valor for nao-negativo.
    // Essa funcao tem um detalhe adicional feito durante a aula: ela retorna uma referencia
    // para o objeto que foi modificado, isso permite invocar funcoes encadeadas no programa principal.
    Box& set_width(double width) {
        if(width >= 0) {
            this->width = width;
        }
        return *this;
    }

    // setter, modifica o comprimento da caixa somente se o valor for nao-negativo.
    // Essa funcao tem um detalhe adicional feito durante a aula: ela retorna uma referencia
    // para o objeto que foi modificado, isso permite invocar funcoes encadeadas no programa principal.
    Box& set_length(double length) {
        if(length >= 0) {
            this->length = length;
        }
        return *this;
    }

    // getter, retorna a altura
    double get_height() {
        return height;
    }

    // getter, retorna a largura
    double get_width() {
        return width;
    }

    // getter, retorna o comprimento
    double get_length() {
        return length;
    }

    // Destrutor: chamado quando o objeto for destruido
    ~Box() {
        std::cout << "caixa destruída\n";
    }

};