# CMA
## Overview
CMA, acronym of Completeness Metric Analyzer, is a command-line tool for runtime monitoring of
timing and State Machine status. This tracing mechanisms uses software level acquisition of hardware timing and State Machine information, outputs operations are the tracing data of the processor such as the function timing execution combined with formal description of the system behaviour through the State Machine status and input operations. The trace protocol provides a real-time trace capability for the functionality.
## How it works
When an event requires the acquisition of system-related information, the CMA tool operates a combination of three macro operations, both composed by a sequence of operations, as follow:
* data acquisition: in this operation the tool gets information about the system run, such as execution time, state machine status, etc
*	data elaboration: previously acquired data are now formatted in an output trace and queued
*	log generation: the queued traces are written to a log file and the queue is cleaned
## System requirement
The tool has been created to be a logging tool for external board.
Whit this purpose there are two different modules that have different requirments.
The first module CMA.c is intent to be add to a board that runs C code and is able to write on serial.
The CMA tool actually is built for a specific MegaM@rt2 Short Range Communication case study. The hardware target used is a Decawave EVB1000 board with STLINK-V2 debugger. Eclipse was used to run the source code.
The second module CMALogger.py is a logger that reads the serial port and generates a log file.
CMALogger.py have to run into a python3 environment and the pyserial module is required.
## Installation Instructions
In order to install the CMA tool, just import the C files into the project.
## Usage description
In the source code, after the struct **trace** has been populated, call the **printTrace()** function. 
When execute the program, run the Python script from terminal to capture and write the traces into the log file.
