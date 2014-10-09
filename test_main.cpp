// Hash map test
#include <iostream>
#include <string>
#include "hash_map.h"

using namespace std;


int main(){
	//hash_map instantiation
	hash_map<string,int> HashMap;
	hash_map<string,int>::iterator iter;


	//insert	
	HashMap.insert("alpha",10);
	HashMap.insert("alpha1",20);
	HashMap.insert("beta",30);
	HashMap.insert("beta1",40);
	HashMap.insert("gamma",50);
	HashMap.insert("gamma1",60);
	HashMap.insert("alpha",70);  //duplicatd key insertion test

	cout << "hash size = " << HashMap.size() << endl;	


	//iterator forward
	cout << "iterator forward:" << endl;
	for(iter = HashMap.begin(); iter != HashMap.end(); ++iter)
		cout << *iter << endl;
	cout << "\n";


	//iterator backward
	cout << "iterator backward:" << endl;
        for(iter = HashMap.rbegin(); iter != HashMap.rend(); --iter)
                cout << *iter << endl;
	cout << "\n";


	//hash_map find
	cout << "hash map find:" << endl;
	iter = HashMap.find("alpha1");
//	*iter = 100;
	cout << *iter << endl;
	iter = HashMap.find("gamma1");
	cout << *iter << endl;

//	iter = HashMap.find("sigma");
	cout << "\n";


	//hash_map erase
        cout << "hash map erase:" << endl;
	HashMap.erase(iter = HashMap.find("alpha1"));	
	HashMap.erase(iter = HashMap.find("gamma1"));
	HashMap.erase(iter = HashMap.find("beta"));
        for(iter = HashMap.begin(); iter != HashMap.end(); ++iter)
                cout << *iter << endl;

	cout << "hash size = " << HashMap.size() << endl;
        cout << "\n";

	
	//hash_map operator[]
	cout << "hash map operator[]:" << endl;
	cout << HashMap["alpha"] << endl;
	cout << HashMap["beta"] << endl;
	cout << HashMap["gamma"] << endl;
	
	return 0;
}
