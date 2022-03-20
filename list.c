#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
      List* Lista=(List*)malloc(sizeof(List));
      Lista->head=NULL;
      Lista->current=NULL;
      Lista->tail=NULL;
      return Lista;
}

void * firstList(List * list) {
    if (list->head==NULL)
      return NULL;
    list->current=list->head;
    return list->current->data;    
}

void * nextList(List * list) {
    if(list->current==NULL)
  {
    return NULL;
  }
   if(list->current->next!=NULL)
  {
    void* dato=(void*)list->current->next->data;
    list->current=list->current->next;
    return dato;
  }
  return NULL;
}

void * lastList(List * list) {
    void* dato=(void*)list->tail->data;
    list->current=list->tail;
    return dato;
}

void * prevList(List * list) {
    void* dato=(void*)list->prev->data;
    list->current=list->prev;
    return dato;
}

void pushFront(List * list, void * data) {
  Node* n=createNode(data);
  n->next=list->head;
  if(list->head)
  {
    list->head->prev=n;
  }
  list->head=n;
  n->prev=NULL;
  list->tail=n;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Nodo* newN = crearNodo( data);
  Nodo* auxN = list->current;
  Nodo* Acurr = auxN->prev;
  if(auxN->prev == NULL){
  auxN->prev = newN;
  newN->next = auxN;
  list->head = newN;
  }
  else{
  Acurr->next = newN;
  newN->prev = Acurr;
  auxN->prev = newN;
  newN->next = auxN;
}
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}