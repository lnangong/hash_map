#include <iosteam>
#include "hash_map.h"

using namespace std;


//Constructor
template <typename Key, typename Value>
hash_map<Key,Value>::hash_map(){
	for(int i = 0; i < capacity; i++)
		HashTable[i] = new Node;

	hash_size = 0;
}

//Destructor
template <typename Key, typename Value>
hash_map<Key,Value>::~hash_map(){
        for(int i = 0; i < capacity; i++)
                delete HashTable[i];

        hash_size = 0;
}

//Hash fuction: return hash value
template <typename Key, typename Value>
size_t hash_map<Key,Value>::hash (const Key& key){
	//TODO: hashing function
}

template <typename Key, typename Value>
hash_map<Key,Valu>::iterator hash_map::begin(){
	
	iterator();
	/*Returns an iterator for the container ct that
	 points to the first data item in ct*/
}

iterator hash_map::end(){
	/*It is a flag and does NOT return the last element*/

}

template <typename Key, typename Value>
                size_t hash_map<Key>size();

                iterator insert (const Key& key, const Value& value);

                void erase (Iterator pos);

                iterator find (const Key& key);

                Value operator[] (const Key& key);
