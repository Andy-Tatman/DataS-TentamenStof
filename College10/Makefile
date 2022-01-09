CC = g++

CompileParms = -c -Wall -std=c++11

OBJS = \
	kmp.o \
	\

HEAD = \
	\ 


all: kmp

kmp: $(OBJS) 
	$(CC) $(OBJS) -o $@

%.o: %.cc $(HEAD)
	$(CC) $(CompileParms) $<

clean:
	rm -f kmp
	rm -f $(OBJS)

