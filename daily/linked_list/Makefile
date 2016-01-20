#Nathan Mankovich
#1/20/2016
#makefile for linked_list program

look:
	ls

linked_list.o: linked_list.c
	gcc -I. -c -o linked_list.o linked_list.c

linked_list_test.o: linked_list_test.c
	gcc -I. -c -o linked_list_test.o linked_list_test.c

compile: linked_list_test.o linked_list.o
	gcc -o test linked_list_test.o linked_list.o

test: compile
	./test

clean:
	rm *.o
	rm test
