EXEC=exec
CC=gcc
OPTION=-o
OPTIONC=-c
FLAGS= -DNDEBUG
# -Wall 
PATHC=sources/
PATHH=headers/

.PHONY: move clear $(EXEC)

exec: stack.o utils.o main.o $(PATHC)calculette.c 
	$(CC) stack.o utils.o main.o $(PATHC)calculette.c $(FLAGS) $(OPTION) exec && ./exec

main.o: $(PATHC)main.c
	$(CC) $(OPTIONC) $(PATHC)main.c

lex.yy.c: $(PATHC)calculette.l
	lex -t $(PATHC)calculette.l > $(PATHC)calculette.c

stack.o: $(PATHC)stack.c $(PATHH)stack.h
	$(CC) $(OPTIONC) $(PATHC)stack.c

utils.o: $(PATHC)utils.c $(PATHH)utils.h
	$(CC) $(OPTIONC) $(PATHC)utils.c

clear:
	rm -f *.o && rm -f data/*.o  

move:
	mv *.o data && mv exec data
