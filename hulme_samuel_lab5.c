#include <stdio.h>
#include <math.h>


int user_menu();

//define equation functions
void equation1(float *);
void equation2(float *);
void equation3(float *);
void equation4(float *);

//define functions to take in values of variables
float get_position_initial(void);
float get_position_final(void);
float get_velocity_initial(void);
float get_velocity_final(void);
float get_acceleration(void);
float get_time(void);

//create pointers 
float *initial_position;
float *final_position;
float *initial_velocity;
float *final_velocity;
float *acceleration;
float *time;


int main(){
	//the functions work fine but the user_menu method will never allow an input for some reason
	//
	//
	//
	//
	//
	//
	printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");
	int choice1;
	do{
		choice1 = user_menu();//decide users choice

	switch(choice1){
		case 1:
			printf("Here");
			equation1(final_velocity);
			break;
		case 2:
			equation2(final_position);
			break;
		case 3:
			equation3(final_velocity);
			break;
		case 4:
			equation4(final_position);
			break;
		case 5:
			printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye. \n");
			return 0;
			break;
	}
	}while(choice1 != 5); //keep going until the user quits

return 0;
	
}
int user_menu(){
	int choice;
	printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
	scanf("%s", &choice); //take in choice value
	//printf("%s\n", &choice);
	if(choice <= 5 && choice >= 1){ 
		return choice;
	}
	else{ //if the value is not 1-5
		printf("That is an invalid option. Try again.\n");
		user_menu(); //recursive call
	}
}
void equation1(float * velocity_final){ //find final velocity
	get_velocity_initial();
	get_acceleration();
	get_time();
	float temp = *initial_velocity + (*acceleration)*(*time); //calculate final velocity
	velocity_final = &temp; //set pointer
	printf("Your result is %.4f\n", *velocity_final); //print result
}
void equation2(float * position_final){ // find final position
	get_position_initial();
        get_velocity_initial();
	get_time();
	get_acceleration();
        float temp2 = (*initial_position) + (*initial_velocity)*(*time) + (1/2)*(*acceleration)*(*time)*(*time);//calculate final position
        position_final = &temp2; //set pointer
        printf("Your result is %.4f\n", *position_final); //print results
}
void equation3(float * velocity_final){ //find final velocity
	get_velocity_initial();
        get_acceleration();
        get_position_final();
	get_position_initial();
	float temp3 = (*initial_velocity)*(*initial_velocity)+2*(*acceleration)*(*final_position - *initial_position); //calc fin velocity
        temp3 = sqrt(temp3);
	velocity_final = &temp3; //set pointer
        printf("Your result is %.4f\n", *velocity_final); //set pointer
}
void equation4(float * position_final){//find final position
	get_position_initial();
	get_velocity_final();
        get_velocity_initial();
        get_time();
        float temp4 = (*initial_position) + (1/2)*(*final_velocity + *initial_velocity)*(*time); //calc final position
	printf("%f",temp4); 
        position_final = &temp4; //set pointer
        printf("Your result is %.4f\n", *position_final); //print results
}

float get_position_initial(){ //take in variable
	float temp;
	printf("Enter the initial position > ");
	scanf("%f", &temp); 
	initial_position = &temp; //set pointer
}
float get_position_final(){//take in variable
	float temp;
	printf("Enter the final position > ");
	scanf("%f", &temp);
	final_position = &temp;//set pointer
}
float get_velocity_initial(){//take in variable
	float temp;
        printf("Enter the initial velocity > ");
        scanf("%f", &temp);
        initial_velocity = &temp;//set pointer
}
float get_velocity_final(){//take in variable
	float temp;
        printf("Enter the final velocity > ");
        scanf("%f", &temp);
        final_velocity = &temp;//set pointer
}
float get_acceleration(){//take in variable
	float temp;
        printf("Enter the acceleration > ");
        scanf("%f", &temp);
        acceleration = &temp;//set pointer
}
float get_time(){//take in variable
	float temp;
        printf("Enter the time > ");
        scanf("%f", &temp);
        time = &temp;//set pointer
}
