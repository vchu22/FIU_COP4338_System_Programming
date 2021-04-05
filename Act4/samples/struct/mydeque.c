#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct LinkedList {
  struct Node* head;
  struct Node* tail;
  int n;
};

struct LinkedList* create_linked_list()
{
  struct LinkedList* newone = 
    (struct LinkedList*)malloc(sizeof(struct LinkedList));
  newone->head = newone->tail = 0;
  newone->n = 0;
  return newone;
}

void destroy_linked_list(struct LinkedList* list)
{
  if(list) {
    struct Node* n = list->head;
    while(n) {
      struct Node* nxt = n->next;
      free(n);
      n = nxt;
    }
    free(list);
  }
}

void add_to_head(struct LinkedList* list, int data)
{
  if(list) {
    struct Node* node = 
      (struct Node*)malloc(sizeof(struct Node*));
    node->data = data;

    node->prev = 0;
    node->next = list->head;
    if(list->head) {
      list->head->prev = node;
      list->head = node;
    } else list->head = list->tail = node;
    list->n++;
  }
}

void add_to_tail(struct LinkedList* list, int data)
{
  if(list) {
    struct Node* node = 
      (struct Node*)malloc(sizeof(struct Node*));
    node->data = data;

    node->next = 0;
    node->prev = list->tail;
    if(list->tail) {
      list->tail->next = node;
      list->tail = node;
    } else list->head = list->tail = node;
    list->n++;
  }
}

int remove_from_head(struct LinkedList* list)
{
  if(list && list->n > 0) {
    struct Node* node = list->head;
    list->head = node->next;
    if(list->head) list->head->prev = 0;
    else list->tail = 0;
    list->n--;
    int tmp = node->data;
    free(node);
    return tmp;
  } else return -1;
}

int remove_from_tail(struct LinkedList* list)
{
  if(list && list->n > 0) {
    struct Node* node = list->tail;
    list->tail = node->prev;
    if(list->tail) list->tail->next = 0;
    else list->head = 0;
    list->n--;
    int tmp = node->data;
    free(node);
    return tmp;
  } else return -1;
}

/* merge the two lists, return a new one, and destroy the two old ones. */
struct LinkedList* merge_linked_list(struct LinkedList* list1, struct LinkedList* list2)
{
  if(!list1) return list2;
  else if(!list1->head) { free(list1); return list2; }
  else if(!list2) return list1;
  else if(!list2->head) { free(list2); return list1; }
  else {
    list1->tail->next = list2->head;
    list2->head->prev = list1->tail;
    list1->tail = list2->tail;
    list1->n += list2->n;
    free(list2);
    return list1;
  }
}

int main()
{
  int k;
  struct LinkedList* l1 = create_linked_list();
  struct LinkedList* l2 = create_linked_list();
  add_to_head(l1, 5);
  add_to_head(l1, 6);
  add_to_tail(l1, 10);
  add_to_head(l2, 17);
  add_to_tail(l2, 0);

  /*
  k = remove_from_head(l2);
  printf("k=%d\n", k);
  k = remove_from_tail(l2);
  printf("k=%d\n", k);
  */

  /*l1 = merge_linked_list(l1, l2);*/
  while(l1->n > 0) {
    printf("%d\n", remove_from_head(l1));
  }
  destroy_linked_list(l1);

  return 0;
}
