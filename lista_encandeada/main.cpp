#include <iostream>
#include "Node.h"
#include "ForwardList.h"
//to com problema no reverse e no remove
using namespace std;

int main() {
    ForwardList lista;
    ForwardList lista2;
    ForwardList lista3;

    for(int i=4;i>=1;i--){
        lista3.push_front(i);
    }

    lista3.reverse();

    for(auto it= lista3.begin();it != lista3.end();it++){
        cout << *it << " ";
    }

    return 0;
}