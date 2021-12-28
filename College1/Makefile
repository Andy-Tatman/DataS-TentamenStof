CC = g++

CompileParms = -c -Wall -std=c++11

OBJS = main.o trie.o

HEAD = trie.h

all: main

main: $(OBJS) 
	$(CC) $(OBJS) -o $@

%.o: %.cc $(HEAD)
	$(CC) $(CompileParms) $<

clean:
	rm -f main
	rm -f $(OBJS)

# trie.o: trie.cc
# 	$(CC) $(CompileParms) trie.cc
