/* Author: Anish Oberoi azo5283
   Date: 2/7/2024
    */
/***
 *      ______ .___  ___. .______     _______.  ______        ____    __   __  
 *     /      ||   \/   | |   _  \   /       | /      |      |___ \  /_ | /_ | 
 *    |  ,----'|  \  /  | |  |_)  | |   (----`|  ,----'        __) |  | |  | | 
 *    |  |     |  |\/|  | |   ___/   \   \    |  |            |__ <   | |  | | 
 *    |  `----.|  |  |  | |  |   .----)   |   |  `----.       ___) |  | |  | | 
 *     \______||__|  |__| | _|   |_______/     \______|      |____/   |_|  |_| 
 *                                                                                   
 */


#include "student.h"

// Takes an array of integers and the length of the array as input, and returns
// the smallest integer in the array
int smallest(int *array, int length) {
  /* YOUR CODE */
	int smallest = array[0]; // a variable smallest stores the value of first value of array
	for (int i = 1; i < length; i++){
		if ( smallest > array[i]){ // checks whether the array value at position i is less than the stored valuese in variable smallest
			smallest = array[i];} // if the value is less, than changes the value of the variable to the new smallest value.
	}
  return smallest;
}

// Takes an array of integers and the length of the array as input, and returns
// the product of the integers in the array.
int product(int *array, int length) {
  /* YOUR CODE */
	int product = 1;
	for (int i = 0; i < length; i++){
		product = product * array[i]; //multiplies the different values in the array.
	}
 return product;
}

// Takes pointers to two integers and swaps the values of integers
void swap(int *a, int *b) {
  /*YOUR CODE */
	int temp = *a; // the variable temp copies the  address of *a
	*a = *b; // the address for *b is now copied to address for *a, now *a points to the address of *b
	*b = temp; // the address of *b is now changed using the temp variable which store the initial address from *a

}

// Rotate values of integers
void rotate(int *a, int *b, int *c) {
  /* YOUR CODE */
	int temp = *a; //the variable temp copies the address of *a
	int temp2 = *b; //the variable temp2 copies the address of *b
	*a = *c; //the address for *c is not copies to *a, now *a points to the address of *c
	*b = temp; //the address of *b is now changed using the temp variable which stores the initial address from *a
	*c = temp2; //the address of *c is now changed using temp2 variable, which stores the intial address of *b
}


// Sorts an array in descending order
void sort(int *array, int length) {
  /* YOUR CODE */
	for (int i = 0; i < (length-1); i++){ 
		for(int j = 0; j < length-i-1; j++){
				if(array[j+1] > array[j]){ //checks if the values of array at j+1 is greater than j
				int temp = array[j]; // stores the value of array at j in a variable temp
				array[j] = array[j+1]; //changes the value of array at j to that of j+1
				array[j+1] = temp; // the value of array at j+1 changes to temp which stores the initial value of array at j
			}
		}
	}

}

// Takes an array of integers and the length of the array as input and halves
// every prime element of the array
int is_prime(int x){
	for (int j = 2; j <= (x/2); j++){
		if(x % j == 0 ){ // checks whether the given value is a prime number or not by using % operator between the given value x and all the values upto x/2.
			return 0;// returen 0 if it is not a prime number
		}
	}
	return 1;// return s 1 if is a prime number

}

void halve_primes(int *array, int length) {
  /* YOUR CODE */
	for (int i = 0; i < length; i++){ // iterates through the array
		if (array[i] > 1 && is_prime(array[i]) == 1){ // checks if array[i] is above 1 and if the is_prime function returns 1 or 0
				int new_array = array[i]/2; //if it is array[i], then it divides it by 2 and stores the value in a new variable.
				array[i] = new_array; // assigns the new value at array[i] location.
		}
	}
}

// Takes an array of integers and the length of the array as input and square
// every positive element of the array that is an Armstrong number.
int is_count(int x){
	int count = 0;
	while(x != 0){ //iterates as long as num is not equal to 0
		x = x/10; // removes a digit from num.
		count++; // increase th value of count by one
	}
	return count;
}
int is_armstrong(int num){
	int initial_num;
	int remaining;
	int sum = 0;
	
	initial_num = num;
		
	while (initial_num != 0){ //iterates as long as num is not equal to 0
		remaining = initial_num % 10; // removes the last digit from initial_num.
		int power = 1;
		for (int i = 0; i < is_count(num); i++){ // iterates as long as i is less than count
			power = (power * remaining); // multiplies the variable remaining with power and stores the value in power variable repeatitively as long as i is less than count. 
		} 
		sum = sum + power; // adds the power with the sum to later check if it is equal to the value from the array. 
		initial_num = initial_num/10; //removes a digit from initial_num
	}
	
	return sum;
	
}

void square_armstrongs(int *array, int length) {
  /* YOUR CODE */	
  
  for (int i = 0; i < length; i++){ // iterates as long as i is less than length
  	if(array[i] > 0 && is_armstrong(array[i]) == array[i]){ // checks whether the value of array at i position is greater than 0 and if the helper function is_armstrong returns a 1 or not.
  		array[i] = array[i] * array[i]; // if the conditions above are true then the value of array at i is squared.
  	}
  }
}

// Take an array of integers and length of the arrays as input and triple every
// happy number of that array
int squareSum(int num) {
	int digit;
	int sum = 0;
	while (num > 0){ // iterates till num is grater than 0
		digit = num % 10; // gets the last digit of num
		sum = sum + (digit * digit); //squares the sum and adds it to a new variable 'sum' 
		num = num / 10; //removes the last digit
	}
	
	return sum;
	
}

int is_happy(int x){
	for (int i = 0; i < 146; i++){ //iterates till 145
		x = squareSum(x); // changed the num to the sum by sending it to squareSum 
		if (x == 1){ // if x == 1 then it is a happy number
			return 1;
		}
	}
	return 0;
}
 
void triple_happy(int *array, int length) {
  /* YOUR CODE */
  for (int i = 0; i < length; i++){ //iterates the loop till length - 1
  	if (is_happy(array[i])){ // Checks if the value passes is a happy variable or not
  		array[i] = array[i] * 3; // multiplies the value of array at position i by 3
  	}	
  }  
}

/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
/*CWD /home/anishoberoi/sp24-lab1-AnishOberoi */
