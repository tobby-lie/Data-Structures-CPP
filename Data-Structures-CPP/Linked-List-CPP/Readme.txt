*******************************************************
*  Name      :  Tobby Lie      
*  Student ID:  103385744      
*  Class     :  CSCI 2421           
*  HW#       :  4               
*  Due Date  :  Sept. 15, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program “LinkedList” will utilize dynamic memory allocation
and pointers to implement LinkedList class.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions.

Name: LinkedList.h
   Contains the definition for the class LinkedList.  

Name: LinkedList.cpp
   Defines and implements the LinkedList class
   This class provides routines to store data and also
   operate on the data in ways such as insertToFront, deleteAtBack

Name: SetFunctions.h
   Contains the support functions for LinkedList program.  

Name: SetFunctions.cpp
   Contains implementation for support functions for 
   LinkedList program.


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
       % unzip LieHW5.zip

   Now you should see a directory named LieHW4 with the files:
        main.cpp
        LinkedList.cpp
	LinkedList.h
	SetFunctions.cpp
	SetFunctions.h
	analysis.txt
	setInput.txt
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieHW5

    Compile the program by:
    % make

3. Run the program by:
   % ./hw5

4. Delete the obj files, executables, and core dump by
   %./make clean
