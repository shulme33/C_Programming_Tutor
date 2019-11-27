#include <stdio.h>
#define MAX_ARRAY_SIZE 50 //set max array size

int populate_array(int array[MAX_ARRAY_SIZE]){ //set values to array
	printf("Enter a value of n > ");
	int num_spots = 0;
	scanf("%d", &num_spots); //take in number of spots in array
	if(num_spots < MAX_ARRAY_SIZE){ // check if it fits in array

		printf("\nEnter %d integers (positive, negative, or zero) > \n", num_spots);
		int i;
		for(i = 0; i < num_spots; i++){ // take in all values of array
			scanf("%d", &array[i]);
		}
	return num_spots; //return size of array
	}
	else{ //if n is more thatn MAX_ARRAY_SIZE
		printf("%d exceeds the maximum array size. Please try again.\n", num_spots);
		return populate_array(array); //recurse the method
	}
}

void print_array(int array[MAX_ARRAY_SIZE], int n){  //prints the array
	int i = 0;
	for(i = 0; i < n; i++){ //go through and print array
		printf("%d\n", array[i]);
	}
}

void swap(int array[MAX_ARRAY_SIZE], int index1, int index2){ // swap two spots in the array
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

int partition(int array[MAX_ARRAY_SIZE], int low, int high){ //sort the array
if(low+1 == high){ // if the sub array is 2 elements long
	if(array[low] > array[high]){ // if the low is more than the high
		int tem = array[low];
		array[low] = array[high];
		array[high] = tem;
	}
return -1; // return value to see end of execution
}
else{ // if subarray is larger than 2
	int pivot = array[high]; // set pivot value

	int current_low = low; //pointer for low
	int current_high = high-1; //pointer for high

	while(current_low < current_high){ // while array is not partitioned
		while(array[current_low] < pivot){ //  go until low finds value larger than pivot
			current_low++;
		}
		while(array[current_high] > pivot){ // go until high finds value less than pivot
			current_high--;
		}

		int new_temp = array[current_low]; // swap two values
		array[current_low] = array[current_high];
		array[current_high] = new_temp;
	}

	int temp2 = array[high]; //swap two values
	array[high] = array[current_high];
	array[current_high] = temp2;

	for(int i = current_high; i < high; i++){ //set pivot in middle and shift all array spots after
		int temp3 = array[i];
		array[i] = array[i+1];
		array[i+1] = temp3;
	}
	return current_high; //return the pivot spot
}
}
 
void quicksort(int array[MAX_ARRAY_SIZE], int low, int high){ // method to sort array
	if(low < high){
			int part = partition(array, low, high);
		if(part != -1){ //if subarrays arent 1 or smaller
			quicksort(array, low, part - 1);
			quicksort(array, part+1, high);
		}
	}
}

int main(){
	int array[MAX_ARRAY_SIZE]; //create array
	int n = populate_array(array); //populate the array
	printf("The initial array contains:\n");
	print_array(array, n); //show the initial values
	quicksort(array, 0, n-1); // sort array

	printf("The sorted array:\n"); 
	print_array(array, n); //print the sorted array
return 0;
}
