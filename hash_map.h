#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_

#include "node.h"

template <typename Key, typename Value>
class hash_map { 
private:
	static const int capacity=100;
	node<Key,Value>* item[capacity];

public:
	class iterator;
	
	hash_map(int capacity = 100);
	~hash_map();
		
	size_t hash (const Key& key);
	iterator begin();
	iterator end();
	size_t size();
	iterator insert (const Key& key, const Value& value); 
	void erase (iterator pos); 
	iterator find (const Key& key); 
	Value operator[] (const Key& key);
private:
	size_t hash_size;
		
};

template <typename Key, typename Value>
class hash_map<Key,Value>::iterator{

private:

public:

        friend class hash_map;

};

#endif

