CC := gcc
CFlags := -std=c99 -Wall -Werror -pedantic
GO := ./

OBJPATH := ./out/
INCPATH := ./inc/
SRCPATH := ./src/
UNITTESTSPATH := ./unit_tests/

.PHONY: clean

app.exe: $(OBJPATH)main.o
	$(CC) -o app.exe $(SRCPATH)main.c

$(OBJPATH)main.o: $(SRCPATH)main.c
	$(CC) $(CFlags) -c $(SRCPATH)main.c -o $(OBJPATH)main.o

run: app.exe
	$(GO)app.exe

clean:
	rm $(OBJPATH)*.o *.exe


