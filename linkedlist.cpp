/*
 * (c) 2025 Yunjae Lim <launius@gmail.com>
 *
 * C++ Linked List Implementation
 *
 */

#include "linkedlist.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {
	std::cout << __func__ << ": created\n";
}

LinkedList::~LinkedList() {}

void LinkedList::traverse() {
	Node* temp = head;

	std::cout << __func__ << ": ";
	while (temp) {
		std::cout << temp->value << "(" << temp << ")" << " -> ";
		temp = temp->next;
	}

	std::cout << "nullptr\n";
}

void LinkedList::insertAtHead(int value) {
	Node* node = new Node{ value, head };	// node->value = value; node->next = head;
	head = node;

	std::cout << __func__ << ": " << value << "\n";
}

void LinkedList::insertAtTail(int value) {
	Node* node = new Node{ value, nullptr };
	if (head == nullptr)
		head = node;
	else {
		Node* temp = head;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}

	std::cout << __func__ << ": " << value << "\n";
}

void LinkedList::insertAfter(int value, int after) {
	Node* temp = head;

	while (temp && temp->value != after)
		temp = temp->next;

	if (temp) {
		temp->next = new Node{ value, temp->next };
		std::cout << __func__ << ": " << value << " after " << after << "\n";
	}
	else
		std::cout << __func__ << ": " << after << " not found\n";
}

void LinkedList::deleteNode(int value) {
	Node* temp = head;
	Node* prev = nullptr;

	while (temp && temp->value != value) {
		prev = temp;
		temp = temp->next;
	}

	if (temp) {
		if (prev == nullptr)
			head = temp->next;
		else
			prev->next = temp->next;

		delete temp;
		std::cout << __func__ << ": " << value << "\n";
	}
	else
		std::cout << __func__ << ": " << value << " not found\n";
}

void LinkedList::deleteList() {
	Node* temp = head;
	while (temp) {
		head = temp->next;
		delete temp;
		temp = head;
	}
	head = nullptr;

	std::cout << __func__ << ": deleted\n";
}

void linkedlist_driver()
{
	LinkedList list;

	list.insertAtHead(1);
	list.insertAtHead(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAfter(5, 3);
	list.insertAfter(6, 10);
	list.traverse();

	list.deleteNode(2);
	list.deleteNode(4);
	list.traverse();

	list.deleteList();
	list.traverse();
}
