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
  int desiredTime;

  int counter = 0;
  findClosestTime(desiredTime, &departureTime, &arrivalTime);
  
  num2 = departureTime % 60;
  num1 = departureTime / 60;
	
  num4 = arrivalTime % 60;
  num3 = arrivalTime / 60;

  printf("The closest time to your desired time departs @ %d:%d and arrives at %d:%d", num2, num1, num4, num3);
}

void findClosestFlight(int desiredTime, int *departureTime, int *arrivalTime){
  /* Any time passed in is an int. To find the XX#1:XX#2 value, XX#2 = desiredTime % 60. XX#1 = desiredTime / 60. */

  int timeBetween;
  int minTime = 999999;
  int returnArrival;
  int returnDepart;
	
  FILE * fp = fopen("flights.dat","r");
  while((fscanf(fp, "%d:%d", &num1, &num2) == 2) && (fscanf("%d:%d", &num3, &num4) == 2)){
	departureTime = (num1*60) + num2;
	arrivalTime = (num3*60) + num4;
	
	timeBetween = abs(desiredTime - departureTime);
	if(timeBetween < minTime){
		minTime = timeBetween;
		returnDepart = *departureTime;
		returnArrival = *arrivalTime;
	}
  }
  
  *departureTime = returnDepart;
  *arrivalTime = returnArrival;
}
