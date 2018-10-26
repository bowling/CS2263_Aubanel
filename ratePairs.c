/*
 * Program to input data from person rating the similarity
 * of all pairs of n concepts, indexed 0 to n-1
 * Takes file a pair of concepts as a command-line argument
 * with the format for each line:  i j concept1 and concept2
 * where i (j) refer to the index of concept1 (concept2)
 * File starts with n 
 *
 * Author: Eric Aubanel
 * Date: October 2018 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100

int main(int argc, char ** argv){
	FILE *fPairs, *fResult;
	if(argc < 2){
		printf("Usage: %s file_name_for_pairs\n", argv[0]);
		return 1;
	}
	int n;
	if((fPairs = fopen(argv[1], "r"))==NULL){
		printf("can't open %s\n", argv[1]);
		return 1;
	}
	if((fResult = fopen("pairs.txt", "w"))==NULL){
		printf("can't open pairs.txt for writing\n");
		return 1;
	}
	if(fscanf(fPairs, "%d",&n)!=1){
		printf("%s must start with n\n", argv[1]);
		return 1;
	} 
	int m = n*(n+1)/2 - n;
	char buf[BUFSIZE];
	system("clear"); // clear screen
	printf("rate the similarity of the following pairs of concepts\n");
	printf("for each pair enter an integer between 1 and 6\n");
	printf("1 means least similar and 6 means most similar\n");
	printf("press ENTER to continue\n");
	char c;
	scanf("%c", &c);
	for(int i=0; i<m; i++){
		system("clear");
		int x,y;
		if(fscanf(fPairs,"%d %d", &x, &y)!=2){
			printf("pairs aren't indexed properly\n");
			return 1;
		}
		fgets(buf, BUFSIZE, fPairs);
		puts(buf); // display pair
		int ans;
		while(scanf("%d", &ans)!=1 || ans < 1 || ans > 6){
			printf("similarity score must be integer between 1 and 6\n");
			fgets(buf, BUFSIZE, stdin);
		}
		fprintf(fResult, "%d %d %d\n", x, y, 7 - ans);
	}
	return 0;
}
