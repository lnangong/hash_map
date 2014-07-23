
/*
 *This hash map C++ STL container is designed by combination of hash table and indexed chaining, 
 *which is doubly linked list can be indexed by the given key.
 *
 *	Hash map design:
 *
 *             header
		^
 *              v
 *      [0]-->(key,val)<-->(key,val)<-->(key,val)<-->points to first (key,val) in the index[2]
 *      [1]
 *	[2]-->(key.val)<-->points to first (key,val) in the index[n]
 *	[3]
 *       :
 *	 :
 *	[n]-->(key,val)<-->(key,val)<-->trailer
 *
 *      *Note: each table index will points to the first entry and last entry in the
 *            index chain, respectively. In the following comments will use 'entry' and 
 *           'bucket' interchangeably, they are same thing.
 *
 *      Author: Long(Ryan) Nangong
 *      Email: lnangong@hawk.iit.edu
 *	Created on: July 15, 2014
*/

#include <iostream>
#include <string>

using namespace std;


//Constructor
template <typename Key, typename Value>
hash_map<Key,Value>::hash_map(){
	try{
		for(int i = 0; i < capacity; i++){
			HashTable[i] = new entry;
		}
		header = new entry;
		trailer = new entry;
		header->next = trailer;
		trailer->prev = header;	
		hash_size = 0;

	}catch(bad_alloc& ba){
		cerr << "exception caught:" << ba.what() << endl;
	}
}


//Destructor
template <typename Key, typename Value>
hash_map<Key,Value>::~hash_map(){
//	while(!empty()) rmEntry();  TODO: remove entry fucntion
        for(int i = 0; i < capacity; i++){
                delete HashTable[i];
	}
//	delete[] HashTable;
	delete header;
	delete trailer;
        hash_size = 0;
}


//Hash fuction: return hash index
template <typename Key, typename Value>
size_t hash_map<Key,Value>::hash (const Key& key){
	size_t index = key[0] % capacity;	//It's a simple hash just for testing
//	cout << "index of " << key << "=" << index << endl;
	return index;
}


//Hash map size function
template <typename Key, typename Value>
size_t hash_map<Key,Value>::size(){	return hash_size;	}


/*Returns an iterator for the container hash_map that
	points to the first data entry in hash_map*/
template <typename Key, typename Value>
typename hash_map<Key,Value>::iterator 
hash_map<Key,Value>::begin(){	return iterator(header->next);	}


/*Returns an iterator for the container hash_map that
	points to the last data entry in hash_map*/
template <typename Key, typename Value>
typename hash_map<Key,Value>::iterator 
hash_map<Key,Value>::end(){	return iterator(trailer);	}


//Hash insert
template <typename Key, typename Value>
typename hash_map<Key,Value>::iterator 
hash_map<Key,Value>::insert (const Key& key, const Value& value){

	size_t index = hash(key);		//Get hash index

	try{
		entry* bucket = new entry;		//Create new bucket
		bucket->_key = key;
		bucket->_value = value;
	
		hash_size++;
	
		if(header->next == trailer){		//Empty hash map
			HashTable[index]->next = bucket;//Points to first bucket in the index chain
			HashTable[index]->prev = bucket;//Points to last bucket in the index chain
			header->next = bucket;		//Header points to the first bucket in the hash map
			bucket->prev = header;		//First bucket's 'prev' points to the header
			bucket->next = trailer;		//First bucket's 'next' points to the trailer
			trailer->prev = bucket;		//Trailer points to the last bucket

			return iterator(bucket);
		}
	
		//In case of header not points to trailer, hash map is not empty
		if(HashTable[index]->next == NULL){		//Empty index chain
			HashTable[index]->next = bucket;	
	                HashTable[index]->prev = bucket;	
			if(index < hash(header->next->_key)){	//In case of inserting bucket before the header
				bucket->next = header->next;
				bucket->prev = header;
				header->next->prev = bucket;
				header->next = bucket;
			}
			else if(index > hash(header->next->_key) && index < hash(trailer->prev->_key)){
				//In case of inserting bucket between header and trailer
				size_t prev_index = index;

				while(HashTable[--prev_index]->next != NULL){}
		
				bucket->next = HashTable[prev_index]->prev->next;
				bucket->prev = HashTable[prev_index]->prev;
				HashTable[prev_index]->prev->next = bucket;
				bucket->next->prev = bucket;
			}
			else{ //Insert bucket after the trailer
				bucket->next = trailer;
                      		bucket->prev = trailer->prev;
                     		trailer->prev = bucket;
                	        bucket->prev->next = bucket;	
			}

			return iterator(bucket);
		}
	
		//Insert bucket to the index chain, which is not empty
		bucket->next = HashTable[index]->next;		//Insert bucket in the first position in the index chain
		bucket->prev = HashTable[index]->next->prev;
		HashTable[index]->next = bucket;
	
		return iterator(bucket);
	}catch(bad_alloc& ba){
		cerr << "exception caught:" << ba.what() << endl;
		return iterator(NULL);
	}

}


//Hash map find
template <typename Key, typename Value>
typename hash_map<Key,Value>::iterator 
hash_map<Key,Value>::find (const Key& key){
	size_t index = hash(key);		//Find the index by key
	iterator iter(HashTable[index]);	//First iterator entry
	
	for( ; hash(iter._bucket->_key) < index+1; ++iter){	//Search the given key int index chain
		if(iter._bucket->_key == key)
			return iter;
	}

	//Entry is not found in the index chain
	cout << "Item with specified key is not found in the hash map!" << endl;
	return iter._bucket = NULL;
	
}


//Hash map erase
template <typename Key, typename Value>
void hash_map<Key,Value>::erase (iterator pos){
	if(pos._bucket != NULL){
		if(pos._bucket != header && pos._bucket != trailer){  //Not position of header or trailer
			size_t index = hash(pos._bucket->_key);	
	
			if(HashTable[index]->next == pos._bucket && 
				HashTable[index]->prev == pos._bucket){	//There is only one bucket in 
				HashTable[index]->next = NULL;			//the index chain
				HashTable[index]->prev = NULL;
				pos._bucket->prev->next = pos._bucket->next;
                        	pos._bucket->next->prev = pos._bucket->prev;
			
				delete pos._bucket;
			}
			else if(HashTable[index]->next == pos._bucket){	//Delete the first bucket in
				HashTable[index]->next = pos._bucket->next;	//the index chain
				pos._bucket->prev->next = pos._bucket->next;
				pos._bucket->next->prev = pos._bucket->prev;
			
				delete pos._bucket;
			}
			else if(HashTable[index]->prev == pos._bucket){	//Delete the last bucket in 
				HashTable[index]->prev = pos._bucket->prev;	//the index chain
				pos._bucket->prev->next = pos._bucket->next;
                		pos._bucket->next->prev = pos._bucket->prev;
			
				delete pos._bucket;
			}
			else{
				pos._bucket->prev->next = pos._bucket->next;
                       		pos._bucket->next->prev = pos._bucket->prev;

                		delete pos._bucket;
			}
		}	
	}
	
	hash_size--;
}


//Hash map operator [] definition
template <typename Key, typename Value>           
Value hash_map<Key,Value>::operator[] (const Key& key){
	iterator iter = find(key);

	return iter._bucket->_value;
}


