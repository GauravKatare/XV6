objects = file1.o file2.o
myob : $(objects)
    gcc -o myob $(objects)
	cd subdir && $(MAKE)
file1.o : file1.c head.h
	gcc -c file1.c 
file2.o : file2.c head.h 
	gcc -c file2.c
clean : 
	rm -r *.o
	rm -r myob
