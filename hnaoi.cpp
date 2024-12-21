#include <iostream>

using namespace std;

void hanoi(int n, char a, char b, char c, char d, int &i){
    if(n>0){
        hanoi(n-1, a, c, d, b, i);
        cout << "mova de" << a << "para" << d << endl;
        hanoi(n-1, b, c, a, d, i);
        i++;
    }
}

int main() {
    int n=0;
    int i=0;
    cin>>n;
    hanoi(n, 'A', 'B', 'C', 'D', i);
    cout << i;
    return 0;
}