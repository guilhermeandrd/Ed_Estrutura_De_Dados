#include <iostream>

// Classe que implementa uma lista linear de inteiros
//é do conteúdo de lista linear
//o que ele ta fazendo é criar um novo objeto com aqueles elemtentos?
class Vector {
private:
    int capacity; // tamanho maximo do array
    int size; // numero de elementos na lista
    int *array; // ponteiro para o array de int

public:
    // construtor de copia
    Vector(const Vector& vec);

    // Construtor default
    Vector();

    // Destrutor
    ~Vector();

    // Solicita que a capacidade do vetor seja >= n .
    // Se n for maior que a capacidade atual do vetor , a
    // funcao faz com que a lista aumente sua capacidade
    // realocando os elementos para o novo vetor . Em todos//para um novo vetor= para um novo objeto
    // os outros casos , a chamada da funcao nao causa uma
    // realocacao e a capacidade do vetor nao eh afetada .
    void reserve ( int n ) ; // O (n)

    // Recebe um inteiro como argumento e o adiciona
    // logo apos o ultimo elemento da lista .
    void push_back ( const int & value ) ; // tempo medio O (1)

    // Retorna uma referencia para o elemento na posicao k .
    // A funcao verifica automaticamente se n esta dentro dos
    // limites de elementos validos no vetor , lancando uma
    // excecao ’ out_of_range ’ se nao estiver .
    int &at (int k); // O (1)
    //const int & at ( int k ) const ; // O (1)

    //retorna quantos elentos tem na lista
    int getSize() const;

    //ver se a lista esta vazia
    bool empty() const;

    //retorna capacidade da lista
    int getCapacity() const;

    //sobrecarga do operador []
    //recebe um indice e retorna o elemento na posicao k
    //se k for invalido, a culpa é sua, se vire
    int& operator[] (int k);

    void pop_back();
};