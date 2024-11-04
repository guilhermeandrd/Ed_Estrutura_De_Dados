#include <iostream>


using namespace std;

int get_int(){
    while(true){
        int value;
        cin >> value;
        if(cin.fail()){
            cerr << "error: invalid data\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max()),'\n';
        }else{
            cin.ignore();
            return value;
        }
    }
}

int main() {


    return 0;
}