Syntax
The syntax for a format placeholder is

%[parameter][flags][width][.precision][length]type
Спецификатор формата имеет вид:

%[флаги][ширина][.точность][размер]тип


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