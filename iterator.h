
#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "hash_map.h"
#include "node.h"



template <typename Key, typename Value>
class hash_map<Key,Value>::iterator{

private:
	typedef node<Key,Value> Node;
	Node* item;
	iterator(Node* item);

public:
        iterator& operator++();
        iterator& operator--();
        friend class hash_map;

};

#endif
