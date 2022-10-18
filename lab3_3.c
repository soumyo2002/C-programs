/*WAP using switch cases to perform the following operations.
i) create a linked list, 
ii) display its element
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *link;
};

void insert();
void display();


typedef struct node DATA_NODE;

DATA_NODE *head_node, *first_node, *temp_node = 0, *prev_node, next_node;
int data;

int main() {
  int option = 0;
  while (option < 5) {

    printf("\nOptions\n");
    printf("1 : Insert into Linked List \n");
    printf("2 : Display Linked List\n");
    printf("Others : leave()\n");
    printf("Enter your option: \n");
    scanf("%d", &option);
    switch (option) {
      case 1:
        insert();
        break;
      case 2:
        display();
        break;
      default:
        break;
    }
  }

  return 0;
}

void insert() {
  printf("\nEnter Element for Insert Linked List : \n");
  scanf("%d", &data);

  temp_node = (DATA_NODE *) malloc(sizeof (DATA_NODE));

  temp_node->info = data;

  if (first_node == 0) {
    first_node = temp_node;
  } else {
    head_node->link = temp_node;
  }
  temp_node->link = 0;
  head_node = temp_node;
  fflush(stdin);
}

void display() {
  int count = 0;
  temp_node = first_node;
  printf("\nDisplay Linked List : \n");
  while (temp_node != 0) {
    printf("%d ", temp_node->info);
    count++;
    temp_node = temp_node->link;
  }
}