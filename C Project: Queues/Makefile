# Define the machine object files for your program
OBJECTS = main.o Queue.o
# Define your include file
INCLUDES = Queue.h

# make for the executable
projectQueue: ${OBJECTS}
	gcc -g -o projectQueue ${OBJECTS}

# Simple suffix rules for the .o
%.o: %.c ${INCLUDES}
	gcc -g -c $<

# Clean the .o files
clean:
	rm -f ${OBJECTS}
