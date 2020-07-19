objects = function1.o function2.o main.o
myob : $(objects)
	mkdir output
	g++ -o myob $(objects)
	mv *.o output/
function1.o : function1.cpp
	g++ -c function1.cpp
function2.o : function2.cpp
	g++ -c function2.cpp
main.o : main.cpp functions.h
	g++ -c main.cpp
clean : 
	rm -rf output
	rm -r myob
