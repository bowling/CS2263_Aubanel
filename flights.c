#include <stdio.h>
#include <stdlib.h>

void findClosestFlight(int desiredTime, int *departureTime, int *arrivalTime);

int main(){
  int d1, d2;
  if(scanf("%d:%d", &d1, &d2) != 2){
	return EXIT_FAILURE;
  }

  /* Timing Variables */
  int num1, num2, num3, num4;
  int arrivalTime;
  int departureTime;
  int desiredTime = d1*60 + d2;

  findClosestFlight(desiredTime, &departureTime, &arrivalTime);
  
  num2 = departureTime % 60;
  num1 = departureTime / 60;
	
  num4 = arrivalTime % 60;
  num3 = arrivalTime / 60;

  if(num1 < 10){
   	char[3] num5 = "0" + num1 + '\0';
  }
  if(num2 < 10){
  	char[3] num6 = "0" + num2 + '\0';
  }
  if(num3 < 10){
  	char[3] num7 = "0" + num3 + '\0';
  }
  if(num4 < 10){
  	char[3] num8 = "0" + num4 + '\0';
  }
  char[12] numberFormatting1 = num5 + ":" + num6;
  char[12] numberFormatting2 = num7 + ":" + num8;

  printf("The closest time to your desired time departs @ %s and arrives at %s", numberFormatting1, numberFormatting2);
}

void findClosestFlight(int desiredTime, int *departureTime, int *arrivalTime){
  /* Any time passed in is an int. To find the XX#1:XX#2 value, XX#2 = desiredTime % 60. XX#1 = desiredTime / 60. */

  int timeBetween;
  int minTime = 999999;
  int returnArrival;
  int returnDepart;
  int num1, num2, num3, num4;
  FILE * fp = fopen("flights.dat","r");
  while((fscanf(fp, "%d:%d", &num1, &num2) == 2) && (fscanf(fp, "%d:%d", &num3, &num4) == 2)){
	*departureTime = (num1*60) + num2;
	*arrivalTime = (num3*60) + num4;
	
	timeBetween = abs(desiredTime - *departureTime);
	if(timeBetween < minTime){
		minTime = timeBetween;
		returnDepart = *departureTime;
		returnArrival = *arrivalTime;
	}
  }
  
  *departureTime = returnDepart;
  *arrivalTime = returnArrival;
}
