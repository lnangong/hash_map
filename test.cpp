
#include <iostream>
#include <string>
#include "hash_map.h"

using namespace std;


//Testing program!
int main(){
	
	hash_map<string,int> HashMap;
	
	HashMap.insert("alpha", 10);
	HashMap.insert("beta", 20);
	HashMap.insert("gamma",30);

	for(hash_map<string,int>::iterator it = HashMap.begin(); it != HashMap.end(); ++it)
		cout << *it << endl;

	
	cout << HashMap["alpha"] << endl;
	cout << HashMap["beta"] << endl;
	cout << HashMap["gamma"] << endl;
	
	return 0;
}
