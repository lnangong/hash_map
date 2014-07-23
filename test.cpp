
#include <iostream>
#include <string>
#include "hash_map.h"

using namespace std;


//Testing program!
int main(){

	//hash_map instantiation
	hash_map<string,int> HashMap;

	//insert	
	HashMap.insert("alpha",10);
	HashMap.insert("alpha1",20);
	HashMap.insert("beta",30);
	HashMap.insert("beta1",40);
	HashMap.insert("gamma",50);
	HashMap.insert("gamma1",60);
	cout << "hash size = " << HashMap.size() << endl;	

	//iterator forward
	cout << "iterator forward:" << endl;
	for(hash_map<string,int>::iterator it = HashMap.begin(); it != HashMap.end(); ++it)
		cout << *it << endl;
	cout << "\n";

	//iterator backward
	cout << "iterator backward:" << endl;
        for(hash_map<string,int>::iterator it = HashMap.rbegin(); it != HashMap.rend(); --it)
                cout << *it << endl;
	cout << "\n";

	//hash_map find
	cout << "hash map find:" << endl;
	hash_map<string,int>::iterator it = HashMap.find("alpha1");
	cout << *it << endl;
	cout << "\n";

	//hash_map erase
        cout << "hash map erase:" << endl;
	HashMap.erase(it = HashMap.find("alpha1"));	
	HashMap.erase(it = HashMap.find("gamma1"));
	HashMap.erase(it = HashMap.find("beta"));
        for(hash_map<string,int>::iterator it = HashMap.begin(); it != HashMap.end(); ++it)
                cout << *it << endl;

	cout << "hash size = " << HashMap.size() << endl;
        cout << "\n";

	
//	it = HashMap.find("sigma");

	//hash_map operator[]
	cout << "hash map operator[]:" << endl;
	cout << HashMap["alpha"] << endl;
	cout << HashMap["beta"] << endl;
	cout << HashMap["gamma"] << endl;
	
	return 0;
}
