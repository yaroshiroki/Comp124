/*
Name: Yaroslav Shiroki
Student ID: 201458436
University Email: Y.Shiroki@student.liverpool.ac.uk
*/

#include <stdio.h>

#include <stdlib.h>

int main(void)

{
	// first declare the numeric variables. These will be the data integers.
	int numOfPos = 0; // this will be a count of the positive integers. Starts at 0 as that is the lowest possible number of positive inputs.
	int numOfNeg = 0; // this will be a count of the negative integers. Starts at 0 as that is the lowest possible number of Negative inputs.
	int numOfZer = 0; // this will be a count of integers which are equal to zero. Starts at 0 as that is the lowest possible number of inputs equal to 0.
	int numOfInts = 0; // this will be a count of all integers. This will be used as a count for the loop, decreasing with each cycle.
	int inp = 0; // this will be the user's input integer, being overwritten every time the user enters a new integer in the loop.

	// formatting for the scanf and printf functions.
	char fmt[] = "%d";

	// data strings.
	char getNumberOfIntegers[] = "How many integers would you like to enter? \n"; // message for getting the number of integers.
	char getInteger[] = "Please enter an integer \n"; // message for getting each individual integer.
	char numZeroMsg[] = "The number of integers you have entered, which are equal to zero are: %d \n";
	char numNegMsg[] = "The number of integers you have entered, which are less than zero (a.k.a negative integers) are: %d \n";
	char numPosMsg[] = "The number of integers you have entered, which are greater than zero (a.k.a positive integers) are: %d \n";
	// use of \n on the end of messages, in order to keep everything on seperate lines, allowing for clear readability and understanding from the user.
	_asm

	{
		// print the introduction message, in order to inform the user that they need to input how many integers they would like to input.
		lea eax, getNumberOfIntegers
		push eax
		call printf
		// clearing the stack with 2^2 as push is used once.
		add esp, 4
		// scan the input of how many integers the user would like to input, saving this to memory in the right format.
		lea eax, numOfInts
		push eax
		lea eax, fmt
		push eax
		call scanf
		// clearing the stack with 2^3 as push is used twice.
		add esp, 8
		// set up the loop to repeat for however many integers the user would like to enter.
		mov ecx, numOfInts
		// if user enters a number of integers they would like to enter which is less than 1, jump to the end of the program.
		cmp ecx, 0
		jle end
		loopInput :
			// print message to inform the user to input one of their integers.
			push ecx
			lea eax, getInteger
			push eax
			call printf
			// clear the stack in the same way.
			add esp, 8
			// scan the input from the user and store it as inp in the correct format.
			lea eax, inp
			push eax
			lea eax, fmt
			push eax
			call scanf
			// clear the stack in the same way.
			add esp, 8
			// compare the input and if it's equal to zero, jump to the zerJmp.
			cmp inp, 0
			je zerJmp
			// compare the input and if it's more than zero, jump to the posJmp.
			cmp inp, 1
			jge posJmp
			// compare the input and if it's less than zero, jump to the negJmp.
			cmp inp, -1
			jle negJmp
		// if jumped here, increase the zero counter, decrease the integer counter, compare the integer counter and if it's greater than 0, jump to
		// top of loopInput. If the input is not greater than 0, then jump to printing.
		zerJmp :
			inc numOfZer
			dec numOfInts
			cmp numOfInts, 0
			jg loopInput
			jmp printing
		// if jumped here, increase the positive counter, decrease the integer counter, compare the integer counter and if it's greater than 0, jump to
		// top of loopInput. If the input is not greater than 0, then jump to printing.
		posJmp :
			inc numOfPos
			dec numOfInts
			cmp numOfInts, 0
			jg loopInput
			jmp printing
		// if jumped here, increase the negative counter, decrease the integer counter, compare the integer counter and if it's greater than 0, jump to
		// top of loopInput. If the input is not greater than 0, then jump to printing.
		negJmp :
			inc numOfNeg
			dec numOfInts
			cmp numOfInts, 0
			jg loopInput
			jmp printing
		printing:
			// print the number of zeros, which the user input, as well as the message, in order to make the information readable and understandable for the user.
			lea eax, numZeroMsg
			push numOfZer
			push eax
			call printf
			// clearing the stack the same way as before.
			add esp, 8
			// print the number of positive integers, which the user input, as well as the message, in order to make the information readable and understandable 
			// for the user.
			lea eax, numPosMsg
			push numOfPos
			push eax
			call printf
			// clearing the stack the same way as before.
			add esp, 8
			// print the number of negative integers, which the user input, as well as the message, in order to make the information readable and understandable 
			// for the user.
			lea eax, numNegMsg
			push numOfNeg
			push eax
			call printf
			// clearing the stack the same way as before.
			add esp, 8
			// the end of the program, to jump to as stated before in line 50.
		end:
	}
	system("pause");
	return 0;
}
