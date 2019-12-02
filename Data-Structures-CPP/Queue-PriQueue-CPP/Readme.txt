*******************************************************
*  Name      :  Tobby Lie      
*  Student ID:  103385744      
*  Class     :  CSCI 2421           
*  HW#       :  7               
*  Due Date  :  October 7, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program “Queues” will utilize the queue STL and the 
priority queue STL in order to implement a bank simulation.
Will run a simulation with a single teller and another
with three tellers.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions.

Name: simulation.h
   Contains the definition for the simulation functions. 

Name: simulation.cpp
   Defines and implements the simulation functions
   Uses queue, priority queue and structs to develop a
   bank simulation

Name: threeTellerSimulation.h
   Contains the definition for the threeTellerSimulation functions. 

Name: threeTellerSimulation.cpp
   Defines and implements the threeTellerSimulation functions
   Uses queue, priority queue and structs to develop a
   bank simulation with three tellers


*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on Xcode.  It was 
   compiled, run, and tested on gcc 4.8 on csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip LieHW7.zip

   Now you should see a directory named LieHW7 with the files:
        main.cpp
        Input.txt
	simulation.h
	simulation.cpp
	threeTellerSimulation.h
	threeTellerSimulation.cpp
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieHW7

    Compile the program by:
    % make

3. Run the program by:
   % ./hw7

4. Delete the obj files, executables, and core dump by
   %./make clean
