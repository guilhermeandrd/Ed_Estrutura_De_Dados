// NAO MEXA NESTE ARQUIVO, ELE JA ESTA PRONTO PARA SER USADO PELO MOODLE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "ForwardList.h"
#include <algorithm>
using namespace std;

int main() 
{
	ForwardList lista1;

	for(int i=9;i>0;i--){
		lista1.push_front(i);
	}

	for(auto it = lista1.begin();it!=lista1.end();it++){
		cout << *it << " ";
	}

	cout << endl;

	//lista1.erase_after(lista1.begin());

	//TESTAR QUANDO É O ULTIMO ELEMENTO

	lista1.erase_after(lista1.before_end());

	for(auto it = lista1.begin();it!=lista1.end();it++){
		cout << *it << " ";
	}
}