/* Program to provide data for ratePairs.c, by permuting all pairs of the concepts
 * given in cConcepts.txt. The seed of the random number generator is given by the student number
 * The student number is provided as a command-line argument
 * Results are written to cConceptsPairs.txt
 *
 * Author: Eric Aubanel
 * Date: October 2018 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100

int main(int argc, char ** argv){
	if(argc == 1){
		printf("Usage: %s student_number\n", argv[0]);
		return 1;
	}
	int studentNo = strtol(argv[1], NULL, 10);
	FILE *fConcepts, *fPairs;
	if((fConcepts = fopen("cConcepts.txt", "r"))==NULL){
		printf("can't open cConcepts.txt");
		return 1;
	}
	if((fPairs = fopen("cConceptsPairs.txt", "w"))==NULL){
		printf("can't open cConceptsPairs.txt for writing\n");
		return 1;
	}
	char buf[BUFSIZE];
	fgets(buf, BUFSIZE, fConcepts);
	int n = strtol(buf, NULL, 10);
	if(n == 0){
		printf("cConceptsPairs must start with n\n");
		return 1;
	}
	srand(studentNo);
	char **list = malloc(n*sizeof(char*));
	if(list == NULL){
		printf("can't allocate array of pointers\n");
		return 1;
	}
	for(int i=0; i< n; i++){
		if(fgets(buf, BUFSIZE, fConcepts)==NULL){
			printf("insufficient data in cConcepts.txt\n");
			return 1;
		}
		if(buf[strlen(buf)-1] == '\n')
			buf[strlen(buf)-1] = '\0';
		list[i] = strdup(buf);
	}
	int m = n*(n+1)/2 - n; // number of unique pairs of distinct strings
	int count = 0;
	char **pairs = malloc(m*sizeof(char*));
	int *coordsi = malloc(m*sizeof(int));
	int *coordsj = malloc(m*sizeof(int));
	if(pairs == NULL || coordsi == NULL || coordsj == NULL){
		printf("can't allocate arrays\n");
		return 1;
	}
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++){
			strcpy(buf, list[i]);
			pairs[count] = strdup(strcat(strcat(buf, " and "), list[j]));
			coordsi[count] = i;
			coordsj[count] = j;
			count++;
		}

	fprintf(fPairs, "%d\n", n);
	count = 0;
	int *seen = calloc(m, sizeof(int));
	if(seen == NULL){
		printf("can't allocate array seen\n");
		return 1;
	}
	while(count < m){
		int i = rand()%m;
		if(seen[i])
			continue;
		seen[i]++;
		fprintf(fPairs, "%d %d %s\n", coordsi[i], coordsj[i], pairs[i]);
		count++;
	}
	return 0;
}
