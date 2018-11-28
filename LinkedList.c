#include "LinkedList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Words * addWord(Words *head, char* newWord){
	Words * ptr = malloc(sizeof(Words));
	if(ptr == NULL){
		printf("Ran out of memory. Aborting\n");
		return NULL;
	}

	strcpy(ptr -> word, newWord);
	ptr -> freq = 1;
	ptr -> next = NULL;
	//printf("\n%s\n", ptr -> word);
	if(head == NULL || compare_words(ptr, head) < 0){
		ptr -> next = head;
		return ptr;
	}
	else{
		Words * alpha = head;
		while(alpha -> next != NULL && compare_words(ptr, alpha -> next) >= 0){
			if(compare_words(ptr, alpha) == 0){
				alpha -> freq += 1;
				return head;
			}
			alpha = alpha -> next;
		}
		ptr -> next = alpha;
		alpha -> next = ptr;
		return head;
	}
}

void printWords(Words * head){

  printf("\n=========================\n");
  printf("Printing the nodes now");
  printf("\n=========================\n");
  while(head != NULL){
    printf("%s: %d\n", head -> word, head -> freq);
    head = head -> next;
  }
  printf("\n");
}

void deleteList(Words * head){
  while(head != NULL){
    Words * p = head -> next;
    free(head);
    head = p;
  }
}

int compare_words(Words * first, Words * second){
	return strcmp(first -> word, second -> word);
}
