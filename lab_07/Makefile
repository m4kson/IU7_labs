CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic

OBJPATH := ./out/
INCPATH := ./inc/
SRCPATH := ./src/
UNITTESTSPATH := ./unit_tests/

.PHONY: clean

app.exe: $(OBJPATH)funcs.o $(OBJPATH)main.o
	$(CC) -o app.exe $(OBJPATH)funcs.o $(OBJPATH)main.o

$(OBJPATH)funcs.o: $(SRCPATH)funcs.c $(INCPATH)funcs.h
	$(CC) $(CFLAGS) -c $(SRCPATH)funcs.c -o $(OBJPATH)funcs.o

$(OBJPATH)main.o: $(SRCPATH)main.c $(INCPATH)funcs.h
	$(CC) $(CFLAGS) -c $(SRCPATH)main.c -o $(OBJPATH)main.o

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

unit_tests.exe: $(OBJPATH)check_funcs.o $(OBJPATH)funcs.o
	$(CC) -o unit_tests.exe $(OBJPATH)check_funcs.o $(OBJPATH)funcs.o -lcheck

$(OBJPATH)check_funcs.o: $(UNITTESTSPATH)check_funcs.c $(INCPATH)funcs.h
	$(CC) $(CFLAGS) -c $(UNITTESTSPATH)check_funcs.c -o $(OBJPATH)check_funcs.o

clean:
	rm $(OBJPATH)*.o *.exe