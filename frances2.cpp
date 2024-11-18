#include <iostream>
#include <string>

using namespace std;

string francear(const string& str) {
    string novastr;

    for (size_t i = 0; i < str.length(); i++) {
        // Verifica se temos a sequência de uma vogal, espaço, e a mesma vogal repetida
        if ((str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') &&
            i + 2 < str.length() && str[i + 1] == ' ' && str[i + 2] == str[i]) {

            novastr += str[i];  // Adiciona a vogal original
            i += 2;  // Pula o espaço e a vogal duplicada

            // Verifica se existe mais uma sequência de espaço + vogal
            while (i + 2 < str.length() && str[i + 1] == ' ' && str[i + 2] == str[i]) {
                i += 2;  // Continua pulando enquanto houver a mesma vogal após um espaço
            }
        } else {
            novastr += str[i];  // Caso não seja uma sequência, adiciona o caractere normalmente
        }
    }

    return novastr;
}

int main() {
    string str;

    cout << "Digite a string: ";
    getline(cin, str);

    string palavraFranceada = francear(str);

    cout << "String franceada: " << palavraFranceada << endl;
    return 0;
}
