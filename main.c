#include <stdio.h>
#include <stdlib.h>

//150120056 Haldun Halil OLCAY

//structure for keeping the digits of the input numbers
struct Numbers {
	int digit;
	struct Numbers* next;
};
typedef struct Numbers Number;

// Function to reverse the linked list and return its length
int reverse(Number** head){
	
	Number* prev = NULL;
	Number* current = *head;
	Number* next;
	int length = 0;
	while (current != NULL) {
		length++;
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
	return length;
}
// Function to make an empty linked list of given size...
Number* makeResultList(int size){
	
	Number* head = NULL;
	
	while (size--){	
		Number* new_node = (Number*)malloc(sizeof(Number));
		new_node->digit = 0;
		new_node->next = (head);
		head = new_node;
	}
		return head;
}
//multiplication process...
Number* multiplication(Number* first , Number* second , int length1 , int length2){
	
//we reverse the numbers to easily multiply...
 	reverse(&first) ,  reverse(&second);
	Number* result = makeResultList(length1 + length2 + 1);

//pointers to traverse linked lists and also to reverse them after...	 
	Number *secondPtr = second,
	 *result1 = result, *result2, *firstPtr;

	while (secondPtr) {
		int carry = 0;

//each time we start from the next of the digit from which we started last time	
		result2 = result1;
		firstPtr = first;
		while (firstPtr) {

// multiply a first list's digit with a current second list's digit
			int mul = firstPtr->digit * secondPtr->digit + carry;
						
// Assigne the product to corresponding digit of result	
			result2->digit += mul % 10;

// now resultant node may have more than 1 digit		 
			carry = mul / 10 + result2 -> digit / 10;
			result2->digit = result2 -> digit % 10;

			firstPtr = firstPtr -> next;
			result2 = result2 -> next;
		}

// if carry is remaining from last multiplication
		if (carry > 0) {
			result2->digit += carry;
		}

		result1 = result1->next;
		secondPtr = secondPtr->next;
	}
	reverse(&result);
	reverse(&first);
	reverse(&second);

//Remove if there are zeros at starting											
	while (result->digit == 0) {
		Number* temp = result;
		result = result->next;
		free(temp);
	}
	return result;
}
//This function prints the result values into the output.txt file...
void printFile(Number* multiplier1, Number* multiplier2, Number* result,FILE *ptr){
	while (multiplier1 != NULL) {
		fprintf(ptr,"%d", multiplier1->digit,multiplier2->digit,result->digit);	
		multiplier1 = multiplier1->next;
	}fprintf(ptr," * ");
	while (multiplier2 != NULL) {
		fprintf(ptr,"%d",multiplier2->digit);	
		multiplier2 = multiplier2->next;
	}fprintf(ptr," = ");
	while (result != NULL) {
		fprintf(ptr,"%d", result->digit);	
		result = result->next;		
	}
	fprintf(ptr," \n");
}

int main(void)
{
	Number* first = NULL;
	Number* second = NULL;
	int lengthOf1;
	int lengthOf2;
	
		FILE *fp  = fopen("Input.txt","r" );
			if( fp == NULL )
				{printf("file cant be opened\n");}
		//	else{printf("input.txt file is opened\n");}
	
//This opens the output file in writing (appending) mode...
			FILE *fpt = fopen("Output.txt","a");		
			if( fpt == NULL )
				{printf("file cant be opened\n");}
		//	else{printf("output.txt file is opened\n");}
		//	printf("\n");
	char x;
//Multiplier 1 is readed into linked list until it realises the NULL character...
	while ((x = fgetc(fp) ) != EOF && x!=10){		
		Number *new_node = (Number*)malloc(sizeof(Number));
		new_node->digit = x-48;
		new_node->next = (first);
		first = new_node;
	}
	lengthOf1 =	reverse(&first);

//Multiplier 2 is readed into linked list...
	while ((x = fgetc(fp) ) != EOF){		
		Number *new_node = (Number*)malloc(sizeof(Number));
		new_node->digit = x-48;
		new_node->next = (second);
		second = new_node;
	}
	lengthOf2 = reverse(&second);
		
//	printf("%d %d\n",lengthOf1,lengthOf2);
//Multiply the two multipliers and put the result in result linked list...
	Number* result = multiplication(first, second,lengthOf1,lengthOf2);	
//Print the final result in output.txt file	
	printFile(first,second,result,fpt);
//close all files...	
	fclose(fp);
	fclose(fpt);
}
