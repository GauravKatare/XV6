objects = function1.o function2.o main.o
obj = file1.o file2.o
	
myob : $(objects) 
	g++ -o myob $(objects)
	gcc -o myapp $(obj)
	cd subdir && $(MAKE) 
c :
	gcc -c *.c
c++ : 
	g++ -c *.cpp
clean : 
	rm -r *.o
	rm -r myob
	rm -r myapp
