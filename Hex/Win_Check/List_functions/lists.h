typedef struct lnode {      
  int let;          /* A list node stores the coordinates of a hex */
  int num;          /* (let = col, num = row) */
  struct lnode* next;
} listnode;

listnode* list;    /* Global list used to store the winning path */

listnode* ins_at_start(listnode* list, int let, int num);           /* a hex that's on the left (lower) or on the right (upper) of our current hex if we're white (black) */                        

void list_free(void);                             /* it is set to 1 when moving to the right (upper) hex, -1 when moving to the left (lower) hex, 0 when moving to lower (right) hexes */
void list_print(listnode* list);