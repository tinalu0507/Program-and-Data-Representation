#include <iostream>

#include "List.h"

using namespace std;

List::List() {
	head = new ListNode();
	tail = new ListNode();
	head->previous = NULL;
	tail->next = NULL;
	head->next = tail;
	tail->previous = head;
	count = 0;
}

List::List(const List& source) {
	head = new ListNode();
	tail = new ListNode();
	head->previous = NULL;
	tail->next = NULL;
	head->next = tail;
	tail->previous = head;
	count = 0;

	ListItr *l = new ListItr(source.head->next);
	while (!l->isPastEnd()) {
		insertAtTail(l->retrieve());
		l->moveForward();
	}

}

List::~List(){
	makeEmpty();
	delete head;
	delete tail;
}

 List& List::operator=(const List& source) {
 	if (this == &source)
 		return *this;
 	else {
 		makeEmpty();
 		ListItr l(source.head->next);
 		while (!l.isPastEnd()) {
 			insertAtTail(l.retrieve());
 			l.moveForward();
 		}
 	}
 	return *this;
 }

 bool List::isEmpty() const{
 	if (count == 0) {
 		return true;
 	}
 	else
 	{
 		return false;
 	}
 }

 void List::makeEmpty() {
 	const int nums = count;
 	ListNode *dele;
 	ListNode *temp;
 	dele = head->next;
 	if (!isEmpty()) {
 		for (int k=1; k<=nums; ++k) {
 			temp = dele->next;
 			delete dele;
 			dele = temp;
 			count --;
 		}
 	}
 	head->next = tail;
 	tail->previous = head;
 }

ListItr List::first(){
	//int firstValue = head -> value;
	//ListNode temp = head;
	//ListItr *l = new ListItr(head);
	//return *l;
	return ListItr(head->next);
} 		//Returns an iterator that points to
    //the ListNode in the first position

ListItr List::last() {
	return ListItr(tail->previous);

}			//Returns an iterator that points to
//the ListNode in the last position

void List::insertAfter(int x, ListItr position) {
	ListNode *l = new ListNode;
	l->value = x;
	l->previous = position.current;
	l->next = position.current->next;

	position.current->next->previous = l;
	position.current->next = l;

	count ++;

}
    //Inserts x after current iterator position p
void List::insertBefore(int x, ListItr position) {
	ListNode *l = new ListNode;
	l->value = x;
	l->next = position.current;
	l->previous = position.current->previous;

	position.current -> previous = l;
	l->previous->next = l;

	count++;
}
    //Inserts x before current iterator position p
void List::insertAtTail(int x) {
	ListNode *l = new ListNode;
	l->value = x;
	l->next = tail;
	l->previous = tail->previous;
	tail->previous->next = l;
	tail->previous = l;
	count++;

}	//Insert x at tail of list
void List::remove(int x) {
	ListItr *l = new ListItr(find(x));

	if (!l->isPastEnd()) {
		l->current->previous->next = l->current->next;
		l->current->next->previous = l->current->previous;
		count--;
		delete l;
	}
}		//Removes the first occurrence of x

ListItr List::find(int x) {
	ListItr *l = new ListItr(first());
	while (!l->isPastEnd()) {
		if (l->retrieve() == x) {
			return *l;
		}
		l->moveForward();
	}
	return *l;
}		//Returns an iterator that points to
    // the first occurrence of x, else return a iterator to the dummy tail node

int List::size() const{
	return count;
} //Returns the number of elements in the list

// printList: non-member function prototype
void printList(List& source, bool direction) {
	if (direction) {
		ListItr *l = new ListItr(source.first());
		while (!l->isPastEnd()) {
			cout << l->retrieve() << " ";
			l->moveForward();
		}
	}
	else {
		ListItr *l = new ListItr(source.last());
		while (!l->isPastBeginning()) {
			cout << l->retrieve() << " ";
			l->moveBackward();
		}
	}
}


//prints list forwards when direction is true
//or backwards when direction is false

