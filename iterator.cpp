
#include "hash_map.h"

typedef hash_map<Key,Value>::iterator<Key,Value> HashIterator;

HashIterator& HashIterator::operator++(){
	item = item->next;
	return *this;
}

HashIterator& HashIterator::operator--(){
        item = item->prev;
        return *this;
}


