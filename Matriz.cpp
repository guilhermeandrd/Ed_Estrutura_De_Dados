// Arquivo de Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"
using namespace std;

// Aloca espaco dinamicamente para matriz com m linhas e n colunas
Matriz::Matriz(int m, int n) {
	// FAZER
}   

// Destrutor: Libera a memoria que foi alocada dinamicamente no construtor
Matriz::~Matriz() {
	// FAZER
}   

// Retorna o numero de linhas da matriz
int Matriz::linhas() {
	// FAZER
} 

// Retorna o numero de colunas da matriz
int Matriz::colunas() { 
	// FAZER
}

// Retorna o valor da celula [i][j] da matriz
int Matriz::getValor(int i, int j) {
	// FAZER
} 

// Atribui valor a celula [i][j] da matriz
void Matriz::setValor(int valor, int i, int j) {
	// FAZER
}

// Imprimir a matriz 
void Matriz::print() {
    for(int i = 0; i < lin; ++i) {
		for(int j = 0; j < col; ++j) {
			cout << setw(7) << mat[i][j];
		}
		cout << "\n";
	}
} 
