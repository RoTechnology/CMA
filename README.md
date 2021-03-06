# CMA
## Overview
CMA, acronym of Completeness Metric Analyzer, is a command-line tool for runtime monitoring of
timing and State Machine status. This tracing mechanisms uses software level acquisition of hardware timing and State Machine information, outputs operations are the tracing data of the processor such as the function timing execution combined with formal description of the system behaviour through the State Machine status and input operations. The trace protocol provides a real-time trace capability for the functionality.

The CMA tool actually is built for a specific [MegaM@rt2](https://megamart2-ecsel.eu/) Short Range Communication case study, in collaboration with **Tekne**, **Intecs** and **UnivAq**.
## How it works
When an event requires the acquisition of system-related information, the CMA tool operates a combination of three macro operations, both composed by a sequence of operations, as follow:
* data acquisition: in this operation the tool gets information about the system run, such as execution time, state machine status, etc
*	data elaboration: previously acquired data are now formatted in an output trace and queued
*	log generation: the queued traces are written to a log file and the queue is cleaned

The log file contains a traces which have the following structure:

\<timestamp\> \<eventId\> \<instance_name\>\_\<port_name_providing_the_operation\>\_\<operation_name\>
  
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
In order to install the CMA tool, for the C module:
1. import the C files into the project containing the board sources
2. include the header file where needed.

Instead regarding the Python module:
   1. Download and Install python3 from the official page https://www.python.org/.
   2. Install **pyserial** using pip command into the terminal: **pip install pyserial** .
   
## Usage description
To correctly use the library follow this steps:

1. Include *cma.h* file into the class you want to log.
2. Populate the **tracestruct**. Pay attention the tracestruct is composed by the filed described above.
  You can add or remove fields in order to log different parameters but then you have to modify the **printTrace()**
  function in *cma.c* file.
3. After the tracestruct has been populated properly, call the **printTrace()** function. 
4. Compile and run your code into the board. 
5. Run the *cmaLogger.py* to capture and write the traces into the log file.
   To do that open the terminal, navigate to the folder where you download the file and launch this command:
   python *cmaLogger.py*.
   
   **! The default serial port in the script is "COM4". Please make sure that is the same port on which your board is writing otherwise open cmaLogger.py with an editor and modify the port variable into the file !**

6. Done! The log file is produced into the same folder of *cmaLogger.py* file.
