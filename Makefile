CC=gcc 
CFLAGS=-Wall

all: test 
test: test.o array_list.o graph.o hash_table.o heap.o linked_list.o queue.o stack.o tree.o trie.o
test.o: test.c array_list.c graph.c hash_table.c heap.c linked_list.c queue.c stack.c tree.c trie.c

clean:
	rm -f test *.o
run: test
	./test
