#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdio.h> 
#include <iostream>
#include <stdlib.h>
using namespace std;

struct NODE {
    int key;
    struct NODE* p_next;
};

struct List {
    NODE* p_head;
    NODE* p_tail;
};


struct d_NODE {
    int key;
    d_NODE* pNext;
    d_NODE* pPrev;
};

struct d_List {
    d_NODE* pHead;
    d_NODE* pTail;
};
// Prototype các hàm
NODE* createNode(int data);
List* createList(NODE* p_node);
bool addHead(List* L, int data);
bool addTail(List* L, int data);
bool removeHead(List* L);
void removeTail(List* L);
void removeAll(List* L);
void removeBefore(List* L, int val);
void removeAfter(List* L, int val);
bool addPos(List* L, int data, int pos);
void removePos(List* L, int pos);
bool addBefore(List* L, int data, int val);
bool addAfter(List* L, int data, int val);
void printList(const List* L);
int countElements(const List* L);
List* reverseList(const List* L);
void removeDuplicate(List* L);
bool removeElement(List* L, int key);


d_NODE* createDNode(int data);
d_List* createDList(d_NODE* p_node);
bool addHeadD(d_List* L, int data);
bool addTailD(d_List* L, int data);
bool removeHeadD(d_List* L);
void removeTailD(d_List* L);
void removeAllD(d_List* L);
void removeBeforeD(d_List* L, int val);
void removeAfterD(d_List* L, int val);
bool addPosD(d_List* L, int data, int pos);
void removePosD(d_List* L, int pos);
bool addBeforeD(d_List* L, int data, int val);
bool addAfterD(d_List* L, int data, int val);
void printDList(const d_List* L);
int countDElements(const d_List* L);
d_List* reverseDList(const d_List* L);
void removeDuplicateD(d_List* L);
bool removeElementD(d_List* L, int key);


bool test_createNode();
bool test_createList();
bool test_addHead(List* L);
bool test_addTail(List* L);
bool test_removeHead(List* L);
bool test_removeTail(List* L);
bool test_addPos(List* L);
bool test_removePos(List* L);
bool test_addBefore(List* L);
bool test_addAfter(List* L);
bool test_removeBefore(List* L);
bool test_removeAfter(List* L);
bool test_removeElement(List* L);
bool test_removeAll(List* L);
bool test_countElements(List* L);
bool test_printList(List* L);
bool test_reverseList(List* L);
bool test_removeDuplicate(List* L);

bool test_createDNode();
bool test_createDList();
bool test_addHeadD(d_List* L);
bool test_addTailD(d_List* L);
bool test_removeHeadD(d_List* L);
bool test_removeTailD(d_List* L);
bool test_addPosD(d_List* L);
bool test_removePosD(d_List* L);
bool test_addBeforeD(d_List* L);
bool test_addAfterD(d_List* L);
bool test_removeBeforeD(d_List* L);
bool test_removeAfterD(d_List* L);
bool test_removeElementD(d_List* L);
bool test_removeAllD(d_List* L);
bool test_countDElements(d_List* L);
bool test_printDList(d_List* L);
bool test_reverseDList(d_List* L);
bool test_removeDuplicateD(d_List* L);

#endif
