#pragma once
#include <string>
#include "Patient.cpp"
#include "List.h"
using namespace std;

List::List() : elementCount(0){};

int List::getElementCount() const{
	return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented. 
bool List::insert(const Patient& newElement){
	//Precondition:

	if(elementCount < MAX_ELEMENTS){ //Check if available space exists
		for(int i = 0; i < elementCount; ++i){ //Check each element to make sure it is not already in data collection
			if(elements[i] == newElement){//Element already exists in data collection
				return false; 
			}
		}
	} else { //List already contains max elements
		return false;
	}

	//Postconditions:

	elementCount++;
	elements[elementCount] = newElement;

	return true;
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove(const Patient& toBeRemoved){
	for(int i = 0; i < elementCount; ++i){
		if(elements[i] == toBeRemoved){ //If target element exists in the list
			
			for(int ii = i; ii < elementCount; ++ii){ 
				elements[ii] = elements[ii + 1];
			}

			elementCount--;
			return true;
		}
	}

	//If the element was not contained in target list:
	return false;
}

// Description: Remove all elements.
void List::removeAll(){
	elementCount = 0;
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target){
	for(int i = 0; i < elementCount; ++i){
		if(elements[i] == target){
			return &elements[i];
		}
	}

	return NULL;
}

// Description: Prints all elements stored in List.
void List::printList(){
	for(int i = 0; i < elementCount; ++i){
		elements[i].printPatient();
	}
}