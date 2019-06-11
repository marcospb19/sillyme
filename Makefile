.DEFAULT_GOAL = sillyme
CC = gcc
Cflags = -Wall -Wextra -Werror -pedantic -std=c11
OBJECTS = sillyme.o functions.o


sillyme: $(OBJECTS)
	$(CC) $(Cflags) -o sillyme $(OBJECTS)

%.o: %.cpp
	$(CC) -c $^ -o $@

clean:
	@rm $(OBJECTS) 2> /dev/null
