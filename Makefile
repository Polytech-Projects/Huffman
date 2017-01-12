CC=gcc
OBJFILES=main.o arbre.o tools.o
CCFLAGS= -Wall -g
all: huffman_exe
	
huffman_exe: $(OBJFILES)
	 $(CC) $(CCFLAGS) -o huffman_exe arbre.c tools.c main.c
arbre.o: arbre.h arbre.c
	 $(CC) $(CCFLAGS) -c arbre.c
tools.o: tools.h tools.c
	 $(CC) $(CFLAGS) -c tools.c
main.o:  main.c
	 $(CC) $(CFlAGS) -c main.c
clean:
	 rm *.o huffman_exe

