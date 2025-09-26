(CC) =gcc

exe: main.o add.o mul.o
	$(CC) -o exe main.o mul.o add.o

main.o: main.c 
	$(CC) -c -o main.o main.c 
	
mul.o: mul.c 
	$(CC) -c -o mul.o mul.c 

add.o: add.c 
	$(CC) -c -o add.o add.c 

clear:
	rm -rf *.o exe