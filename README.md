# Programming Lab 2 - IPC

## Learning Outcomes

By the end of this activity, a student should be able to:

1. Gain experience in C programming
2. Use system calls to create child processes
3. Use shared memory to enable communication between child and parent processes
4. Implement a makefile to compile and link your program

## Introduction

This lab will require you to implement three C functions, `ipc_create()`, `elapsed_time()`, and `main()` and a Makefile. the `ipc_create()` function creates a shared memory object called <span style="font-family:monospace;color:red;border:1px solid red; border-radius: 5px;">lab2</span> and returns a pointer to a memory map of the shared object.  The function `elapsed_time()` calculates the diferrence between the initial time before invoking the `execvp()` function and after the child completes.

## Files

This lab must be forked from the repo at

```
https://github.com/mrasamny/csci-320-lab2
```

Click the <span style="background-color:#444444;color:white;">Fork</span> button to fork a copy of the repo to your GitHub account and **clone** your repo on **your VM**.  You should commit your code as you work on your program and push it systematically to your repo.  **Your finalized product should be on your GitHub repo**.  Submissions that have only one push will not be graded!


Included in the repo are,

- **lab2.h** - definitions relevant to this programming project. DO NOT MODIFY.
- **time.c** - this is where you implement `elapsed_time()` functions.
- **ipc.c**  - this is where you implement `ipc_open()` and `ipc_read()`
- **main.c** - contains the main function.  
- **README.md** - this file.

## Time It!

You will write a C program that will result in an executable called <span style="font-family:monosapce;font-weight:bold;color:blue;">time</span> that determines the amount of time necessary to run a command from the command line.  This program will be run as <span style="font-family:monosapce;font-weight:bold;color:blue;">./time &lt;command&gt;</span> and will report the amount of elapsed time to run the specified command. This will involve using fork() and exec() functions, as well as the gettimeofday() function to determine the elapsed time. It will also require the use of an IPC mechanism.  In this case, a shared memory object.

The general strategy is to fork a child process that will execute the specified command. However, before the child executes the command, it will record a timestamp of the current time (which we term "starting time"). The parent process will wait for the child process to terminate. Once the child terminates, the parent will record the current timestamp for the ending time. The difference between the starting and ending times represents the elapsed time to execute the command. 

The example output below reports the amount of time to run the command `ls`:

```
./time ls
time.c
time
 
Elapsed time: 0.25422
```
As the parent and child are separate processes, they will need to arrange how the starting time will be shared between them. 

The program will have the child process write the starting time to a region of shared memory before it calls exec(). After the child process terminates, the parent will read the starting time from shared memory. Refer to Section POSIX shared memory for details using POSIX shared memory. In that section, there are separate programs for the producer and consumer.  Also, look at the example code provided for class demonstration.  As the solution to this problem requires implementation in `main()`, the region of shared memory can be established before the child process is forked, allowing both the parent and child processes access to the region of shared memory.  This means that the shared memory is created prior to forking the child process.

Each function requiring implmenetation contains a set of TODOs that when completed, should result in a working executable.  Replace each TODO with the appropriate line(s) of code.

You will use the `gettimeofday()` function to record the current timestamp. This function is passed a pointer to a `struct timeval` object, which contains two members: `tv_sec` and `t_usec`. These represent the number of elapsed seconds and microseconds since January 1, 1970 (known as the UNIX EPOCH). The following code sample illustrates how this function can be used:

```
struct timeval current;
 
gettimeofday(&current,NULL);
 
// current.tv_sec represents seconds
// current.tv_usec represents microseconds
```
For IPC between the child and parent processes, the contents of the shared memory pointer can be assigned the struct timeval representing the starting time, or you can use the `memcpy()` function from the standard library.

## Requirements

You are required to complete the following:

1. Implement the two functions in the **ipc.c** file.  Each function is provided with commented TODOs that help you implement the functions.
2. Implement the `elapsed_time`function in **time.c**.
3. Implement the `main` function in **main.c** using the TODOs to guide you in completing it.
2. Write a makefile that will compile and link your program into an executable called <span style="color:purple;font-family:monospace;font-style:italic;font-size:1.3em;">time</span>.

## Program Specifications

Your program must perform the following:

1. Use a shared memory object to communicate the start time to the parent process.
2. Use fork to start a child process that will use the `execvp` system call to execute the command.

## Submission

Your are to submit your GitHub repo link on Blackboard.  Your repo should show no submissions after the submissions deadline.  Any submissions after the deadline will result in an immediate zero (0) on the assignment.  If your **program does not compile, you will receive a zero (0) on the assignment**.  A rubric is provided with the assignment on Blackboard.

