(CC) =gcc

thread : thread.o 
	$(CC) -o thread thread.o -lpthread

thread.o : thread.c 
	$(CC) -c -o thread.o thread.c 

clean :
	rm -rf *.o thread
