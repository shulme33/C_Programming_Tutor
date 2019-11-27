#include <stdio.h>

int is_valid(int num){
	if(0 < num && num < 10 && num%2 != 0){ //decide if number fits bounds and is odd
		return(1);
	}
	else{ //if it is not odd or within bounds
		return(0);
	}
}

int get_input(){
    int inputNum; //number to take in
    printf("Enter an odd number between 1 and 9 > ");//prompt to get number
    scanf("%d", &inputNum); //take in number
    if(is_valid(inputNum) == 0){ //if it does not pass is_valid
	if(inputNum >= 10){ //if inputNum is too big
	   printf("The number you entered is too high. Try again.\n"); //tell the user the number is too large
	   get_input(); //recurse to get_input()
	}
	else if(inputNum <= 0){ //if number is too low
	   printf("The number you entered is too low. Try again.\n"); //tell user the number is too low
	   get_input(); //recurse to get_input()
	}
	else if((inputNum % 2) == 0){ //if the number is even
	   printf("That is an even number. Try again.\n"); //tell user the number is even
 	   get_input(); //recurse to get_input()
	}
    }
    else{ //if it passes is_valid
    	return inputNum; //return the number inputted by the user
    }
    
    
}

void print_pattern(int num){ 
    int length = (num+1)/2;	//number of spaces
    int num_choice = 1; //variable for the value that gets printed
    int i; //number for the for loops
    for(i = 1; i <= num; i+=2){  //each line
	num_choice = 1; //set num_choice to 1
	printf("%*s", length, " "); //print out number of spaces
	//create top of diamond
	while(num_choice <= i){ //print out values in each line
		printf("%d", num_choice); //print values
		num_choice++; //incriment the number
	}

    	printf("%*s", length, " "); //print spaces at end of line
	length --; //decriment the number of spaces
	printf("\n");    //enter to next line
	}

	length+=2; // increment number of spaces for bottom of diamond

   for(i = num-2; i >0; i-=2){ // for loop for bottom of diamond
	num_choice = 1; //set number to 1
	printf("%*s", length, " "); //print number of spaces at beginning of line
	//creates bottom of diamond
	while(num_choice <= i){ //prints each line
		printf("%d", num_choice); //prints the number stored in num_choice
		num_choice++; // increment num_choice
	}
	printf("%*s", length, " "); //print spaces at end of line
	length++; //increment number of spaces
	printf("\n"); //enter to next line
   }
}

int main()
{
	int x = get_input(); //get input from the user
	print_pattern(x); //print the diamond

return 0; //end program
}
