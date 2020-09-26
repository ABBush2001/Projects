#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

/******
 * In this file, provide all of the definitions of the stack functions as described in stack.h.
 *
 * ****/

//creates a new stack, mallocs an array of elements, and defines max stack size and sets element count to 0
Stack newStack(int maximumStackSize)
{
	StackImp* newStack = (StackImp*)malloc(sizeof(StackImp));

	newStack->maxSize = maximumStackSize;
	newStack->count = 0;
	newStack->stackElements = (Element*)malloc(newStack->maxSize * sizeof(Element));	
	
	return newStack;

}

//puts elements on to the element array in the stack, and reallocs the array to increase its size
void push(Stack s, Element e)
{
	if(s->maxSize <= s->count)
	{
		s->maxSize *= 2;
		s->stackElements = realloc(s->stackElements, s->maxSize * sizeof(int));
	}

	s->stackElements[s->count] = e;
	s->count++;
}

//removes elements on the element array, and sibtracts 1 from count to decrease its size
Element pop(Stack s)
{
	if(isEmpty(s) == 1)
	{
		printf("Error: stack is empty\n");
	}

	else
	{
		s->count--;
	}

	return s->stackElements[s->count];
}

//checks count to see whether or not  the array is empty, returning 1 if true and 0 if false
int isEmpty(Stack s)
{
	if(s->count == 0)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

//returns whatever the top element on the array is, and returns an error message if the array is empty
Element topElement(Stack s)
{
	if(isEmpty(s) == 1)
	{
		printf("Error: stack is empty\n");
		Element e;
		e.operand = -1;
		return e;
	}

	else
	{
		return s->stackElements[s->count - 1];
	}
}

//frees the memory space used by the stack
void freeStack(Stack s)
{
	free(s->stackElements);
	free(s);
}
