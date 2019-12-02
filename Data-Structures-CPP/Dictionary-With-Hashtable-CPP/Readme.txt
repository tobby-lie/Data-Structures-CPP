*******************************************************
*  Name      :  Tobby Lie      
*  Student ID:  103385744      
*  Class     :  CSCI 2421           
*  HW#       :  9               
*  Due Date  :  November 5, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program “Spell Check”, creates a partial spellchecker
by utilizing a hash table implemented as an array
with linked lists. Used the list STL.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions.

Name: Hash.h
   Contains the definition for the Hash functions. 

Name: Hash.cpp
   Defines and implements the Hash functions
   Uses list, and array to create a hash table class
   based on an array of linked lists

Name: functions.h
   Program functions for finding certain numbers of 
   words correlated between files and a given dictionary
   .txt file


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
       % unzip LieHW9.zip

   Now you should see a directory named LieHW9 with the files:
        main.cpp
	Hash.h
	Hash.cpp
	functions.h
	check.txt
	Potter.txt
	dict.txt
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieHW9

    Compile the program by:
    % make

3. Run the program by:
   % ./hw9

4. Delete the obj files, executables, and core dump by
   %./make clean
