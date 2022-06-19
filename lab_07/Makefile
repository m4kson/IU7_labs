CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic

OBJPATH := ./out/
INCPATH := ./inc/
SRCPATH := ./src/
UNITTESTSPATH := ./unit_tests/
GO := ./
ARGS := in.txt out.txt f

.PHONY: clean

app.exe: $(OBJPATH)funcs.o $(OBJPATH)main.o $(OBJPATH)sort.o
	$(CC) -o app.exe $(OBJPATH)funcs.o $(OBJPATH)sort.o $(OBJPATH)main.o

$(OBJPATH)funcs.o: $(SRCPATH)funcs.c $(INCPATH)funcs.h
	$(CC) $(CFLAGS) -c $(SRCPATH)funcs.c -o $(OBJPATH)funcs.o

$(OBJPATH)sort.o: $(SRCPATH)sort.c $(INCPATH)sort.h
	$(CC) $(CFLAGS) -c $(SRCPATH)sort.c -o $(OBJPATH)sort.o

$(OBJPATH)main.o: $(SRCPATH)main.c $(INCPATH)funcs.h $(INCPATH)sort.h
	$(CC) $(CFLAGS) -c $(SRCPATH)main.c -o $(OBJPATH)main.o

simple : CFLAGS := -std=c99
simple : app.exe
	$(GO)app.exe $(ARGS)

debug : CFLAGS += -g3
debug : app.exe
	$(GO)app.exe $(ARGS)

release : CFLAGS += -DNDEBUG -g0
release : app.exe

unit_tests.exe: $(OBJPATH)check_funcs.o $(OBJPATH)funcs.o
	$(CC) -o unit_tests.exe $(OBJPATH)check_funcs.o $(OBJPATH)funcs.o -lcheck

$(OBJPATH)check_funcs.o: $(UNITTESTSPATH)check_funcs.c $(INCPATH)funcs.h
	$(CC) $(CFLAGS) -c $(UNITTESTSPATH)check_funcs.c -o $(OBJPATH)check_funcs.o

unit_tests: app.exe unit_tests.exe
	$(GO)unit_tests.exe

time_check: time_tracker.exe
	$(GO)time_tracker.exe

time_tracker.exe: $(OBJPATH)time_tracker.o $(OBJPATH)sort.o
	$(CC) -o time_tracker.exe $(OBJPATH)time_tracker.o $(OBJPATH)sort.o

$(OBJPATH)time_tracker.o: $(SRCPATH)time_tracker.c $(INCPATH)time_tracker.h
	$(CC) $(CFLAGS) -c $(SRCPATH)time_tracker.c -o $(OBJPATH)time_tracker.o

run: app.exe
	$(GO)app.exe $(ARGS)

clean:
	rm $(OBJPATH)*.o *.exe