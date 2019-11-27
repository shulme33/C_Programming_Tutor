#include <stdio.h>

double x1, x2, x3, x4, x5;

//function to take in sequence values
double get_input(){
	double input;
	//prompt user for input, take in value, and show user what they entered
	printf("Enter a value > ");
	scanf("%lf", &input);
	printf("You entered %.2lf \n", input);

	return(input);	 
}

//function to calculate next value
double get_next(double x_n1, double x_n2){
	double n3;
	n3 = (x_n1/2)+(3*x_n2);
	return(n3);
}

//print resulting values in the sequence
print_result(double result){
	//print with only 2 decimal places
	printf("The result is %.2lf \n", result);
}

int main(void){
	//take in first two values
	x1 = get_input();
	x2 = get_input();

	//calculate third value
	x3 = get_next(x1, x2);
	
	//calculate fourth value
	x4 = get_next(x2, x3);

	//calculate fifth value
	x5 = get_next(x3, x4);

	//print fifth sequence value
	print_result(x5);

	return(0);
}
