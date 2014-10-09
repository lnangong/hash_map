
//These are member functions of the iterator class


template <typename Key, typename Value>
hash_map<Key,Value>::iterator::iterator(entry* bucket = NULL):_bucket(bucket){}

template <typename Key, typename Value>
typename hash_map<Key,Value>::iterator&
hash_map<Key,Value>::iterator::operator++(){
	_bucket = _bucket->next;
	return *this;
}

template <typename Key, typename Value>
typename hash_map<Key,Value>::iterator&
hash_map<Key,Value>::iterator::operator--(){
        _bucket = _bucket->prev;
        return *this;
}

template <typename Key, typename Value>
bool hash_map<Key,Value>::iterator::operator==(const iterator& p) const{ return _bucket == p._bucket; } 


template <typename Key, typename Value>
bool hash_map<Key,Value>::iterator::operator!=(const iterator& p) const{ return _bucket != p._bucket; }


template <typename Key, typename Value>
Value& hash_map<Key,Value>::iterator::operator*(){ 
	if(_bucket != NULL){ return _bucket->_value; }	
}

