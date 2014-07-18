#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_

#include "iterator.h"

template <typename Key, typename Value>
class hash_map { 
	public:
		class iterator;
	
		hash_map(int capacity = 100);
		~hash_map();

		iterator begin();
		iterator end();
		size_t size();
		iterator insert (const Key& key, const Value& value); 
		void erase (Iterator pos); 
		iterator find (const Key& key); 
		Value operator[] (const Key& key);
	private:
		int n;
		size_t hash (const Key& key);

}
#endif

