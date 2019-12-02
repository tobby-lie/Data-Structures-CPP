*******************************************************
*  Name      :  Tobby Lie      
*  Student ID:  103385744      
*  Class     :  CSCI 2421           
*  HW#       :  1                
*  Due Date  :  Aug. 31, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program generates a number randomly. The user will be asked for input
that will specify the number of digits in this number and the range of each
digit. The user will then need to input a guess for each digit of the number.
The way to win this game is to correctly guess the number.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from an input file, use the data to create two matrices,
   and compute and display their sum and product.

Name:  Guess.h
   Contains the definition for the class Guess.  

Name: Guess.cpp
   Defines and implements the Guess class for implementing a guessing 
   game.  
   This class provides routines to randomly generate numbers which 
   become populated into a vector. It defines user interface in regards
   to expected user input and how that input is handled with the 
   randomly generated number.
   
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
       % unzip LieHW1.zip

   Now you should see a directory named homework with the files:
        main.cpp
        Guess.cpp
	Guess.h
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieHW1

    Compile the program by:
    % make

3. Run the program by:
   % ./hw1

4. Delete the obj files, executables, and core dump by
   %./make clean
