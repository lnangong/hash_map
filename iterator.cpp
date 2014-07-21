
#include "hash_map.h"

template <typename Key, typename Value>
hash_map<Key,Value>::iterator::iterator(entry* bucket):_bucket(bucket){}

template <typename Key, typename Value>
typename hash_map<Key,Value>::iterator&
hash_map<Key,Value>::iterator::operator++(){
	bucket = bucket->next;
	return *this;
}

template <typename Key, typename Value>
typename hash_map<Key,Value>::iterator&
hash_map<Key,Value>::iterator::operator++(){
        bucket = bucket->prev;
        return *this;
}


