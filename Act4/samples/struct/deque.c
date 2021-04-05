#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char* content;
  struct Node* prev;
  struct Node* next;
};

struct Node* head = 0;
struct Node* tail = 0;

struct Node* insert_head(char* str)
{
  struct Node* n = (struct Node*)malloc(sizeof(struct Node));
  n->content = (char*)malloc(strlen(str)+1);
  n->prev = n->next = 0;
  strcpy(n->content, str);

  if(!head) head = tail = n;
  else {
    n->next = head;
    head->prev = n;
    head = n;
  }
  return n;
}

struct Node* insert_tail(char* str)
{
  struct Node* n = (struct Node*)malloc(sizeof(struct Node));
  n->content = (char*)malloc(strlen(str)+1);
  n->prev = n->next = 0;
  strcpy(n->content, str);
  if(!tail) head = tail = n;
  else {
    n->prev = tail;
    tail->next = n;
    tail = n;
  }
  return n;
}

void list_elements()
{
  struct Node* p = head;
  while(p) {
    printf("%s\n", p->content);
    p = p->next;
  }
}

void delete_node(struct Node* p)
{
  if(!p->prev) { // I'm at the head
    head = p->next;
    if(head) head->prev = 0;
  } else { // I'm not at the head
    p->prev->next = p->next;
    if(p->next) p->next->prev = p->prev;
  }

  if(!p->next) { // I'm at the tail
    tail = p->prev;
    if(tail) tail->next = 0;
  } else { // I'm not at the tail
    p->next->prev = p->prev;
    if(p->prev) p->prev->next = p->next;
  }

  free(p->content);
  free(p);
}


int main()
{
  struct Node* p2;

  insert_head("1");
  p2 = insert_head("2");
  insert_tail("3");
  insert_head("4");
  insert_tail("5");
  list_elements();

  delete_node(p2);
  list_elements();

  return 0;
}

