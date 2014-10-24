Sume-Reimann
============

Sume Riemann project for highschool, maths


A project I made in the last year of highscool, written fully in C++ and using the SFML 2.1 library for 2D graphics and
the GUI.

The program it's supposed to take a function (provided as a string from the stdin), the two ends of an interval and 
another number representing the number of Riemann intervals. The output should be the graph of the function on ortogonal
XOY plane and the given number of rectangles represnting the Riemann intervals which approximate the area of the function.

I compiled it in code::blocks under Windows at the time, but now having gone to university I switched to a linux 
distribution for the time being and haven't gotten my head around building the project under this new environment.
External libraries are required to make this project work which I will add or point to when I will be able to solve the
issue mentioned above.

The code is partially commented and organized as good as I knew at the time. The coding standard lacks in spacing before
and after most operators (for example: "a+b" instead of "a + b") because of a habit I developed from participating in
algorithmic competitions (the habbit was dropped in the meantime).
TO DO: Run a program to format the code to respect a coding standard.

The program has flaws like, not drawing the graph for some high? number of functions, sometimes one of the divisions gets
bugged, the colours used in the graph screen could be improved, zooming in and out is not smooth enough.

Also the files eval.c and eval.h were written by a classmate( we were supposed to work in groups ), but everything else
is my concept.

The program is more of a proof of concept and practising than a well behaving app.
All this being said, take everything as you will and Enjoy Yourself.
