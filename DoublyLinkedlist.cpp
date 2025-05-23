#include "list.h"

d_NODE* createDNode(int data) {
    d_NODE* newNode = (d_NODE*)malloc(sizeof(d_NODE));
    if (!newNode) return NULL;
    newNode->key = data;
    newNode->pNext = NULL;
    newNode->pPrev = NULL;
    return newNode;
}

d_List* createDList(d_NODE* p_node) {
    d_List* newList = (d_List*)malloc(sizeof(d_List));
    if (!newList) return NULL;
    newList->pHead = p_node;
    newList->pTail = p_node;
    return newList;
}

bool addHeadD(d_List* L, int data) {
    if (!L) return false;

    d_NODE* newNode = createDNode(data);
    if (!newNode) return false;

    if (!L->pHead) {
        L->pHead = L->pTail = newNode;
    }
    else {
        newNode->pNext = L->pHead;
        L->pHead->pPrev = newNode;
        L->pHead = newNode;
    }
    return true;
}

bool addTailD(d_List* L, int data) {
    if (!L) return false;

    d_NODE* newNode = createDNode(data);
    if (!newNode) return false;

    if (!L->pTail) {
        L->pHead = L->pTail = newNode;
    }
    else {
        newNode->pPrev = L->pTail;
        L->pTail->pNext = newNode;
        L->pTail = newNode;
    }
    return true;
}

bool removeHeadD(d_List* L) {
    if (!L || !L->pHead) return false;

    d_NODE* temp = L->pHead;
    if (L->pHead == L->pTail) {
        L->pHead = L->pTail = NULL;
    }
    else {
        L->pHead = L->pHead->pNext;
        L->pHead->pPrev = NULL;
    }
    free(temp);
    return true;
}

void removeTailD(d_List* L) {
    if (!L || !L->pTail) return;

    d_NODE* temp = L->pTail;
    if (L->pHead == L->pTail) {
        L->pHead = L->pTail = NULL;
    }
    else {
        L->pTail = L->pTail->pPrev;
        L->pTail->pNext = NULL;
    }
    free(temp);
}

void removeAllD(d_List* L) {
    if (!L) return;
    d_NODE* curr = L->pHead;
    while (curr) {
        d_NODE* temp = curr;
        curr = curr->pNext;
        free(temp);
    }
    L->pHead = L->pTail = NULL;
}

void removeBeforeD(d_List* L, int val) {
    if (!L || !L->pHead || !L->pHead->pNext) return;

    d_NODE* curr = L->pHead->pNext;
    while (curr && curr->key != val) {
        curr = curr->pNext;
    }

    if (!curr || !curr->pPrev) return;

    d_NODE* toDelete = curr->pPrev;
    if (toDelete->pPrev) {
        toDelete->pPrev->pNext = curr;
        curr->pPrev = toDelete->pPrev;
    }
    else {
        L->pHead = curr;
        curr->pPrev = NULL;
    }
    free(toDelete);
}

void removeAfterD(d_List* L, int val) {
    if (!L || !L->pHead) return;

    d_NODE* curr = L->pHead;
    while (curr && curr->key != val) {
        curr = curr->pNext;
    }

    if (!curr || !curr->pNext) return;

    d_NODE* toDelete = curr->pNext;
    curr->pNext = toDelete->pNext;

    if (toDelete->pNext) {
        toDelete->pNext->pPrev = curr;
    }
    else {
        L->pTail = curr;
    }

    free(toDelete);
}

bool addPosD(d_List* L, int data, int pos) {
    if (!L || pos < 0) return false;

    if (pos == 0) return addHeadD(L, data);

    d_NODE* curr = L->pHead;
    int idx = 0;
    while (curr && idx < pos - 1) {
        curr = curr->pNext;
        idx++;
    }

    if (!curr || !curr->pNext) return addTailD(L, data);

    d_NODE* newNode = createDNode(data);
    if (!newNode) return false;

    newNode->pNext = curr->pNext;
    newNode->pPrev = curr;
    curr->pNext->pPrev = newNode;
    curr->pNext = newNode;

    return true;
}

void removePosD(d_List* L, int pos) {
    if (!L || !L->pHead || pos < 0) return;

    if (pos == 0) {
        removeHeadD(L);
        return;
    }

    d_NODE* curr = L->pHead;
    int idx = 0;
    while (curr && idx < pos) {
        curr = curr->pNext;
        idx++;
    }

    if (!curr) return;

    if (curr->pPrev) curr->pPrev->pNext = curr->pNext;
    if (curr->pNext) curr->pNext->pPrev = curr->pPrev;

    if (curr == L->pHead) L->pHead = curr->pNext;
    if (curr == L->pTail) L->pTail = curr->pPrev;

    free(curr);
}

bool addBeforeD(d_List* L, int data, int val) {
    if (!L || !L->pHead) return false;

    d_NODE* curr = L->pHead;
    while (curr && curr->key != val) {
        curr = curr->pNext;
    }

    if (!curr) return false;
    if (curr == L->pHead) return addHeadD(L, data);

    d_NODE* newNode = createDNode(data);
    if (!newNode) return false;

    newNode->pPrev = curr->pPrev;
    newNode->pNext = curr;
    curr->pPrev->pNext = newNode;
    curr->pPrev = newNode;

    return true;
}

