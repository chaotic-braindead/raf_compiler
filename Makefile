EXEC = a.exe
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

$(EXEC): $(OBJECTS)
	gcc $(OBJECTS) -o $(EXEC)

%.o: %.c include/%.h
	gcc -c $< -o $@

clean:
	del *.o
	del $(EXEC)