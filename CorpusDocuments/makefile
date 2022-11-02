CC=gcc
EXEC=exec
OPTION=-o
OPTIONO=-c
CFLAGS=-Wall -DNDEBUG
PATHC=sources/
PATHH=headers/
OBJECTS=character.o corpus.o statistics.o linkedlist.o hashmap.o bufferReader.o binaryTree.o main.o
HEADERS=character.h corpus.h statistics.h linkedlist.h hashmap.h bufferReader.h binaryTree.h

.PHONY: clear move $(EXEC) 

#########################################

exec: $(OBJECTS)
	$(CC) $(OBJECTS)  $(CFLAGS) $(OPTION) exec && make move

main.o: $(PATHC)main.c 
	$(CC) $(OPTIONO) $(PATHC)main.c

binaryTree.o: $(PATHC)binaryTree.c $(PATHH)binaryTree.h
	$(CC) $(OPTIONO) $(PATHC)binaryTree.c

bufferReader.o: $(PATHC)bufferReader.c $(PATHH)bufferReader.h
	$(CC) $(OPTIONO) $(PATHC)bufferReader.c

hashmap.o: $(PATHC)hashmap.c $(PATHH)hashmap.h
	$(CC) $(OPTIONO) $(PATHC)hashmap.c

linkedlist.o: $(PATHC)linkedlist.c $(PATHH)linkedlist.h
	$(CC) $(OPTIONO) $(PATHC)linkedlist.c

statistics.o: $(PATHC)statistics.c $(PATHH)statistics.h
	$(CC) $(OPTIONO) $(PATHC)statistics.c

corpus.o: $(PATHC)corpus.c $(PATHH)corpus.h
	$(CC) $(OPTIONO) $(PATHC)corpus.c
	
character.o: $(PATHC)character.c $(PATHH)character.h
	$(CC) $(OPTIONO) $(PATHC)character.c


#########################################

clear: 
	rm -f data/*.o && rm -f exec && rm -f *.o

move: 
	mv *.o data
	
