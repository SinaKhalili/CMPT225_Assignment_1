#include <iomanip>
#include <iostream>
#include "Patient.cpp"
#include "List.cpp"
using namespace std;

int main(){
	Patient Steve("1234567898");
	cout << Steve.getCareCard() << endl;
	Steve.setName("Marie Lower");
	Steve.setAddress("123 A Ave Vancouver");
	Steve.setPhone("778-123-1234");
	Steve.setEmail("marie@somewhere.ca");
	Steve.printPatient(); 

	
	return 0; 
}