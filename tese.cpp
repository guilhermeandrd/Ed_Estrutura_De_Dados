#include <iostream>

using namespace std;

int main() {

    int i;

    cin >> i;

    int n[i];

    for(int j=0; j<i;j++){
        cin >> n[j];
        if(n[j]<n[j-1]){
            cout << "precisa de ajuste" << endl;
            break;
        }
        if(n[j]==i-1&&n[j]>n[j-1]){
            cout << "ok" << endl;
        }
    }

    return 0;
}