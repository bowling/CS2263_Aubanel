#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *w = fopen("words.dat", "r");
	int size =0;
	if(fscanf(w, "%d",&size) != 1){
		 printf("Failed to scan in the Array Size.\n");
	   return EXIT_FAILURE;
	}
	char arr1[size*50];

	int i = 0;
	
	
	while(fscanf(w, "%s", arr1)==1){
		printf("%s\n", arr1);
		i++;
	}

	char *words[size];
	for(int l = 0; l < size; l++){
		words[l] = &arr1[l*50];
	}

	/* Creating the array of Edges */
	int value;
	int arr2[size][size];
	for(int z = 0; z < size; z++){
		for(int p = 0; p < size; p++){
					arr2[z][p] = 99999;
			}
		}

	/* Open the file */
	FILE *m = fopen("matrix.dat", "r");

	/* Force skip the first value */
  if(fscanf(m, "%d", &value) != 1){
		//doesn't matter
		return EXIT_FAILURE;
	}

	/* Scan in all the values */
	for(int z = 0; z < size; z++){
		for(int p = 0; p < size; p++){
			//printf("%d ",value);
			if(fscanf(m, "%d", &value) != 1){
				printf("Failed to scan\n");
				return EXIT_FAILURE;
			}
			else{
				/* Scanning successful, input the number */
				arr2[z][p] = value;
			}
		}
	}
	for(int j = 0; j < size; j++){
		for(int k = 0; k < size; k++){
			printf("%d ", arr2[j][k]);
		}
		printf("\n");
	}

	/*
	for(int j = 0; j < size; j++){
			printf("%s\n", words[j]);
	}
	printf("\n");
	*/
}