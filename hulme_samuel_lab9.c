#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_SIZE 100 //sets maximum size of a line

const char delim[2] = ","; //sets the character that seperates parts of the line

void merge_files(FILE *inp1, FILE *inp2, FILE *out){ //function to merge files
	char line1[LINE_SIZE]; //string characters
	char line2[LINE_SIZE];

	char copy1[LINE_SIZE]; //copies of the lines 
        char copy2[LINE_SIZE];

	fgets(line1, LINE_SIZE, inp1); //gets the first line from file 1
        fgets(line2, LINE_SIZE, inp2); //gets first line from file 2
	strcpy(copy1, line1); //copy line 1 to copy1
        strcpy(copy2, line2); //copy line 2 to copy2

	while(!feof(inp1) && !feof(inp2)){ //run until one file is empty
		strtok(line1, delim); //take just first part of each line
		strtok(line2, delim);
		int one = atoi(line1); //change strtok part into integer
		int two = atoi(line2);
		if(one < two){ //compare the two atomic numbers
			fprintf(out, "%s\n", copy1); //copy to the output file
			line1[0] = '\0'; // change line1 back to 0
			//printf("%s", copy1);
			fgets(line1, LINE_SIZE, inp1); //get next line from file
			strcpy(copy1, line1); //copy line1 to copy1 again
		}else if(two < one){//compare the two atomic numbers
			fprintf(out, "%s", copy2);//copy to the output file
			line2[0] = '\0';// change line1 back to 0
			//printf("%s", copy2);
			fgets(line2, LINE_SIZE, inp2); //get next line from file 
			strcpy(copy2, line2);//copy line1 to copy1 again
		}
	}

	while(!feof(inp1)){ //finish file that still has data
		fgets(line1, LINE_SIZE, inp1); //get first line
		fprintf(out, "%s\n", line1); //print to output file
		//printf("%s", line1);
	}
	while(!feof(inp2)){ //finish file that still has data
                fgets(line2, LINE_SIZE, inp2);//get first line
                fprintf(out, "%s\n", line2);//print to output file
		//printf("%s", line2);
        }
	printf("\nFile merging complete.\n\n");
	//make while loops to finish off the lists
}

void find(FILE *out, char s){ // function to find an element
	FILE *f; //file pointer
	if(out == NULL){ //if the file is empty
		printf("Error"); //error message
		exit(1); //exit the program
	}
	else{
		char line[LINE_SIZE]; //string for one line of file
		char copy[LINE_SIZE]; //to make copy of line
		int found = 0; // boolean value for if the value is found
		int atomic_number; 
		double atomic_weight;
		char *name;
		char *symbol;

		while(found == 0){ //seatch through the file
			fgets(line, LINE_SIZE, out); //get a line from the file
        		strcpy(copy, line); //copy the line
			if(line == NULL){ //if the line is empty
				continue;
			}
			else{
				atomic_number = *strtok(NULL,delim); //set first part of line to variable
				atomic_weight = *strtok(NULL, delim); //set second part of line
				name = strtok(NULL, delim); //third part
				symbol = strtok(NULL, delim); //4th part
			if(strcmp(symbol,(char *)s) == 0){ //compare the atomic symbol to the passed value
				printf("Element: %s\n", *name); //print values
				printf("Symbol %s\n", *symbol);
				printf("Atomic Number %d", atomic_number);
				printf("Atomic Weight %f", atomic_weight);
				break;
			}
			}
		}
	}
}

//
//
//
//
// I couldn't get the strcmp to work for some reason. It didn't like how I was comparing them
// I'm also doing somethng wrong with the way I use the name and symbol variables in the 
// The file adding works
//
//
//

int main(int argc, char *argv[]){
	FILE *inp1 = fopen("elements_file1.csv", "r"); //open file
	FILE *inp2 = fopen("elements_file2.csv", "r"); //open file
	FILE *out = fopen("elements.csv", "w"); //open file

	if( inp1 == NULL || inp2 == NULL || out == NULL){ //if any one of the files has nothing in it
		printf("Error loading file."); //print error message
		exit(1); //exit with an error
	}

merge_files(inp1, inp2, out); //run merge files function
find(out, "O");
return 0;
}
