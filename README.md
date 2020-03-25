# CMA
## Overview
CMA, acronym of Completeness Metric Analyzer, is a command-line tool for runtime monitoring of
timing and State Machine status. This tracing mechanisms uses software level acquisition of hardware timing and State Machine information, outputs operations are the tracing data of the processor such as the function timing execution combined with formal description of the system behaviour through the State Machine status and input operations. The trace protocol provides a real-time trace capability for the functionality.

The CMA tool actually is built for a specific MegaM@rt2 Short Range Communication case study.
## How it works
When an event requires the acquisition of system-related information, the CMA tool operates a combination of three macro operations, both composed by a sequence of operations, as follow:
* data acquisition: in this operation the tool gets information about the system run, such as execution time, state machine status, etc
*	data elaboration: previously acquired data are now formatted in an output trace and queued
*	log generation: the queued traces are written to a log file and the queue is cleaned

The log file contains a traces which have the following structure:

- timestamp = system time in μs
- eventId = 0 (running), 1 (ready), 2 (blocked), 3 (sleep), 4 (wakeup)
- instance_name = according to the device
- port_name_providing_the_operation = input/output node block port
- operation_name = status of State Machine

## System requirement
The tool has been created to be a logging tool for external board.
With this purpose there are two different modules that have different requirements, a C module and a Python module.
The first module is intent to be add to a board that runs C code and is able to write on serial.
The hardware target used is a Decawave EVB1000 board with STLINK-V2 debugger. Eclipse and Python were used to run the source codes.

The second module is a logger that reads the serial port and generates a log file. For this module, have to run into a python3 environment and the pyserial module is required.
## Installation Instructions
In order to install the CMA tool, for the C module import the C files into the project containing the board sources and include the header file where needed.

Instead regarding the Python module, install python and pyserial to enable the logger to operate.
## Usage description
In the source code, after the struct **trace** has been populated properly, call the **printTrace()** function. 
When execute the program, run the Python script from terminal to capture and write the traces into the log file. Make sure that the **serial** port in python script has been configured correctly.
