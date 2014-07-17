#ifndef _HASH_MAP_H_INCLUDED_
#define _HASH_MAP_H_INCLUDED_

template <class T>
class hash_map { 

}
#endif
size_t hash (const Key& key);

iterator begin();
iterator end();
size_t size();
iterator insert (const Key& key, const Value& value); 
void erase (Iterator pos); 
iterator find (const Key& key); 
Value operator[] (const Key& key);

