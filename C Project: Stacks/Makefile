# Define the machine object files for your program
OBJECTS = main.o Stack.o
# Define your include file
INCLUDES = Stack.h

# make for the executable
projectStack: ${OBJECTS}
	gcc -g -o projectStack ${OBJECTS}

# Simple suffix rules for the .o
%.o: %.c ${INCLUDES}
	gcc -g -c $<

# Clean the .o files
clean:
	rm -f ${OBJECTS}
