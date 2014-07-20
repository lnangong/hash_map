#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_		//Header guard

#include "node.h"



template <typename Key, typename Value>
class hash_map { 
private:
	static const int capacity=100;
	node<Key,Value>* HashTable[capacity];
	size_t hash_size;

public:
	class iterator;		//class proto.
	
	hash_map();
	~hash_map();
	size_t hash (const Key& key);
	iterator begin();
	iterator end();
	size_t size();
	iterator insert (const Key& key, const Value& value); 
	void erase (iterator pos); 
	iterator find (const Key& key); 
	Value operator[] (const Key& key);

public:
	class iterator{
	private:
        	node<Key,Value>* _item;
        	iterator(node<Key,Value>* item);

	public:
        	iterator& operator++();
        	iterator& operator--();
        	friend class hash_map;

	};
		
};


#endif

