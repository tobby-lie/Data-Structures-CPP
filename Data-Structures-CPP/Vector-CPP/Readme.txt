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

The program “myVector” will utilize dynamic memory allocation
to implement a class that utilizes a dynamic array to mimic
the STL vector. 

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions.

Name:  MyVector.h
   Contains the definition for the class MyVector.  

Name: MyVector.cpp
   Defines and implements the MyVector class
   This class provides routines to store data and also
   operate on the data in ways such as pop_back, push_back
   and search.

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
       % unzip LieHW4.zip

   Now you should see a directory named LieHW4 with the files:
        main.cpp
        MyVector.cpp
	MyVector.h
	analysis.txt
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieHW4

    Compile the program by:
    % make

3. Run the program by:
   % ./hw4

4. Delete the obj files, executables, and core dump by
   %./make clean