bool addAfterD(d_List* L, int data, int val) {
    if (!L || !L->pHead) return false;

    d_NODE* curr = L->pHead;
    while (curr && curr->key != val) {
        curr = curr->pNext;
    }

    if (!curr) return false;

    d_NODE* newNode = createDNode(data);
    if (!newNode) return false;

    newNode->pNext = curr->pNext;
    newNode->pPrev = curr;
    if (curr->pNext) {
        curr->pNext->pPrev = newNode;
    }
    else {
        L->pTail = newNode;
    }
    curr->pNext = newNode;

    return true;
}

void printDList(const d_List* L) {
    d_NODE* curr = L->pHead;
    while (curr) {
        printf("%d", curr->key);
        if (curr->pNext) printf(" <-> ");
        curr = curr->pNext;
    }
    printf("\n");
}

int countDElements(const d_List* L) {
    int count = 0;
    d_NODE* curr = L->pHead;
    while (curr) {
        count++;
        curr = curr->pNext;
    }
    return count;
}

d_List* reverseDList(const d_List* L) {
    if (!L) return NULL;
    d_List* rev = createDList(NULL);
    d_NODE* curr = L->pTail;
    while (curr) {
        addTailD(rev, curr->key);
        curr = curr->pPrev;
    }
    return rev;
}

void removeDuplicateD(d_List* L) {
    if (!L || !L->pHead) return;

    d_NODE* curr = L->pHead;
    while (curr) {
        d_NODE* runner = curr->pNext;
        while (runner) {
            if (runner->key == curr->key) {
                d_NODE* toDelete = runner;
                runner = runner->pNext;

                if (toDelete->pPrev) toDelete->pPrev->pNext = toDelete->pNext;
                if (toDelete->pNext) toDelete->pNext->pPrev = toDelete->pPrev;

                if (toDelete == L->pTail) L->pTail = toDelete->pPrev;

                free(toDelete);
            }
            else {
                runner = runner->pNext;
            }
        }
        curr = curr->pNext;
    }
}

bool removeElementD(d_List* L, int key) {
    if (!L || !L->pHead) return false;

    d_NODE* curr = L->pHead;
    while (curr && curr->key != key) {
        curr = curr->pNext;
    }

    if (!curr) return false;

    if (curr->pPrev) curr->pPrev->pNext = curr->pNext;
    else L->pHead = curr->pNext;

    if (curr->pNext) curr->pNext->pPrev = curr->pPrev;
    else L->pTail = curr->pPrev;

    free(curr);
    return true;
}



// ham test
bool test_createDNode() {
    d_NODE* node = createDNode(10);
    return node && node->key == 10 && node->pNext == nullptr && node->pPrev == nullptr;
}

bool test_createDList() {
    d_NODE* node = createDNode(20);
    d_List* L = createDList(node);
    return L && L->pHead == node && L->pTail == node;
}

bool test_addHeadD(d_List* L) {
    addHeadD(L, 5);
    return L->pHead && L->pHead->key == 5;
}

bool test_addTailD(d_List* L) {
    addTailD(L, 10);
    return L->pTail && L->pTail->key == 10;
}

bool test_removeHeadD(d_List* L) {
    int before = countDElements(L);
    removeHeadD(L);
    return countDElements(L) == before - 1;
}

bool test_removeTailD(d_List* L) {
    int before = countDElements(L);
    removeTailD(L);
    return countDElements(L) == before - 1;
}

bool test_addPosD(d_List* L) {
    addHeadD(L, 1);
    addTailD(L, 3);
    bool ok = addPosD(L, 2, 1);
    d_NODE* second = L->pHead->pNext;
    return ok && second && second->key == 2;
}

bool test_removePosD(d_List* L) {
    int before = countDElements(L);
    removePosD(L, 1);
    return countDElements(L) == before - 1;
}

bool test_addBeforeD(d_List* L) {
    return addBeforeD(L, 6, 3);
}

bool test_addAfterD(d_List* L) {
    return addAfterD(L, 7, 3);
}

bool test_removeBeforeD(d_List* L) {
    int before = countDElements(L);
    removeBeforeD(L, 3);
    return countDElements(L) == before - 1;
}

bool test_removeAfterD(d_List* L) {
    int before = countDElements(L);
    removeAfterD(L, 3);
    return countDElements(L) == before - 1;
}

bool test_removeElementD(d_List* L) {
    addTailD(L, 99);
    return removeElementD(L, 99);
}

bool test_removeAllD(d_List* L) {
    removeAllD(L);
    return L->pHead == nullptr && L->pTail == nullptr;
}

bool test_countDElements(d_List* L) {
    addTailD(L, 1);
    addTailD(L, 2);
    addTailD(L, 3);
    return countDElements(L) == 3;
}

bool test_printDList(d_List* L) {
    printDList(L);
    return true;
}

bool test_reverseDList(d_List* L) {
    d_List* rev = reverseDList(L);
    if (!rev || !rev->pHead) return false;
    return rev->pHead->key == 3 && rev->pTail->key == 1;
}

bool test_removeDuplicateD(d_List* L) {
    addTailD(L, 2);
    addTailD(L, 2);
    int before = countDElements(L);
    removeDuplicateD(L);
    return countDElements(L) == before - 1;
}
