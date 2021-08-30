# rpn-calculator
A basic reverse polish notation calculator. It is similar to GNU dc with a few
extra operations added that I use quite often.

# Features
* Basic arithmetic operations (add, subtract, multiply, divide, and exponent)
* Logarithms (both natural and base 10)
* Exponentials (e^x)
* Square root
* Handles both integers and floating point numbers
* Ten Registers, numbered 0-9
* Only depends on the C standard math library

# Planned Features
* Trigonometric functions
* Support for arbitrary precision

# Usage
The program reads from standard input. Each input is entered on its own line. To compile, simply use something like:
`gcc rpn.c -o rpn -lm`

Alternatively, the latest release can be downloaded to use as a command line utility. To do this, download the latest tarball
and unpack it to your desired directory. The following commands should configure and compile it.
```
./configure
make
sudo make install
```

It can then be run by typing `rpn` into a terminal.

Note that this has only been tested under Debian Linux, so other OS's might have different requirements to build.

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
* 'v' &nbsp; &nbsp; Pops the number at the top of the stack, calculates the square root, and stores the result.
* 'e' &nbsp; &nbsp; Pops the number at the top of the stack, uses it as the exponent of the natural base, and stores the result.

## Register commands
* 'sX' &nbsp; &nbsp; Pops the number at the top of the stack and saves it in register X.
* 'rX' &nbsp; &nbsp; Recalls the number from register X and pushes it to the stack. The register is then cleared.
* 'RX' &nbsp; &nbsp; Recalls the number from register X and pushes it to the stack. The value in the register is preserved.
