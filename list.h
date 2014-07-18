#ifndef _NODE_H_INCLUDED_
#define _NODE_H_INCLUDED_

template <typename K, typename V>
class Node{
        private:
		K key;
                V value;                        //node value
                Node<K,V>* next;                  //next node
                Node<K,V>* prev;                  //previous node
                friend class DLinkedList;
};

template <typename K, typename V>
class DLinkedList { 
        public:
                DLinkedList();
		~DLinkedList();
		bool empty() const;
		const V& front() const;
		void addFront(const V& e);
		void removeFront();
	private:
		Node<K,V>* head;
};
#endif
