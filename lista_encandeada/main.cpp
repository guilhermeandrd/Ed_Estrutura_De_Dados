#include <iostream>
#include "Node.h"
#include "List.h"

using namespace std;

int main() {

    List lista;

    for(int i=9;i>=1;i--){
        lista.push_front(i);
    }

    for(auto it= lista.begin();it != lista.end();it++){
        cout << *it << " ";
    }

    cout << endl;
    
    return 0;
}