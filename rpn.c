/* Implement a reverse polish notation calculator. */
#include <stdio.h>
#include <string.h>
#include <math.h>

enum
{
	STACK_LENGTH = 256,
	NUMBER_SIZE = 1000,
	REGISTERS = 10
};

/* Add the two numbers at the top of the stack and store the result at the top of the stack */
void
addNums (double *stack, int *stackPointer)
{
	double sum;
	int stackPtr = *stackPointer;

	sum = stack[stackPtr - 1] + stack[stackPtr];

	/* Clear the top of the stack and decrement the stack pointer */
	stack[stackPtr] = 0x00;
	stackPtr--;

	/* Now store the sum at the new top of the stack */
	stack[stackPtr] = sum;
	*stackPointer = stackPtr;
}

/* Subtract the two numbers at the top of the stack */
void
subNums (double *stack, int *stackPointer)
{
	double diff;
	int stackPtr = *stackPointer;

	diff = stack[stackPtr - 1] - stack[stackPtr];

	/* Clear the top of the stack and decrement the stack pointer */
	stack[stackPtr] = 0x00;
	stackPtr--;

	/* Now store the sum at the new top of the stack */
	stack[stackPtr] = diff;
	*stackPointer = stackPtr;
}

/* Multiply the two numbers at the top of the stack */
void
multNums (double *stack, int *stackPointer)
{
	double prod;
	int stackPtr = *stackPointer;

	prod = stack[stackPtr - 1] * stack[stackPtr];

	/* Clear the top of the stack and decrement the stack pointer */
	stack[stackPtr] = 0x00;
	stackPtr--;

	/* Now store the sum at the new top of the stack */
	stack[stackPtr] = prod;
	*stackPointer = stackPtr;
}

/* Divide the two numbers at the top of the stack */
void
divNums (double *stack, int *stackPointer)
{
	double quot;
	int stackPtr = *stackPointer;

	if (stack[stackPtr] == 0) {
		fprintf (stderr, "ERROR:  Divide by zero error.\n");
		return;
	}

	quot = stack[stackPtr - 1] / stack[stackPtr];

	/* Clear the top of the stack and decrement the stack pointer */
	stack[stackPtr] = 0x00;
	stackPtr--;

	/* Now store the sum at the new top of the stack */
	stack[stackPtr] = quot;
	*stackPointer = stackPtr;
}

/* Use the number at the top of the stack as the exponent and the next number
 * as the base */
void
expNums (double *stack, int *stackPointer)
{
	double res;
	int stackPtr = *stackPointer;

	res = pow (stack[stackPtr - 1], stack[stackPtr]);

	/* Clear the top of the stack and decrement the stack pointer */
	stack[stackPtr] = 0x00;
	stackPtr--;

	/* Now store the sum at the new top of the stack */
	stack[stackPtr] = res;
	*stackPointer = stackPtr;
}
 
/* Print the stack from top to bottom */
void
printFullStack (double *stack, int stackPtr)
{
	int i;

	for (i = stackPtr; i >= 0; i--) {
		printf ("%lf\n", stack[i]);
	}
}

