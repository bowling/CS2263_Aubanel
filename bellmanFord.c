#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int readWeightedGraph(int n, int m, int graph[]);
int main(){
  int n, m;

  if(scanf("%d %d", &n, &m)  != 2){
    printf("Failed to scan n or m");
    return EXIT_FAILURE;
  }

  int queue[n];
  int inQueue[n];
  int distance[n]; // Size?
  int predecessor[n]; // Size?

  /* Assign the array to 0 */
  int graph[n*n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      graph[i*n+j] = 0;
    }
  }

  /* Assign the result of readWeightGraph */
  int result = readWeightedGraph(n, m, graph);

  if(result == 1){
    printf("Failed to read the array");
    return EXIT_FAILURE;
  }
  else{
    /* Initalize Array to INT_MAX */
    for(int i = 0; i < n; i++){
      distance[i] = INT_MAX;
    }

    /* Initialize Array to -1 */
    for(int i = 0; i < n; i++){
      predecessor[i] = -1;
    }

    int sourceVertex;
    if(scanf("%d", &sourceVertex) != 1){
      printf("Failed to scan Starting Vertex");
      return 1; // Failed
    }

    /* Assigning variables */
      int front = 0;
      int size = 1;
      int max = n; //Changed
    queue[(front+size)%max]=sourceVertex;
    size++;
    predecessor[sourceVertex] = sourceVertex;

    distance[sourceVertex] = 0;
  //Remove vertex i from list
    while(size > 0){
      int i = queue[front];
      front = (front+1)%max;
      size--;
      inQueue[i] = 0;

      for(int j = 0; j < n; j++){
        if (graph[i*n+j] != 0){
          if(distance[j] > distance[i] + graph[i*n+j]){
            distance[j] = distance[i] + graph[i*n+j];
            predecessor[j] = i;
            if(inQueue[j] == 0){
              if(size < max){ //CHanged?
                queue[(front+size)%max]=j;
                size++;
                inQueue[j] = 1;
              }
            }
          }
        }
      }
  }
}
  printf("\nP: ");
  for(int l = 0; l < n; l++){
    printf("%d ", predecessor[l]);
  }

  printf("\nD: ");
  for(int q = 0; q < n; q++){
    printf("%d ", distance[q]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}

int readWeightedGraph(int n, int numEdges, int graph[]){
  int j = 0;
  int i = 0;
  int weight = 0;

  /* Read in the graph */
  for(int counter = 0; counter < numEdges; counter++){
    if(scanf("%d %d %d", &i, &j, &weight) != 3){
      printf("Failed to scan edges or weight");
      return 1;
    }
    else{
      graph[i*n+j] = weight;
    }
  }

  /* Print the graph */
  for(int a = 0; a < n; a++){
		for(int b = 0; b < n; b++){
			printf("%d  ", graph[a*n+b]);
		}
		printf("\n");
	}
  return EXIT_SUCCESS;
}
