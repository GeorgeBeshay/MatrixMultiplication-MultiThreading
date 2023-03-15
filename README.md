# Matrix Multiplication
`Performing the matrices multiplication using 3 different approaches, utilizing the ULTs from pthreads library.`

Presenting 3 different approaches for performing the matrix multiplication operation while utilizing the ULTs, observing the performance enhancement in each of the following cases:

* Spawning a single thread per the whole result matrix.
* Spawning a single thread per row of the result matrix.
* Spawning a single thread per element of the result matrix.

---

## Table of Contents

- [Introduction](#introduction)
- [Lab Objectives](#lab-objectives)
- [Installation](#installation)
- [Usage](#usage)
- [Problem Statement](#problem-statement)

---

## Introduction

This lab was developed as a part of the academic course ***CSE x61: Operating Systems*** that is being studied on the 6th semester (spring 2023) in the department of Computer and Systems Engieering, Alexandria University.

---

## Lab Objectives

* Deeply understand the processes & ULTs, and how are they managed / manipulated, and how can they affect a program performance.
* Getting familiar with threads programming and [Pthread library](https://hpc-tutorials.llnl.gov/posix/)

---

## Installation

Steps to install and run this project on your local machine.

* Download the ZIP folder: <br>
`https://github.com/GeorgeBeshay/MatrixMultiplication-MultiThreading/archive/refs/heads/main.zip`
* Open the src directory using you favourite IDE.
* Place the test cases on the pre-defined format of the matrix input, follow the CLI procedure to run the application that can be found in the problem statement repository.
* Open the src directory from the terminal run the following commands:
 * `make`
 * `./matMultp a b c`
 * replace a, b and c with the input and output matices files.

---

## Usage

- The program goal is to perform a matrix multiplication between matrices A, B and store the result in the output matrix C using the 3 different approaches mentioned above.
- The input (matrices sizes / elements) are scanned from an input files that attached with in the same src code folder inside a directory named *IO*.


---

## Problem Statement
- For more details about the lab and the problem, kindly refer to the lab problem definition repository that can be found at the course TA github.
 - [Repo Link](https://github.com/SajedHassan/Operating-Systems/tree/master/Labs/lab2)

---
