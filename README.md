# rpn-calculator
A basic reverse polish notation calculator. It is based on GNU dc with a few
extra operations added that I use quite often.

# Features
* Basic arithmetic operations (add, subtract, multiply, divide, and exponent)
* Square root and logarithms (both natural and base 10)
* Handles both integers and floating point numbers

# Planned Features
* Logarithms (both natural log and base 10)
* Exponentials (e^x)
* Trigonometric functions
* Support for arbitrary precision
* Registers

# Usage
The program reads from standard input. Each input is entered on its own line. To compile, simply use something like:
`gcc rpn.c -o rpn`

## Printing and Control Commands
* q &nbsp; &nbsp; Exits the program.
* p  &nbsp; &nbsp;Prints the number at the top of the stack followed by a newline. The number is not popped from the stack.
* f &nbsp; &nbsp; Prints the entire stack. Each number is followed by a newline. None of the numbers are popped from the stack.
* P &nbsp; &nbsp; Pops the number at the top of the stack and prints it with a newline.

## Arithmetic Commands
* '+' &nbsp; &nbsp; Pops the two numbers at the top of the stack and stores the sum.
* '-' &nbsp; &nbsp; Pops the two numbers at the top of the stack. The first number is subtracted from the second number and the difference is stored.
* '*' &nbsp; &nbsp; Pops the two numbers at the top of the stack and stores the product.
* '/' &nbsp; &nbsp; Pops the two numbers at the top of the stack. The first number is the divisor and the second number is the dividend, so the second number will be divided by the first number.
* '^' &nbsp; &nbsp; Pops two numbers at the top of the stack. The first number will be the exponent to which the second number will be raised.
* 'l' &nbsp; &nbsp; Pops the number at the top of the stack and stores its natural logarithm.
* 'L' &nbsp; &nbsp; Pops the number at the top of the stack and stores its base 10 logarithm.

