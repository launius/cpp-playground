/*
 * (c) 2025 Yunjae Lim <launius@gmail.com>
 *
 * C++ Linked List Implementation
 *
 */

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

struct Node {
	int value;
	Node* next;
};

class LinkedList {
	Node* head;

public:
	LinkedList();
	~LinkedList();
	void traverse();
	void insertAtHead(int value);
	void insertAtTail(int value);
	void insertAfter(int value, int after);
	void deleteNode(int value);
	void deleteList();
};

void linkedlist_driver();

#endif