int
main ()
{
	unsigned char number[NUMBER_SIZE]; /* The number is entered as a string */
	unsigned char *indexPtr; /* Stores the returned pointer from strchr */
	int index; /* Index of the decimal point in the number */
	double fullNumber; /* Number after parsing from string */
	double stack[STACK_LENGTH] = {0x00}; /* The stack */
	double registers[REGISTERS] = {0x00}; /* The registers */
	int regNum; /* The register being accessed */
	int stackPtr = -1; /* Holds the index to the number at the top of the stack */
	int length; /* The number of digits in the number that was just entered */
	int i; /* Loop counter */

	while (number[0] != 0x71) {
		memset (number, 0x00, NUMBER_SIZE);

		/* Read the number from standard input */
		fgets (number, NUMBER_SIZE, stdin);

		/* Check if any control characters were entered */
		/* If the letter 'q' was entered then exit */
		if (number[0] == 0x71) {
			break;
		}

		/* If a '+' was entered then add the top two numbers on the stack */
		else if (number[0] == 0x2b) {
			if (stackPtr <= 0) {
				fprintf (stderr, "ERROR:  not enough numbers on the stack.\n");
			}
			else {
/*				fullNumber = stack[stackPtr - 1] + stack[stackPtr];
				stack[stackPtr] = 0x00;
				stack[stackPtr - 1] = fullNumber;
				stackPtr--; */
				addNums (stack, &stackPtr);
			}

			continue;
		}

		/* If a '-' was entered then subtract the top two numbers on the stack */
		else if (number[0] == 0x2d) {
			if (stackPtr <= 0) {
				fprintf (stderr, "ERROR:  not enough numbers on the stack.\n");
			}
			else {
/*				fullNumber = stack[stackPtr - 1] - stack[stackPtr];
				stack[stackPtr] = 0x00;
				stack[stackPtr - 1] = fullNumber;
				stackPtr--; */

				subNums (stack, &stackPtr);
			}

			continue;
		}

		/* If a '*' was entered then multiply the top two numbers on the stack */
		else if (number[0] == 0x2a) {
			if (stackPtr <= 0) {
				fprintf (stderr, "ERROR:  not enough numbers on the stack.\n");
			}
			else {
/*				fullNumber = stack[stackPtr - 1] * stack[stackPtr];
				stack[stackPtr] = 0x00;
				stack[stackPtr - 1] = fullNumber;
				stackPtr--; */

				multNums (stack, &stackPtr);
			}

			continue;
		}

		/* If a '/' was entered then divide the top two numbers on the stack */
		else if (number[0] == 0x2f) {
			if (stackPtr <= 0) {
				fprintf (stderr, "ERROR:  not enough numbers on the stack.\n");
			}
			else {
/*				fullNumber = stack[stackPtr - 1] / stack[stackPtr];
				stack[stackPtr] = 0x00;
				stack[stackPtr - 1] = fullNumber;
				stackPtr--; */

				divNums (stack, &stackPtr);
			}

			continue;
		}

		/* If a '^' was entered then use the second number on the stack as the base
		 * and raise it to the top number on the stack */
		else if (number[0] == 0x5e) {
			if (stackPtr <= 0) {
				fprintf (stderr, "ERROR:  not enough numbers on the stack.\n");
			}
			else {
/*				fullNumber = pow (stack[stackPtr - 1], stack[stackPtr]);
				stack[stackPtr] = 0x00;
				stack[stackPtr - 1] = fullNumber;
				stackPtr--; */

				expNums (stack, &stackPtr);
			}

			continue;
		}

		/* If a 'l' was entered then calculate the natural log of the number
		 * at the top of the stack */
		else if (number[0] == 0x6c) {
			if (stackPtr == -1) {
				fprintf (stderr, "ERROR:  stack is empty.\n");
			}
			else {
				stack[stackPtr] = log (stack[stackPtr]);
			}
		}

		/* If a 'L' was entered then calculate the base 10 logarithm of the
		 * number at the top of the stack */
		else if (number[0] == 0x4c) {
			if (stackPtr == -1) {
				fprintf (stderr, "ERROR:  stack is empty.\n");
			}
			else {
				stack[stackPtr] = log10 (stack[stackPtr]);
			}
		}

		/* If a 'f' was entered then print the entire stack */
		else if (number[0] == 0x66) {
			if (stackPtr == -1) {
				fprintf (stderr, "Stack is empty.\n");
			}
			else {
				printFullStack (stack, stackPtr);
			}

			continue;
		}

		/* If a 'p' was entered then print the number at the top of the stack */
		else if (number[0] == 0x70) {
			if (stackPtr == -1) {
				fprintf (stderr, "Stack is empty.\n");
			}
			else {
				printf ("%lf\n", stack[stackPtr]);
			}

			continue;
		}

		/* If a 'c' was entered then clear the stack and reset the stack pointer */
		else if (number[0] == 0x63) {
			memset (stack, 0x00, STACK_LENGTH);
			stackPtr = -1;
			continue;
		}

		/* If a 'P' was entered then pop the number at the top of the stack */
		else if (number[0] == 0x50) {
			stack[stackPtr] = 0x00;
			stackPtr--;
		}

		/* If 'sX' was entered then save the number at the top of the
		 * stack in register X. If another number is already saved
		 * in the register then overwrite it. */
		else if (number[0] == 0x73) {
			if (stackPtr == -1) {
				fprintf (stderr, "ERROR:  stack empty.\n");
				continue;
			}

			else {
				if (number[1] >= 0x30 && number[1] <= 0x39) {
					/* Convert the number from ascii to decimal */
					regNum = number[1] - 0x30;

					/* Pop the number from the top of the stack
					 * and store it in the register */
					registers[regNum] = stack[stackPtr];
					stack[stackPtr] = 0x00;
					stackPtr--;
				}
			}

			continue;
		}

		/* if 'rX' was entered then recall the number from register X
		 * and push it to the stack. The registers is then cleared. */
		else if (number[0] == 0x72) {
			regNum = number[1] - 0x30;

			if (registers[regNum] == 0x00) {
				fprintf (stderr, "Register %d is empty.\n", regNum);
			}
			else {
				stackPtr++;
				stack[stackPtr] = registers[regNum];
				registers[regNum] = 0x00;
			}

			continue;
		}

		/* If 'RX' is entered then recall the number from register X
		 * and push it to the stack. The value in the register is preserved. */
		else if (number[0] == 0x52) {
			regNum = number[1] - 0x30;

			if (registers[regNum] == 0x00) {
				fprintf (stderr, "Register %d is empty.\n", regNum);
			}
			else {
				stackPtr++;
				stack[stackPtr] = registers[regNum];
			}

			continue;
		}

		/* Remove the trailing newline from the number string */
		indexPtr = strchr (number, 0x0a);
		*indexPtr = 0x00;

		/* Parse the number from a string of bytes to double precision.
		 * Start by finding the index of the decimal point */
		indexPtr = strchr (number, 0x2e);

		/* If strchr returns a null pointer then the number is an integer */
		if (indexPtr == 0x00) {
			/* Calculate the length of the number */
			length = strlen (number);

			/* Reset the number to zero */
			fullNumber = 0;

			/* If an underscore was entered then the number should be negative */
			if (number[0] == 0x5f) {
				/* Now loop through the digits and combine them into one number */
				for (i = length - 1; i >= 1; i--) {
					/* Convert the digit from ascii to decimal */
					number[i] -= 0x30;
					fullNumber += (double)number[i] * pow (10, (length - 1) - i);
				}

				fullNumber *= -1;
			}

			/* Otherwise the number is positive */
			else {
				/* Loop through the digits and combine them into one number */
				for (i = length - 1; i >= 0; i--) {
					/* Convert each digit from ascii to decimal */
					number[i] -= 0x30;
					fullNumber += (double)number[i] * pow (10, (length - 1) - i);
				}
			}

			/* Push the number onto the stack and increment the stack pointer */
			stackPtr++;
			stack[stackPtr] = fullNumber;
		}

		/* Otherwise the number is a floating point number */
		else {
			/* Get the location of the decimal point
			 * indexPtr is a pointer (holds the address to)
			 * the decimal point and number is a pointer
			 * to the leading digit in the number */
			index = (int)(indexPtr - number);

			/* Calculate the number of digits in the number */
			length = strlen (number);

			/* Reset the number to zero */
			fullNumber = 0;

			/* If an underscore was entered then the number should be negative */
			if (number[0] == 0x5f) {
				/* First loop through the integer part of the number
				 * That is, the part of the number to the left of the decimal point */
				for (i = index - 1; i >= 1; i--) {
					/* Convert each digit from ascii to decimal */
					number[i] -= 0x30;
					fullNumber += (double)number[i] * pow (10, (index - 1) - i);
				}
	
				/* Now loop through the decimal part of the number */
				for (i = index + 1; i < length; i++) {
					/* Convert each digit from ascii to decimal */
					number[i] -= 0x30;
					fullNumber += (double)number[i] / pow (10, index - i);
				}
	
				fullNumber *= -1;
			}

			/* Otherwise the number is positive */
			else {
				/* First loop through the integer part of the number
				 * That is, the part of the number to the left of the decimal point */
				for (i = index - 1; i >= 0; i--) {
					/* Convert each digit from ascii to decimal */
					number[i] -= 0x30;
					fullNumber += (double)number[i] * pow (10, (index - 1) - i);
				}
	
				/* Now loop through the decimal part of the number */
				for (i = index + 1; i < length; i++) {
					/* Convert each digit from ascii to decimal */
					number[i] -= 0x30;
					fullNumber += (double)number[i] / pow (10, i - index);
				}
			}

			/* Push the number onto the stack and increment the stack pointer */
			stackPtr++;
			stack[stackPtr] = fullNumber;
		}
	}

	return 0;
}
