
#include "iterator.h"

//typedef hash_map::iterator<Key,Value> HashIterator;

HashIterator& HashIterator::operator++(){
	item = item->next;
	return *this;
}

HashIterator& HashIterator::operator--(){
        item = item->prev;
        return *this;
}


