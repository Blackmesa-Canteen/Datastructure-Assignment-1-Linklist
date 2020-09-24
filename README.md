# Datastructure-Assignment-1-Linklist
use a link list to store a .csv file

# Purpose
The purpose of this assignment is to:  
• Improve your proficiency in C programming and your dexterity with dynamic memory allocation.  
• Demonstrate understanding of a concrete data structure (linked list).  
• Practice multi-file programming and improve your proficiency in using UNIX utilities.  

# Background
A dictionary is an abstract data type that stores and supports lookup of key, value pairs. For example,
in a telephone directory, the (string) key is a person or company name, and the value is the phone
number. In a student record lookup, the key would be a student ID number and the value would be a
complex structure containing all the other information about the student.

# task
In this assignment, you will create a simple dictionary based on a linked list to store information from
the City of Melbourne Census of Land Use and Employment (CLUE). A user will be able to search this
dictionary to retrieve information about businesses in Melbourne using the business name (key).
Your implementation will build the dictionary by reading census data from a file and inserting each
property record as a node in a linked list. You will also implement a method to search for a key in the
list, outputting any records that match the key. Note that keys are not guaranteed to be unique!

# Implementation Details
Your Makefile should produce an executable program called dict. This program should take two command line arguments:  
(1) the name of the data file used to build the dictionary, and  
(2) the name of an output file.  
  
Your dict program should:  
• Construct a linked list to store the information contained in the data file specified in the com-mand line argument. Each record (row) should be stored in a separate Node.  
• Search the linked list for records, based on keys. The keys will be read in from stdin, i.e. from
the screen. Remember that the entries in the file do not necessarily have unique keys, so your
search must locate all keys matching the search key, and output all the data found.  
• Your program will look up each key and output the information (the data found) to the output
file specified by the second command line parameter. If the key is not found in the tree, you
must output the word NOTFOUND.  

# Requirements
The following implementation requirements must be adhered to:  
• You must write your implementation in the C programming language.  
• You must write your code in a modular way, so that your implementation could be used in another program without extensive rewriting or copying. This means that the linked list opera-tions are kept together in a separate .c file, with its own header (.h) file, separate from the main program.  
• Your code should be easily extensible to different dictionaries. This means that the functions for insertion, search, and deletion take as arguments not only the item being inserted or a key for searching and deleting, but also a pointer to a particular dictionary, e.g. insert(dict,item).  
• Your implementation must read the input file once only.  
• Your program should store strings in a space-efficient manner. If you are using malloc() to create the space for a string, remember to allow space for the final end of string ‘\0’ (NULL).  
• A Makefile is not provided for you. The Makefile should direct the compilation of your program. To use the Makefile, make sure it is in the same directory of your code, and type make dict to make the dictionary. You must submit your makefile with your assignment.  
