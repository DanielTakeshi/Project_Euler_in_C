This will contain my solutions to Project Euler questions using C or C++.
Ideally, I'll be able to benchmark some of these solutions with top-performing
Java and Python versions. The numbers are listed with 3 digits, so there's
zero-padding to make it easier to list numbers consecutively. It's really
annoying otherwise!

Note, to RUN a C program, here's what we can do. Write the C file which will
have the .c extension, e.g. `pe001.c`, and then we run the following:

```
clang pe001.c ; ./a.out 
```

The first command creates the executable file, `a.out`, which we then run using
`./a.out`.

An alternative to clang is using `gcc`, but `clang` is the default C (and C++)
compiler for Macs.

By the way, when I finish programs, I should record the output from the time
command, just to make sure I'm seeing solutions on the order of 1 second or
less. So do this:

```
clang pe001.c ; time ./a.out 
```
