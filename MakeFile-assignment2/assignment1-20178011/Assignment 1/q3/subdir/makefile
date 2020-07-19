objects = subfile.o
my : $(objects)
	gcc -o my $(objects)
	cd tmp && $(MAKE)
subfile.o : subfile.c
	gcc -c subfile.c
clean : 
	rm -r *.o
	rm -r my
