(CC)= gcc

arith : arith.o libshared.so
	$(CC) -o arith arith.o -L. -lshared

arith.o : arith.c 
	$(CC) -c -o arith.o arith.c 

clean : 
	rm -rf *.o arith 