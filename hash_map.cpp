
#include <iosteam>
#include <string>
#include "hash_map.h"

using namespace std;


//Constructor
template <typename Key, typename Value>
hash_map<Key,Value>::hash_map(){
	for(int i = 0; i < capacity; i++)
		HashTable[i] = new entry;

	header = new entry;
	trailer = new entry;
	header->next = trailer;
	trailer->prev = header;	
	hash_size = 0;
}


//Destructor
template <typename Key, typename Value>
hash_map<Key,Value>::~hash_map(){
	while(!empty()) rmEntry(); //TODO: remove entry fucntion
        for(int i = 0; i < capacity; i++)
                delete HashTable[i];

	delete header;
	delete trailer;
        hash_size = 0;
}


//Hash fuction: return hash index
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


//Hash insert
template <typename Key, typename Value>
typename hash_map<Key,Valu>::iterator 
iterator insert (const Key& key, const Value& value){
	int index = hash(key);
	entry* bucket = new entry;
	bucket->_key = key;
	bucket->_value = value;

	if(HashTable[index]->next == NULL){
		HashTable[index]->bucket;
		bucket->prev = HashTable[index];
		bucket->next = NULL;	

		return iterator(bucket);
	}

	bucket->prec = HashTable[index];
	bucket->next = HashTable[index]->next;
	HashTable[index]->next = bucket;

	return iterator(bucket);
	
}


//Hash find
template <typename Key, typename Value>
typename hash_map<Key,Valu>::iterator 
iterator find (const Key& key){
	int index = hash(key);
	iterator iter(HashTable[index]);
	
	for( ; iter->_bucket->next != NULL; ++iter){
		if(iter->_bucket->_key == key)
			return iter;
	}

	return iter(NULL);
	
	
}



void erase (Iterator pos);

             
Value operator[] (const Key& key);






