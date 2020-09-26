# Define the machine object files for your program
OBJECTS = ProjectStacks.o Stack.o
# Define your include file
INCLUDES = Stack.h

# make for the executable
projectStacks: ${OBJECTS}
	gcc -g -o projectStacks ${OBJECTS}

# Simple suffix rules for the .o
%.o: %.c ${INCLUDES}
	gcc -g -c $<

# Clean the .o files
clean:
	rm -f ${OBJECTS}
