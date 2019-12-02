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

The program “list STL” will utilize the list STL in 
order to sort and search a list of words. This program
will illustrate the different ways a double linked list
can be efficient.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions.

Name: dictionary.h
   Contains the definition for the class dictionary.  

Name: dictionary.cpp
   Defines and implements the dictionary class
   This class provides routines to store a list of strings
   and then also search strings using the list STL.

Name: DictEntry.h
   Encapsulates each entry, can hold info about a certain word.  


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
       % unzip LieHW6.zip

   Now you should see a directory named LieHW6 with the files:
        main.cpp
        dictionary.cpp
	dictionary.h
	DictEntry.h
	dictionary.txt
	findwords.txt
	revsorted.txt
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieHW6

    Compile the program by:
    % make

3. Run the program by:
   % ./hw6

4. Delete the obj files, executables, and core dump by
   %./make clean
