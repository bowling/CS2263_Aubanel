#include <stdio.h>
#include <limits.h>

int readGraphWeighted(int n, int m, int graph[][n]);

int main(){
  int n, m;
  scanf("%d %d",&n, &m);
  int int graph[n][n];
  if(readGraphWeighted(n, m, graph) == 1){
          printf("invalid input\n");
          return 1;
  }
  int s;
  scanf("%d",&s);
  if(s >= n || s < 0){
         printf("invalid source vertex\n");
         return 1;
  }
  printf("source vertex: %d\n", s);

  int queue[n]  ;//circular buffer to hold FIFO list
  int inQueue[n];//sparse representation of list
  int front = 0; //index of start of list
  int size = 1; //size of list (has source vertex initially)

  int D[n], P[n];
  for(int i=0; i <n; i++){
         D[i] = INT_MAX;
         inQueue[i] = 0;
         P[i] = -1;
  }
  D[s] = 0;
  P[s] = s;
  queue[0] = s;
  inQueue[s] = 1;
  while(size > 0){
    int i = queue[front];
    front = (front+1)%n;
    size--;
    inQueue[i] = 0;
    for(int j=0; j<n; j++){
      int w = graph[i][j];
      if(w == 0)
        continue;
                  if(D[j] > D[i] + w){
        D[j] = D[i] + w;
        P[j] = i;
        if(!inQueue[j]){
                                  queue[(front+size)%n] = j;
                                  size++;
                                  inQueue[j] = 1;
        }
                  }
    }
  }
  printf("P: ");
  for(int i=0;i<n;i++)
          printf("%d ",P[i]);
  printf("\n");
  printf("D: ");
  for(int i=0;i<n;i++)
          printf("%d ",D[i]);
  printf("\n");
}

int readGraphWeighted(int n, int m, int graph[][n]){
  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++)
                graph[i][j] = 0;
  }

  for(int i=0; i<m; i++){
    int v1, v2, w;
    if(scanf("%d %d %d",&v1, &v2, &w)!=3){
      return 1;
    }
    graph[v1][v2] = w;
  }
  return 0;
}
