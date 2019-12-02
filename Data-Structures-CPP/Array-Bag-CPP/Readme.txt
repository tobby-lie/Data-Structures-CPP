*******************************************************
*  Name      :  Tobby Lie      
*  Student ID:  103385744      
*  Class     :  CSCI 2421           
*  HW#       :  2                
*  Due Date  :  Sept. 4, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program “Bag” will take two sets of integers from a 
file called setInput.txt and store them into two separate
ArrayBag objects from there two operations will be done 
on the data, one being a union operation which will 
combine the data from the two sets into one, eliminating 
duplicate elements, the other being a difference operation 
which will remove all elements of the second set from the 
first set

Note: Utilized error checking to see if items in a set
are all integers 


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from an input file, use the data to create two matrices,
   and compute and display their sum and product.

Name:  ArrayBag.h
   Contains the definition for the class ArrayBag.  

Name: ArrayBag.cpp
   Defines and implements the ArrayBag class for implementing
   This class provides routines to store integers and also
   operate on the data in ways such as adding to the object,
   removing, etc.

Name: SetFunctions.h
   Contains prototypes for the Bag program support functions

Name: SetFunctions.cpp
   Includes functions for input validation and displaying the
   contents of the ArrayBag class
   
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
       % unzip LieHW2.zip

   Now you should see a directory named homework with the files:
        main.cpp
        ArrayBag.cpp
	ArrayBag.h
	SetFunctions.cpp
	SetFunctions.h
	setInput.txt
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieHW2

    Compile the program by:
    % make

3. Run the program by:
   % ./hw2

4. Delete the obj files, executables, and core dump by
   %./make clean
