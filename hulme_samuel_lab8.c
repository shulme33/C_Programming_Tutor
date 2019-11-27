#include <stdio.h>
#include <stdlib.h>
#define NAME_SIZE 25 //max size of a persons name

typedef struct student{ //creates all the parts of a student
	int sid; //student ID
	char last[NAME_SIZE]; //last name
	char first[NAME_SIZE]; //first name
	float *grades; //pointer to array of grades
	float gpa; //average score on grades
}student;

float gpa_calc(float *grade_list, int num_grades){ //function to calculate gpa
        float total;
        for(int i = 0; i < num_grades; i++){ //run through all grades
                total += grade_list[i];
        }

	float average = total/((float)num_grades); //calc average
        return average;
}

student get_info(int num_grades){ //takes in all information for the student
	printf("Enter information for student:\n");
	student s;
	printf("	Enter SID: > "); //student ID
	scanf("%d", &s.sid);

	printf("	Enter last name: > "); //last name
	scanf("%s", &s.last);

	printf("	Enter first name > "); //first name
        scanf("%s", &s.first);

	s.grades = (float *) malloc(num_grades * sizeof(float)); //allocate space for grades

	printf("	Enter grades (seperated by space): >");

	for(int i = 0; i < num_grades-1; i++){ //take in and seperate grades that were entered
		scanf("%f ", &s.grades[i]);

	}
	scanf("%f", &s.grades[num_grades-1]); //take in last grade

	s.gpa = gpa_calc(s.grades, num_grades); //function call to calc average
	printf("	GPA: %.2f\n", s.gpa);

	return s;
}

void print(student stud, int num_grades){ //function to print all student info
	printf("\nStudent ID #%d\n", stud.sid); //print ID number
	printf("	Name:    %s %s\n", stud.first, stud.last); //print name
	printf("	Grades: ");
	for(int i = 0; i < num_grades; i++){ //print all grades in one line
		printf(" %.1f", stud.grades[i]);
	}
	printf("\n	GPA:     %.2f\n", stud.gpa); //print gpa
}

int main(){
	int num_grades;
	int num_students;
	printf("Enter the number of students: > "); 
        scanf("%d", &num_students); //takes in number of students
	student studs[num_students]; //create array to hold students
	printf("Enter the number of grades to track: > ");
	scanf("%d", &num_grades); //take in number of grades

	printf("\nThere are %d students.\n", num_students); //print number of students
	printf("There are %d grades.\n\n", num_grades); //print number of grades

	for(int i = 0; i < num_students; i++){ // get info for all students
		studs[i] = get_info(num_grades);
	}
	for(int i = 0; i < num_students; i++){ //print info for all students
		print(studs[i], num_grades);
	}
	return 0; //end program
}
