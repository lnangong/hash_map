#ifndef _NODE_H_INCLUDED_
#define _NODE_H_INCLUDED_

template <typename K, typename Value>
class Node{
        private:
		K key;
                Value value;                        //node value
                Node<K,Value>* next;                  //next node
                Node<K,Value>* prev;                  //previous node
                friend class DLinkedList;
};

template <typename K, typename Value>
class DLinkedList { 
        public:
                DLinkedList();
		~DLinkedList();
		bool empty() const;
		const Value& front() const;
		void addFront(const Value& e);
		void removeFront();
	private:
		Node<K,Value>* head;
};
#endif
