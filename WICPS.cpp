#pragma once
#include <iomanip>
#include <iostream>
#include "Patient.cpp"
//#include "List.cpp"
using namespace std;

int main(){
	Patient Steve("1234567898");
	cout << Steve.getCareCard() << endl;
	Steve.printPatient(); 
	
	return 0; 
}