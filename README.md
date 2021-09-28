# Matrix Math Implementation
Contributor: Spenser Fong
## Overview
A command-line program that solves linear systems using echelong forms. It allows users to find matrix echelon forms, RREFs, and more. It currently only supports finding echelon forms and RREFs. This project was inspired by coursework in linear algebra, analog signal processing, and electronics.

REQUIRED FILES: matrix.h/cpp, main.cpp, Makefile

To run the program, do **make main** to compile, then do **./main** to run.

**TODO**
I currently plan on doing two things:
  1) Implementing determinants, inverse matrices, decomps (LU, QR, etc.)
  2) Executing matrix functions will not affect the matrix stored, and will therefore let users to call other matrix functions on the current matrix before scrapping the matrix.
