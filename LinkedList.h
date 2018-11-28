#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef struct words{
  char word[100];
  int freq;
  struct words *next;
}Words;

Words * addWord(Words *head, char* newWord);
void printWords(Words * head);
void deleteList(Words * head);
int compare_words(Words * first, Words * second);


#endif
