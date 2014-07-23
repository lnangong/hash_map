hash_map: hash with chaining
===============================

Author:Long(Ryan) Nangong

Created on July 15, 2014

Email: lnangong@hawk.iit.edu

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
