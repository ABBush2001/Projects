#include "Stack.h"
#define MAX_LINE_LENGTH 50


int convertToPostfix(char *infixString, char *postfixString);
int evaluatePostfix(char *postfixString);


int main()
{
	FILE *inputFile;
	inputFile = fopen("p1Input.txt", "r");
	if(inputFile == NULL){

		perror("Error opening file");
		return -1;
	}


	//This string will hold the infix equations that are read from inputFile, one at a time.
	char infixString[MAX_LINE_LENGTH];


	//Use fgets to read the next line from the inputFile.
	//Store the line into infixString.
	//The while loop repeats until there are no more lines in the file.
	while(fgets(infixString, MAX_LINE_LENGTH, inputFile)!=NULL){

		//If the line is blank, skip it.
		if(infixString[0] == '\n')
			continue;

		printf("Current infix string: %s",infixString);
		
		//postfixString is a string to store the equation from szInfixString converted into postfix.
		char postfixString[MAX_LINE_LENGTH];

		//Call the convertToPostfix function (that you are to implement below main).
		int returnMessage = convertToPostfix(infixString,postfixString);
		//convertToPostfix should return an integer letting us know if the infix string was in a valid format.
		//If the format is valid (we returned 0), then we call the evalutaePostfix function (that you are to implement below), and print the result of the evalution.
		//If the format is not valid (we returned something other than 0), then we print the corresponding error message.
		switch(returnMessage)
		{

			case 0: //0 means the infix string had no errors.  Go ahead and evaluate the postfix string.
				printf("Postfix string: %s\n",postfixString);
				int result = evaluatePostfix(postfixString);
				printf("It evaluates to %d.\n",result);
				break;
			case 1:  //1 means the infix string is missing a left parenthesis.
				printf("WARNING: Missing left parenthesis.\n");
				break;
			case 2: //2 means the infix string is missing a right parenthesis.
				printf("WARNING: Missing right parenthesis.\n");
				break;
			case 3: // 3 means missing operator.
				printf("WARNING: Missing operator.\n");
				break;
			case 4: //4 means missing operand.
				printf("WARNING: Missing operand.\n");
				break;
			default:
				printf("WARNING: %d.\n", returnMessage);


		}


		printf("\n\n");
	}

	fclose(inputFile);

	return 0;
}


