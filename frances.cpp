#include <iostream>
#include <string>

using namespace std;

string francear(const string& str){
    string novastr;

    int j=0;
    for(int i=0;i<str.length();i++){
        
        novastr += str[i];

        if(str[i]=='a'&&str[i+1]==32&&str[i+2]=='a'){
            i += 2;
        }else if(str[i]=='e'&&str[i+1]==32&&str[i+2]=='e'){
            i += 2;
        }else if(str[i]=='i'&&str[i+1]==32&&str[i+2]=='i'){
            i += 2;
        }else if(str[i]=='o'&&str[i+1]==32&&str[i+2]=='o'){
            i += 2;
        }else if(str[i]=='u'&&str[i+1]==32&&str[i+2]=='u'){
            i += 2;
        }
        j++;

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