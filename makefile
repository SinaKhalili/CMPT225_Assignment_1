all: wicps

wicps: WICPS.o List.o Patient.o
	g++ -Wall -o -w wicps WICPS.o List.o Patient.o

WICPS.o: WICPS.cpp List.h Patient.h
	g++ -Wall -c -w WICPS.cpp

List.o: List.h List.cpp
	g++ -Wall -c -w List.cpp

Patient.o: Patient.h Patient.cpp
	g++ -Wall -c -w Patient.cpp

clean:
	rm -f -w wicps *.o
