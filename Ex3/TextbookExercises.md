# Part 1 | Exercises from Chapter 2

## Ex 2.1
- int: an integer data type of at least 16 bits, usually 32 bits.
- long: target type will have a width of at least 32 bits
- long long: type will have a width of at least 64 bits
- short: type will have a width of at least 16 bits
- float: single precision floating point number (32 bits)
- double: double precision floating point number (64 bits)
<br>

## Ex 2.2
I would use a double for both the principal and payment because using a double will give us better precision for decimal numbers, which is especially important in uses for currency.
<br>

## Ex 2.3
32 <br>
4294967264 (because it is an unsigned type) <br>
32 <br>
-32 <br>
0 <br>
0
<br>

## Ex 2.10
global_str = empty string "" <br>
global_int = 0 <br>
local_int = garbage value <br>
local_str = empty string "" <br>
<br>

## Ex 2.12
Invalid:<br>
- int double = 3.14;
- int catch-22;
- int 1_or_2 = 1;
<br>

## Ex 2.13
j = 100
<br>

## Ex 2.14
The code is valid, the for statement has a local integer name i. <br>
The output is: 100 45
<br>

## Ex 2.17
Output: 10 10
<br>

## Ex 2.27
- (a) is illegal because you cannot define a variable to be a regular integer and another to be a reference on the same line.
- (b) is legal even though int* and const is switched
- (c) is legal to have a const int and a const reference on same line
- (d) is legal despite making use of two const attributes
- (e) is legal, pointer declaration
- (f) is illegal, & modifier does not make sense next to const
- (g) is legal, const int and reference
<br>

## Ex 2.28
- (a) is illegal, const is suppored to be an attribute to a type
- (b) is illegal, cannot have a regular int and const int on same line
- (c) is legal, a const int and const int reference can be declared on same line
- (d) is illegal, cannot have anything after star modifier but the name of the variable
- (e) is legal, pointer does not need to initialized
<br>
