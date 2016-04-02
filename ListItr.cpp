#include <iostream>

#include "ListItr.h"

using namespace std;

ListItr::ListItr() {
	current = NULL;
}

ListItr::ListItr(ListNode* theNode) {
	current = theNode;
}	// One parameter constructor

bool ListItr::ListItr::isPastEnd() const {
	return (current->next == NULL);
}	//Returns true if past end position
    // in list, else false

bool ListItr::ListItr::isPastBeginning() const {
	return (current->previous == NULL);
}//Returns true if past first position
    // in list, else false
void ListItr::moveForward() {
	if (!isPastEnd()) {
		current = current->next;
	}
}	//Advances current to next position in list
    //(unless already past end of list)
void ListItr::moveBackward() {
	if (!isPastBeginning()) {
		current = current->previous;
	}
}	//Moves current back to previous position
    // in list (unless already past beginning of
    // list)
int ListItr::retrieve() const {
	return current->value;
}	//Returns item in current position

