CC=gcc 
CFLAGS=-Wall

all: autocomplete
autocomplete: autocomplete.o autocomplete_trie.o ../trie.o ../array_list.o ../linked_list.o
autocomplete.o: autocomplete.c autocomplete_trie.c ../trie.c ../array_list.c ../linked_list.c

clean:
	rm -f autocomplete *.o ../*.o
run: autocomplete
	./autocomplete