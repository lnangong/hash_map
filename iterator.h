
#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "hash_map.h"


template <typename Key, typename Value>
class hash_map<Key,Value>::iterator{

private:

public:
        iterator& operator++();
        iterator& operator--();
        friend class hash_map;

};

#endif
