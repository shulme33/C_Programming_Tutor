#include <stdio.h>
#define SIZE 12 //size of barcode



int get_array(int barcode[SIZE]){ //take in barcode values
	printf("Enter a bar code to check. Seperate digits with a space > \n");
	for(int i = 0; i < SIZE-1; i++){ //convert input into the array values
		scanf("%d ", &barcode[i]);
	}
	scanf("%d", &barcode[SIZE-1]); //last spot in array

	printf("You entered the code: ");
	for(int i = 0; i < SIZE; i++){ //print out the array values
		printf("%d ", barcode[i]);
	}
	printf("\n");
}

int calc_num(int barcode[SIZE], int odd_or_even){ //calculate sums of odds and evens
	int sum = 0;
	for(int i = odd_or_even; i < SIZE; i+=2){ //calculate the value
		if(i == SIZE-1){

		}
		else{
			sum += barcode[i];
		}
	}
	if(odd_or_even == 0){ //if you are summing odd values
		sum = sum*3;
		printf("Sum of odds times 3 is %d\n", sum);
	}
	else{ //if you are summing even values
		printf("Sum of the even digits is %d\n", sum);
	}
return sum;
}

int decide_if_valid(int barcode[SIZE], int total_num){ //determine if barcode is valid
	int last_num = total_num % 10; //calc last digit
	if(last_num != 0){ //calc check digit
		last_num = 10 - last_num;
	}
	printf("Calculated check digit is %d\n", last_num);

	if(last_num == barcode[SIZE-1]){ // check validity
		printf("Barcode is valid\n");
	}
	else{	//invalid
		printf("Barcode is invalid\n");
	}
}

int main(){
	int barcode1[SIZE]; //create array
	get_array(barcode1); //take in values
	int odd = calc_num(barcode1, 0); //calc odd sum
	int even = calc_num(barcode1, 1); //calc even sum
	int total = odd + even; //calc total sum
	printf("Total sum is %d\n", total);
	decide_if_valid(barcode1, total); //determine validity
	return 0;
}
