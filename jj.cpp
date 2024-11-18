#include <iostream>
#include <string>

using namespace std;

string francear(const string& str){
    string novastr;

    
    for(size_t i=0;i<str.length();i++){

        if((str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')&&str[i+1]==32&&str[i+2]==str[i]){
             if(str[i+3]==32&&str[i+4]==str[i]){
                novastr += str[i];
                i+=4;
            }else{
                novastr += str[i];
                i+=2;
            }
        }else{
           
            novastr += str[i];
        }
    }

    return novastr;
}

int main() {
    string str;

    string palavraFranceada;

    getline(cin, str);

    palavraFranceada = francear(str);

    cout << palavraFranceada;

    return 0;
}