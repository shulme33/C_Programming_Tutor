#include <stdio.h> //standard in
#include <math.h> //math library
#define PI 3.14159 //set value precision of pi
#define LOOP_LIMIT 90 //define the max degree the function will go to

typedef enum MENU{ //create new variable type
          sine,
          cosine,
          tangent,
          quit,
    }menu_t; //set name of this type


void sinef(){ //function for calculating sign
    int degree = 0; //value for degree
    while(degree <= LOOP_LIMIT){ //run until program has reached max degree value
	double radian = PI*degree/180; //convert to radians
        double answer = sin(radian); //find sine of radian value
        printf("	sin(%d) = %.4f\n", degree, answer); //print answer
        degree += 15; //incrememnt degree value by 15 degrees
    }
}

void cosinef(){ //function to calc cosine
    int degree = 0; //value of degrees
    while(degree <= LOOP_LIMIT){ //run until program has reached max degree value
	double radian = PI*degree/180; //convert to radians
        double answer = cos(radian); // find cosine of radian value
	printf("	cos(%d) = %.4f\n", degree, answer); //print answer
        degree += 15; //increment by 15 degrees
    }
}

void tangentf(){ //function to calc cosine
    int degree = 0; //var for dgree value
    while(degree <= LOOP_LIMIT){ //run until degree is the max val
	if(degree % 90 == 0 && (degree/90)%2 == 1){ //if tangent is undefined
		printf("	tan(%d) is UNDEFINED\n", degree); //print it is undefined
		degree += 15; //increment by 15 degrees
	}
	else{ //if tangent is defined
		double radian = PI*degree/180; //convert to radians
        	double answer = tan(radian); //find tangent of radian value
        	printf("	tan(%d) = %.4f\n", degree, answer); //print answer
        	degree += 15; //increment by 15 degrees
	    }
	}
}

int is_valid(menu_t choice){ //decide if input number is valid
	if(choice > 3){ //if to big
		printf("That number is too large. Try again.");
		return 0;	
        }
        else if(choice < 0){ //if too small
	        printf("That number is too small. Try again.");
        	return 0;
        }
        else{ //if correct
                return 1;
        }
}

menu_t choose_trig_f(){ //take in users choice
   menu_t  x; //var for input
   printf("Please choose and option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n"); //print prompt
   printf("Enter your choice > "); //prompt
   scanf("%d", &x); //take in input value

   if(is_valid(x) == 1){ //if it is valid
	return x; 
   }
   else { //if not valid
	choose_trig_f();
   }
}

void decide(menu_t choice){ //decide what trig to use
   switch(choice){
       case sine: //if sine
        sinef();
        break;
       case cosine: //if cosine
        cosinef();
        break;
       case tangent: //if tangent
        tangentf();
        break;
   }

}

int main()
{
menu_t x; //input number
while(x != 3){
   x = choose_trig_f(); //set x to input number

   if(x == quit){ //if quit
	printf("You chose QUIT. Thank you, come again!\n");
	return 0;
}
else{ //else keep running
	decide(x);
}
}

}
