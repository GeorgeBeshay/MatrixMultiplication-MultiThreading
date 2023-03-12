# Matrix multiplication using multi threading

Presenting 3 different approaches for performing the matrix multiplication operation while utlizing the OS threads, observing the performance enhancement in each of the following cases:

* Spawning a single thread per the whole result matrix.
* Spawning a single thread per row of the whole result matrix.
* Spawning a single thread per element of the whole result matrix.

---

## Table of Contents

- [Introduction](#introduction)
- [Lab Objectives](#lab-objectives)
- [Installation](#installation)
- [Usage](#usage)
- [Problem Statement](#problem-statement)

---

## Introduction

This lab was developed as a part of the academic course [CSE x61: Operating Systems] that is being studied on the 6th semester in the department of Computer and Systems Engieering, Alexandria University.

---

## Lab Objectives

* Deeply understand the processes & threads, and how are they managed / manipulated by the OS, and how can the affect a program performance.
* Getting familiar with threads programming and [Pthread library](https://hpc-tutorials.llnl.gov/posix/)

---

## Installation

Steps to install and run this project on your local machine.

* npm install <br>
* npm start
---

## Usage

- The program goal is to perform a matrix multiplication between matrices A, B and store the result in the output matrix C using the 3 different approaches mentioned above.
- The input (matrices sizes / elements) are scanned from an input files that attached with in the same src code directory.


---

## Problem Statement
- For more details about the lab and the problem, kindly refer to the Lab Definition Repository that can be found at the course TA github.
- - [Repo Link](https://github.com/SajedHassan/Operating-Systems/tree/master/Labs/lab2)

