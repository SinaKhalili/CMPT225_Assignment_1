#pragma once
#include <string>
#include "Patient.h"
#include "Patient.cpp"
#include "List.h"
using namespace std;

//CODE IS MOSTLY UNTESTED, AND WILL CONTINUE TO BE UNTESTED UNTIL PATIENT.CPP IS COMPLETE
//THERE ARE LIKELY BUGS

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
			Patient newElements[MAX_ELEMENTS]; //Make a new array that holds all other elements
			for(int ii = 0; ii < elementCount; ++ii){ 
				if(ii != i){ //Add any element that's not toBeRemoved to the new array
					newElements[ii] = elements[ii];
				} else { //Skip removed element and continue the loop one past it
					newElements[ii] = elements[ii + 1];
					ii++; //Loop will increment this one more time so we won't add the same element twice
				}
			}
			elements = &newElements[0];
			elementCount--;
			return true;
		}
	}

	//If the element was not contained in target list:
	return false;
}

// Description: Remove all elements.
void removeAll(){
	Patient newElements[MAX_ELEMENTS];
	elements = newElements;
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* search(const Patient& target){
	for(int i = 0; i < elementCount; ++i){
		if(*target == *elements[i]){
			return elements[i];
		}
	}

	return NULL;
}

// Description: Prints all elements stored in List.
void printList(){
	for(int i = 0; i < elementCount; ++i){
		*elements[i].printPatient();
	}
}