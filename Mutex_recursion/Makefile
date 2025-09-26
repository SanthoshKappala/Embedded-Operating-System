CC = gcc

mutex_recursion : mutex_recursion.o	-lpthread
	$(CC) -o mutex_recursion mutex_recursion.o 	-lpthread

mutex_recursion.o : mutex_recursion.c 
	$(CC) -c -o mutex_recursion.o mutex_recursion.c 

clean :
	rm -rf *.o mutex_recursion