#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void lerVetor(int *A, int n, int e){
    if(n==1||e==n-1){
        cout << A[e] << " ]" << "\n";
    }else{
        if(e==0){
            cout << " [ ";
        }
        cout << A[e] << " ";
        return lerVetor(A, n, e+=1);
    }
}

void inverterVetor(int *A, int n, int e){
    if(n==1||e==0){
        cout << A[e] << " ]" << "\n";
    }else{
        if(e==n-1){
            cout << " [ ";
        }
        cout << A[e] << " ";
        return inverterVetor(A, n, e-=1);
    }
}



void somaVetor(int *A, int n, int e, int soma){
    if(n==1||e==n-1){
        soma+=A[e];
        cout << soma << " ]" << endl;
    }else{
        if(e==0){
            cout << "[ ";
        }
        return somaVetor(A, n, e+=1, soma+=A[e]);
    }
}
void multiVetor(int *A, int n, int e, int mult){
    if(n==1||e==n-1){
        mult*=A[e];
        cout << mult << " ]" << endl;
    }else{
        if(e==0){
            cout << "[ ";
        }
        return multiVetor(A, n, e+=1, mult*=A[e]);
    }
}

void minVetor(int *A, int n, int i, int min){
    if(n==1||i==n-1){
        cout << min << " ] " << endl;
    }else{
        if(i==0){
            cout << "[ ";
        }
        if(A[i]<min){
            return minVetor(A, n, i+=1, min=A[i]);
        }else{
            return minVetor(A, n, i+=1, min);
        }
    }
}

void invVetor(int *A, int n, int i){  
    if( i < n-1){
        int aux = A[i];
        A[i] = A[n-1];
        A[n-1] = aux;
        invVetor(A, n-1,i+1);
    }
}


int main(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;
    while(ss >> value)
        vet.push_back(value);
    
    int soma=0;
    int mult=1;
    

    cout << "vet : ";
    lerVetor(num, n, 0);

    cout << "inv: ";
    inverterVetor(num, n, n-1);

    cout << "sum: ";
    somaVetor(num, n, 0, soma);

    cout << "mult: ";
    multiVetor(num, n, 0, mult);

    int min=num[0];

    cout << "min: ";
    minVetor(num, n, 0, min);

    cout << "inv: ";
    invVetor(num, n, 0);
    lerVetor(num, n, 0);
    
    return 0;

    delete[] num;
}

