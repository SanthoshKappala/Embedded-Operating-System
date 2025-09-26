(CC) = gcc

mutex : mutex.o -lpthread
	$(CC) -o mutex mutex.o -lpthread

mutex.o : mutex.c 
	$(CC) -c -o mutex.o mutex.c 

clean :
	rm -rf *.o mutex 