# Speller

Speller is a program to spell-checks words in english from a text.

The Program is based on C and takes as input a text, then compare it with the words present in a dictionary, and then output the number of misspelled words.

I have used a Hash Table to organise the words presents in a dictionary in linked lists.

I've also created a hash function that index the words in the hash table in a very fast and efficient way.

## The methodology

In speller, I’ve put together a
 program that’s designed to spell-check a file after loading a 
dictionary of words from disk into memory. That dictionary, meanwhile, 
is implemented in a file called dictionary.c. The prototypes for the functions therein, meanwhile, are defined not in dictionary.c itself but in dictionary.h instead (for organisational reasons). 

That was a pretty challenging project because I had to create my own data structures and hash function. The challenge was also to implement the fastest spell checker I could, using an efficient hash function.

This project involves using all the low-level specifications of C, such as pointers. It's a project that I've loved to work on.  

## Specifications about the source code 

My code is well-documented and easy to understand. 

One can see that after loading the dictionary into memory and starting the loading 
function to scan the file for spell-checking.

To create my hashtable, I've implemented a linked list. 

This process uses a lot of memory, so I had to use a lot of memory allocation in the code and also create a 
function only to free all this memory allocated.

## Tools

* C

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. 

### Prerequisites

You will need to settle up a compiler for C. There is many but I recommend downloading ![Visual Studio Code](https://code.visualstudio.com/) and getting the C/C++ extension that it provides. 

### Installing

Just download the repository here and open it with Visual Studio Code. Inside the repository there's already some texts to test the program, you can find it on `speller/texts`

To run it, open your terminal and run the commands:

`./speller texts/[text file you want to check].txt`

That's all.

## License / Copyright


* Completed as my final project of Harvard CS50 Curriculum

* This project is licensed under the MIT License.


