#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(){
  Words * head = malloc(sizeof(Words));
  char word[100];
  printf("Input first word: ");
  while(scanf("%s", word) == 1){
    head = addWord(head, word);
    if(head == NULL){
      printf("\nSomething has gone wrong.");
      return EXIT_SUCCESS;
    }
    printf("\nInput next word (ctrl + d to exit): ");
  }

  printWords(head);
  deleteList(head);
}
