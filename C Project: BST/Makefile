# Define the machine object files for your program
OBJECTS = main.o BinarySearchTree.o
# Define your include file
INCLUDES = BinarySearchTree.h

# make for the executable
pBST: ${OBJECTS}
	gcc -g -o pBST ${OBJECTS}

# Simple suffix rules for the .o
%.o: %.c ${INCLUDES}
	gcc -g -c $<

# Clean the .o files
clean:
	rm -f ${OBJECTS}
