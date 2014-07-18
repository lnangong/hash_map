#ifndef _HASH_MAP_H_INCLUDED_
#define _HASH_MAP_H_INCLUDED_


template <typename K, typename V>
class hash_map { 
	public:
		class iterator;
		
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

