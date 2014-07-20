#ifndef _NODE_H_
#define _NODE_H_

template <typename Key, typename Value>
class node{
private:
	Key key;			//node key
        Value value;                    //node value
        node<Key,Value>* next;          //next node
        node<Key,Value>* prev;          //previous node
        friend class hash_map;
};


#endif
