CC := gcc
CFlags := -std=c99 -Wall -Werror -pedantic
GO := ./
ENTER := < test.txt

OBJPATH := ./out/
INCPATH := ./inc/
SRCPATH := ./src/
UNITTESTSPATH := ./unit_tests/

.PHONY: clean

app.exe: $(OBJPATH)main.o $(OBJPATH)matrix_transformation.o $(OBJPATH)allocation.o
	$(CC) -o app.exe $(OBJPATH)main.o $(OBJPATH)matrix_transformation.o $(OBJPATH)allocation.o

$(OBJPATH)main.o: $(SRCPATH)main.c $(INCPATH)errors.h  $(INCPATH)allocation.h $(INCPATH)matrix_transformation.h
	$(CC) $(CFlags) -c $(SRCPATH)main.c -o $(OBJPATH)main.o

$(OBJPATH)matrix_transformation.o: $(SRCPATH)matrix_transformation.c $(INCPATH)matrix_transformation.h $(INCPATH)errors.h
	$(CC) $(CFLAGS) -c $(SRCPATH)matrix_transformation.c -o $(OBJPATH)matrix_transformation.o

$(OBJPATH)allocation.o: $(SRCPATH)allocation.c $(INCPATH)allocation.h $(INCPATH)errors.h
	$(CC) $(CFLAGS) -c $(SRCPATH)allocation.c -o $(OBJPATH)allocation.o

run: app.exe
	$(GO)app.exe $(ENTER)

clean:
	rm $(OBJPATH)*.o *.exe



