
#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_		//Header guard


template <typename Key, typename Value>
class hash_map { 			//Hash_map interface
private:
	class entry{			//Entry node
	public:
        	Key _key;              	//Entry key
        	Value _value;          	//Entry value
        	entry* next;          	//next entry
        	entry* prev;          	//previous entry
	};

public:
	class iterator{			//Hash_map iterator
	private:
        	entry* _bucket;
        	iterator(entry* bucket);

	public:
        	iterator& operator++();
        	iterator& operator--();
		friend class hash_map;

	};
	
public:
	hash_map();
	~hash_map();
	size_t hash (const Key& key);
	size_t size();
	iterator begin();
	iterator end();
	iterator insert (const Key& key, const Value& value); 
	iterator find (const Key& key);
	void erase (iterator pos); 
	Value operator[] (const Key& key);

private:
	static const int capacity=100;
	entry* HashTable[capacity];
	entry* header;
	entry* trailer;
	size_t hash_size;
	
};


#endif

