STL hash_map: hash with chaining
===============================

Copyright (c) 2014, Long(Ryan) Nangong.
All right reserved.
 
Email: lnangong@hawk.iit.edu
Created on: July 15, 2014



*This is unordered hash map, which has constant insert, delete, search time, and suppport forward/backward iteration.

Implemented member functions of hash_map:

	size_t hash (const Key& key);
	size_t size();
	iterator begin();
	iterator end();
	iterator rbegin();
	iterator rend();
	iterator insert (const Key& key, const Value& value); 
	iterator find (const Key& key);
	void erase (iterator pos); 
	Value operator[] (const Key& key);
	
and member functions of iterator:

	iterator& operator++();
	iterator& operator--();
	bool operator==(const iterator& p) const;
	bool operator!=(const iterator& p) const;
	Value& operator*();	
