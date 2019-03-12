#include <stdio.h>
#include <stdlib.h>

#include "lists.h"


/*  Thank you @orestis_pol, https://lists.di.uoa.gr/showpost.php?p=83741&postcount=3  */

listnode* ins_at_start(listnode* list, int let, int num){
  listnode* node; 
  if ((node = malloc(sizeof(listnode))) == NULL) exit(EXIT_FAILURE);
  node->let = let;
  node->num = num;
  node->next = list;
  return node;
}

void list_print(listnode* list) {
  printf("%c%d ",list->let + 'A',list->num + 1);    /* Print the letter as a character */
  list = list->next;
  while (list != NULL) {
    printf("-> %c%d ",list->let + 'A',list->num + 1);
    list = list->next;
  }
} 

void list_free(void) {    /* No need for arguments since the list we want to free is declared as global */
  while (list != NULL) {
    listnode* tmp_node = list;
    list = list->next;
    free(tmp_node);
  }
} 