/*******
int convertToPostfix(char *infixString, char *postfixString)

Input: 
infixString is a character array of length <= MAX_LINE_LENGTH that contains an equation in infix format.
postfixString is a currently empty character array of length <= MAX_LINE_LENGTH that we should fill with a postfix representation of infixString.

Output:
We return an integer based on any errors found in infixString.
If there are no errors, return 0.
If there is a missing (, return 1.
If there is a missing ), return 2.
If there is a missing operator, return 3 (for extra credit).
If there is a missing operand, return 4 (for extra credit).
*********/
int convertToPostfix(char *infixString, char *postfixString)
{
	//variables to iterate our infix and postfix strings, and the declaration of a new stack	
	int i = 0;
	int j = 0;
	char in;
	Stack s = newStack(MAX_LINE_LENGTH);

	//char in will represent the char of infixString at i
	in = infixString[i];	

	//while the end of the string hasn't been reached
	while(in != '\0')
	{

		//if an operator
		if(in == '+' || in == '-' || in == '*' || in == '/')
		{
			//if stack is empty
			if(isEmpty(s) == 1)
			{
				Element n;
				n.operation = in;
				push(s, n);
			}
			//if stack is not empty
			else
			{

				//top is * or /
				if(in == '*' || in == '/')
				{
					//if same precedence or higher, pop top of stack and add to postfix
					Element n;
					while(isEmpty == 0)
					{
						n = topElement(s);

						if(n.operation == '*' || n.operation == '/')
						{
							n = pop(s);
							
							postfixString[j] = n.operation;
							j++;
						}


					}


					//push new element
					Element w;
					w.operation = in;
					push(s, w);
				}

				//if top is + or -
				if(in == '+' || in == '-')
				{
					//pop everything
					Element n;
					while(isEmpty(s) == 0)
					{
						n = topElement(s);
						//don't pop if left parenthesis is encountered
						if(n.operation != '(')
						{
							n = pop(s);

							postfixString[j] = n.operation;
							j++;
						}
						else
						{
							break;
						}
					}			

					Element w;
					w.operation = in;
					
					push(s, w);
				}
			}
		}
		
		//if a (, just push onto stack
		else if(in == '(')
		{
			Element n;
			n.operation = in;
			push(s, n);
		}

		//if a ), pop until ( is reached, and if none is found, return an error
		else if(in == ')')
		{
			Element n;
			n = topElement(s);

			//while the top element isn't (, pop until it is found
			while(n.operation != '(')
			{
				n = pop(s);
						
				if(isEmpty(s) == 1)
				{
					//free stack before returning an error
					freeStack(s);

					return 1;
				}
				postfixString[j] = n.operation;
				j++;
				//set n back to top element at the start of each iteration
				n = topElement(s);
			}

			//pop the (
			n = pop(s);

			//if top element after loop wasn't (, return an error, otherwise, pop next element and put on postfixString
			if(n.operation != '(')
			{
				//free stack before returning an error
				freeStack(s);
				
				return 1;
			}
						
		}
	
		//if a number
		else
		{
			//don't print newlines
			if(in == '\n')
			{
				break;
			}
			else
			{
				postfixString[j] = in;
				j++;
			}

		}
		
		//iterate the in at the end of each loop iteration
		i++;	
		in = infixString[i];

	}

	//pop any remaining elements on stack
	if(isEmpty(s) == 0)
	{
		Element n;
		//while the stack isn't empty pop, if a ( is found, return an error
		
		while(isEmpty(s) != 1)
		{
			n = topElement(s);
			
			if(n.operation == '(')
			{
				//free stack before returning an error
				freeStack(s);

				return 2;
			}

			else if(n.operation == '+' || n.operation == '-' || n.operation == '*' || n.operation == '/')
			{
				n = pop(s);

				postfixString[j] = n.operation;
				j++;
			}


		}
	}

	//tell postfix string to end
	postfixString[j] = '\0';


	//free the stack
	freeStack(s);	

	return 0;
}



/************
evaluatePostfix(char *postfixString)

Input:
postfixString is a string of length <= MAX_LINE_LENGTH that contains an equation in postfix representation.
If your convertToPostfix() function is correct, this string should be in a valid postfix format.

Output:
Return an integer representing what the postfix equation evaluated to.
************/
int evaluatePostfix(char *postfixString)
{

	/*create a new stack, an int to iterate the postfix, an int to get the total of the evaluation, and two elements to 
	hold operands/operators*/
	Stack s = newStack(MAX_LINE_LENGTH);
	int i = 0;
	Element w;
	Element x;
	int total;

	char in;
	in = postfixString[i];

	//while end of string hasn't been reached
	while(in != '\0')
	{

		//if char at i is a number, push it onto the stack
		if(isdigit(in))
		{

			Element n;
			n.operand = in - '0';
			push(s, n);
		}

		//else if its an operator, pop 2 numbers, convert them to ints and evaluate
		else if(in == '+' || in == '-' || in == '*' || in == '/')
		{

			w = pop(s);
			x = pop(s);
			
			
			//evaluate based on which operator in equals
			switch(in)
			{
				case '+':
					total = w.operand + x.operand;
					break;
				case '-':
					total = x.operand - w.operand;
					break;
				case '*':
					total = w.operand * x.operand;
					break;
				case '/':
					total = x.operand / w.operand;
					break;
			}

			//push total onto stack
			Element a;
			a.operand = total;
			push(s, a);
		}

		//iterate in on postfix
		i++;
		in = postfixString[i];
	}

	//free the stack;
	freeStack(s);

	//return the final calculated value	
	return total;

}
