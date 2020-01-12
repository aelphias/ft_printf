Syntax
The syntax for a format placeholder is

%[parameter][flags][width][.precision][length]type
Спецификатор формата имеет вид:

%[флаги][ширина][.точность][размер]тип
A format specifier follows this prototype: [see compatibility note below]
%[flags][width][.precision][length]specifier

specifier	Output	Example
d or i	Signed decimal integer	392
u	Unsigned decimal integer	7235
o	Unsigned octal	610
x	Unsigned hexadecimal integer	7fa
X	Unsigned hexadecimal integer (uppercase)	7FA
f	Decimal floating point, lowercase	392.65
F	Decimal floating point, uppercase	392.65
e	Scientific notation (mantissa/exponent), lowercase	3.9265e+2
E	Scientific notation (mantissa/exponent), uppercase	3.9265E+2
g	Use the shortest representation: %e or %f	392.65
G	Use the shortest representation: %E or %F	392.65
a	Hexadecimal floating point, lowercase	-0xc.90fep-2
A	Hexadecimal floating point, uppercase	-0XC.90FEP-2
c	Character	a
s	String of characters	sample
p	Pointer address	b8000000
n	Nothing printed.
The corresponding argument must be a pointer to a signed int.
The number of characters written so far is stored in the pointed location.	
%	A % followed by another % character will write a single % to the stream.	%


B.7 Variable Argument Lists: <stdarg.h>
The header <stdarg.h> provides facilities for stepping through a list of function arguments of
unknown number and type.
Suppose lastarg is the last named parameter of a function f with a variable number of
arguments. Then declare within f a variable of type va_list that will point to each argument
in turn:
 va_list ap;
ap must be initialized once with the macro va_start before any unnamed argument is
accessed:
va_start(va_list ap, lastarg);
Thereafter, each execution of the macro va_arg will produce a value that has the type and
value of the next unnamed argument, and will also modify ap so the next use of va_arg returns
the next argument:
type va_arg(va_list ap, type);
The macro
 void va_end(va_list ap);
must be called once after the arguments have been processed but before f is exited. 
--
conversion specifications introduced by a ‘%’
an integer argument as an unsigned value in octal, decimal, or hexadecimal radix (‘%o’, ‘%u’, or ‘%x’, respectively); or as a character value (‘%c’).
---
You have to manage the following conversions: csp
• You have to manage the following conversions: diouxX with the following flags: hh, h,landll.
• You have to manage the following conversion: f with the following flags: l and L.
--l
length modificators
hh

• You must manage %%
• You must manage the flags #0-+ and space
• You must manage the minimum field-width
• You must manage the precision
https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html
https://ru.wikipedia.org/wiki/Printf

