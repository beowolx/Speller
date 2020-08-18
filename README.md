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

