objects = function1.o function2.o main.o
myob : $(objects)
ifeq ($(USE_C),1)
	mkdir output
	g++ -o myob $(objects)
	mv *.o output/
else
	rm -r *.o
endif
function1.o : function1.cpp
	g++ -c function1.cpp
function2.o : function2.cpp
	g++ -c function2.cpp
main.o : main.cpp functions.h
	g++ -c main.cpp
clean : 
	rm -rf output
	rm -r myob
