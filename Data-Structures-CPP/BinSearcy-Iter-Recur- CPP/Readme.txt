*******************************************************
*  Name      :  Tobby Lie      
*  Student ID:  103385744      
*  Class     :  CSCI 2421           
*  HW#       :  3                
*  Due Date  :  Sept. 8, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program “Recursion” will take a file that holds data
regarding different vehicles. The data regards to the 
year, make, and model of the vehicles. The program will 
then sort the specified data and then perform a binary
search on the data that the user specifies. The binary
search will be done both recursively and iteratively

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions.

Name:  Recursion.h
   Contains the definition for the class Recursion.  

Name: Recursion.cpp
   Defines and implements the Recursion class for implementing
   This class provides routines to store data and also
   operate on the data in ways such as sorting and searching.

Name: Vehicle.h
   Contains definition for the class Vehicle

Name: Vehicle.cpp
   Defines and implements the Vehicle class for implementing
   provides routines for accessing and mutating data
   
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
       % unzip LieHW3.zip

   Now you should see a directory named homework with the files:
        main.cpp
        Recursion.cpp
	Recursion.h
	Vehicle.cpp
	Vehicle.h
	vehiclein.txt
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieHW3

    Compile the program by:
    % make

3. Run the program by:
   % ./hw3

4. Delete the obj files, executables, and core dump by
   %./make clean
