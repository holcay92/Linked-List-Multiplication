# linked-list-multiplication
CSE2025 Data Structures
PROJECT #1 (Due November 5, 2021, Friday at 17:00)

Problem:
    Assume an (theoretically) infinitely large positive natural number specified in decimal number system. How can we multiply it in our computer? We look for a solution that is capable of multiplying such a number. The infinitely large numbers concerning the multiplication (i.e., the multiplicand and the result) should be shown in the original number system presented to your program.
  Example 1:
        5301858469230152002541253
                                8
       x____________________________
        42414867753841216020330024
        
  Example 2:
                              5301
                                 4
                            x_____
                             21204
    The requirement that the numbers may be infinitely large implies that you cannot use standard data types to represent these numbers. Therefore, you will need a data structure that appropriately represents such large natural numbers and you will redefine the multiplication operation in terms of these data structures. A typical data structure to exploit in this case is linked lists (LLs). You may hold each number (including the result) in a LL each digit stored in a node and, while multiplying each pair of digits of multiplicand and multiplier, you may accordingly update the relevant digits in the result. We provide below how the second example is implemented.
  
In this project you are expected to develop an algorithm that is capable of finding a solution to the above problem and implement this algorithm in C that runs under

Input:
An input file containing
 the multiplicand, and
 the multiplier
Output:
An output file containing
 the multiplicand
 the multiplier and
 the result
