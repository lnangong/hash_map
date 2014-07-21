
#include "hash_map.h"

template <typename Key, typename Value>
hash_map<Key,Value>::iterator::iterator(entry* item):_item(item){}

template <typename Key, typename Value>
typename hash_map<Key,Value>::iterator&
hash_map<Key,Value>::iterator::operator++(){
	item = item->next;
	return *this;
}

template <typename Key, typename Value>
typename hash_map<Key,Value>::iterator&
hash_map<Key,Value>::iterator::operator++(){
        item = item->prev;
        return *this;
}


