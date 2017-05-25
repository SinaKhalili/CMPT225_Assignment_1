#pragma once
#include <iomanip>
#include <iostream>
#include "Patient.cpp"
//#include "List.cpp"
using namespace std;

int main(){
	Patient Steve;
	cout << Steve.getCareCard() << endl;
	
	
	return 0; 
}