#include <stdio.h>
#include <stdlib.h>

int **pathFind(int n, int w[][n], int q); //Function to find q, the maximum shortest path length

int max(int uno, int dos);

int main(int argc, char** argv)
{
  FILE *file;
  file = fopen(argv[1], "r");
  if(file == NULL)
  {
    printf("File1 not found!");
  }
  FILE *file2;
  file2 = fopen(argv[2], "r");
  if (file2 == NULL)
  {
    printf("File2 not found!");
  }

  int n;
  fscanf(file, "%d",&n); //Taking in the value n(from a file), the # of vertices
  int w[n][n]; //Initialize the weighted adjacency matrix to n x n

  while(!feof(file)){
    for(int i =0; i <n;i++){
      for(int j =0; j <n;j++){
        fscanf(file, "%d",&w[i][j]);
      }
    }
  }
  printf("\n");
  pathFind(n,w,3);
  printf("\n");

  int nw;
  fscanf(file2,"%d",&nw);
  char *wpadjM[nw];
  char wadjM[nw][50];

  while(!feof(file2)){
    for(int i =0; i <nw;i++){
      fscanf(file2, "%s",&wadjM[i]);
    }
  }
  for(int i =0; i<nw;i++){

    wpadjM[i] = &wadjM[i][0];
  }
  //writing to .dot file

  printf("graph {\noverlap = scale\n");

  for(int i =0; i <n;i++){
    for(int j =0; j <n;j++){
        //print some text
        if(w[i][j] == w[j][i])
        {
          w[j][i] = 0;
        }
        if(w[i][j]!=w[j][i])
        {
        const char *row = wpadjM[i];

        const char *col = wpadjM[j];
        //fprintf(w, "\"%s\" -- \"%s\"\n", *row,*col);
        printf("\"%s\" -- \"%s\"\n", wpadjM[i],wpadjM[j]);
}
      }
    }
    printf("}");
    printf("\n");
  }






int **pathFind(int n, int w[][n], int q)
{
  int wa[n][n]; //Initialize the Mathrix of path lengths, w2
  int wb[n][n];
  int dq[n][n]; //Initializes something
  int p[n][n];
  int dist;
  int minWeight;
  int swapTemp = 0;


  for(int v = 0; v < n; v++)
  {
    for(int d = 0; d < n; d++)
    {
      wa[v][d] = w[v][d];
      dq[v][d] = w[v][d];
      wb[v][d]  = 0;
      p[v][d] = 0;
    }
  }


  for(int m = 1; m < q-1; m++)
  {
    for(int j = 0; j < n-1; j++)
    {
      for(int k = 0; k < n-1; k++)
      {
        if(k!=j)
        {
          minWeight = -99;
        }
        for(int g = 0; g < n-1; g++)
        {
          if(g!=j)
          {
            if(g!=k)
            {
              dist = max(w[j][g],wa[g][k]);
            }
          }
          if(dist < minWeight)
          {
            minWeight = dist;
          }



        }
        if(minWeight < dq[j][k])
        {
          dq[j][k] = minWeight;
        }
        wb[j][k] = minWeight;
      }
    }
    //swap wa and wb

    for(int a = 0; a < n; a++)
    {
      for(int z = 0; z < n; z++)
      {
        swapTemp = wa[a][z];
        wa[a][z] = wb[a][z];
        wb[a][z] = swapTemp;
      }
    }
  }



  for(int j = 0; j < n; j++)
  {
    for(int k = 0; k < n; k++)
    {
      if(j != k)
      {
        if(dq[j][k] == w[j][k])
        {
          p[j][k] = w[j][k];
        }
      }
    }
  }

  for(int m = 0; m < n; m++)
  {
    for(int y = 0; y < n; y++)
    {
      printf("%d ",p[m][y]);
    }
    printf("\n");
  }
  printf("\n");
  for(int m = 0; m < n; m++)
  {
    for(int y = 0; y < n; y++)
    {
      printf("%d ",dq[m][y]);
    }
    printf("\n");
  }

  return p;

}

int max(int uno, int dos)
{
  if(uno > dos)
  {
    return uno;
  }
  else
  {
    return dos;
  }
}
