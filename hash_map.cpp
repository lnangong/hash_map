#include <iosteam>
#include "hash_map.h"

using namespace std;


//Constructor
template <typename Key, typename Value>
hash_map<Key,Value>::hash_map(){
	for(int i = 0; i < capacity; i++)
		HashTable[i] = new entry;
	
	header->next = trailer;
	trailer->prev = header;	
	hash_size = 0;
}

//Destructor
template <typename Key, typename Value>
hash_map<Key,Value>::~hash_map(){
	while(!empty()) rmEntry(); //TODO: remove entry fucntion
        for(int i = 0; i < capacity; i++){
                delete HashTable[i];
		delete HashTailer[i];
	}
        hash_size = 0;
}

//Hash fuction: return hash value
template <typename Key, typename Value>
size_t hash_map<Key,Value>::hash (const Key& key){
	//TODO: hashing function
}

//Hash map size function
template <typename Key, typename Value>
size_t hash_map<Key,Value>::size(){	return hash_size;	}

/*Returns an iterator for the container hash_map that
	points to the first data entry in hash_map*/
template <typename Key, typename Value>
typename hash_map<Key,Valu>::iterator 
hash_map<Key,Value>::begin(){	return iterator(header->next)	}

/*Returns an iterator for the container hash_map that
	points to the last data entry in hash_map*/
template <typename Key, typename Value>
typename hash_map<Key,Valu>::iterator 
iterator hash_map::end(){	return iterator(trailer);	}


                iterator insert (const Key& key, const Value& value);

                void erase (Iterator pos);

                iterator find (const Key& key);

                Value operator[] (const Key& key);
