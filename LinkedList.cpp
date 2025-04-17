
#include "list.h"

NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode == NULL) return NULL;
    newNode->key = data;
    newNode->p_next = NULL;
    return newNode;
}

List* createList(NODE* p_node) {
    List* newList = (List*)malloc(sizeof(List));
    if (newList == NULL) return NULL;
    newList->p_head = p_node;
    newList->p_tail = p_node;
    return newList;
}

bool addHead(List* L, int data) {
    if (L == NULL) return false;

    NODE* newNode = createNode(data);
    if (newNode == NULL) return false;

    if (L->p_head == NULL) {
        L->p_head = newNode;
        L->p_tail = newNode;
    }
    else {
        newNode->p_next = L->p_head;
        L->p_head = newNode;
    }

    return true;
}

bool addTail(List* L, int data) {
    if (L == NULL) return false;

    NODE* newNode = createNode(data);
    if (newNode == NULL) return false;

    if (L->p_head == NULL) {
        L->p_head = newNode;
        L->p_tail = newNode;
    }
    else {
        L->p_tail->p_next = newNode;
        L->p_tail = newNode;
    }

    return true;
}

bool removeHead(List* L) {
    if (L == NULL || L->p_head == NULL) return false;

    NODE* temp = L->p_head;

    if (L->p_head == L->p_tail) {
        L->p_head = NULL;
        L->p_tail = NULL;
    }
    else {
        L->p_head = L->p_head->p_next;
    }

    free(temp);
    return true;
}

void removeTail(List* L) {
    if (L == NULL || L->p_head == NULL) return;

    if (L->p_head == L->p_tail) {
        free(L->p_tail);
        L->p_head = NULL;
        L->p_tail = NULL;
    }
    else {
        NODE* current = L->p_head;
        while (current->p_next != L->p_tail) {
            current = current->p_next;
        }

        free(L->p_tail);
        current->p_next = NULL;
        L->p_tail = current;
    }
}

void removeAll(List* L) {
    if (L == NULL) return;

    NODE* current = L->p_head;
    while (current != NULL) {
        NODE* temp = current;
        current = current->p_next;
        free(temp);
    }

    L->p_head = NULL;
    L->p_tail = NULL;
}

void removeBefore(List* L, int val) {
    if (L == NULL || L->p_head == NULL || L->p_head->p_next == NULL) return;
    if (L->p_head->p_next->key == val) {
        removeHead(L);
        return;
    }

    NODE* prev = L->p_head;
    NODE* curr = prev->p_next;
    NODE* next = curr->p_next;

    while (next != NULL && next->key != val) {
        prev = curr;
        curr = next;
        next = next->p_next;
    }

    if (next == NULL) return;

    prev->p_next = next;
    free(curr);
}

void removeAfter(List* L, int val) {
    if (L == NULL || L->p_head == NULL) return;

    NODE* curr = L->p_head;
    while (curr != NULL && curr->key != val) {
        curr = curr->p_next;
    }

    if (curr == NULL || curr->p_next == NULL) return;

    NODE* toDelete = curr->p_next;
    curr->p_next = toDelete->p_next;

    if (toDelete == L->p_tail) {
        L->p_tail = curr;
    }

    free(toDelete);
}

bool addPos(List* L, int data, int pos) {
    if (L == NULL || pos < 0) return false;

    if (pos == 0) return addHead(L, data);

    NODE* newNode = createNode(data);
    if (newNode == NULL) return false;

    NODE* curr = L->p_head;
    int idx = 0;

    while (curr != NULL && idx < pos - 1) {
        curr = curr->p_next;
        idx++;
    }

    if (curr == NULL) {
        return addTail(L, data);
    }

    newNode->p_next = curr->p_next;
    curr->p_next = newNode;

    if (curr == L->p_tail) {
        L->p_tail = newNode;
    }

    return true;
}

void removePos(List* L, int pos) {
    if (L == NULL || L->p_head == NULL || pos < 0) return;

    if (pos == 0) {
        removeHead(L);
        return;
    }

    NODE* prev = L->p_head;
    int idx = 0;

    while (prev != NULL && idx < pos - 1) {
        prev = prev->p_next;
        idx++;
    }

    if (prev == NULL || prev->p_next == NULL) return;

    NODE* toDelete = prev->p_next;
    prev->p_next = toDelete->p_next;

    if (toDelete == L->p_tail) {
        L->p_tail = prev;
    }

    free(toDelete);
}

bool addBefore(List* L, int data, int val) {
    if (L == NULL || L->p_head == NULL) return false;

    if (L->p_head->key == val) {
        return addHead(L, data);
    }

    NODE* prev = L->p_head;
    NODE* curr = prev->p_next;

    while (curr != NULL && curr->key != val) {
        prev = curr;
        curr = curr->p_next;
    }

    if (curr == NULL) return false;

    NODE* newNode = createNode(data);
    if (newNode == NULL) return false;

    newNode->p_next = curr;
    prev->p_next = newNode;
    return true;
}

bool addAfter(List* L, int data, int val) {
    if (L == NULL || L->p_head == NULL) return false;

    NODE* curr = L->p_head;
    while (curr != NULL && curr->key != val) {
        curr = curr->p_next;
    }

    if (curr == NULL) return false;

    NODE* newNode = createNode(data);
    if (newNode == NULL) return false;

    newNode->p_next = curr->p_next;
    curr->p_next = newNode;

    if (curr == L->p_tail) {
        L->p_tail = newNode;
    }

    return true;
}

void printList(const List* L) {
    NODE* curr = L->p_head;
    while (curr != NULL) {
        printf("%d", curr->key);
        if (curr->p_next != NULL) {
            printf(" -> ");
        }
        curr = curr->p_next;
    }
    printf("\n");
}

int countElements(const List* L) {
    int count = 0;
    NODE* curr = L->p_head;
    while (curr != NULL) {
        count++;
        curr = curr->p_next;
    }
    return count;
}

List* reverseList(const List* L) {
    if (L == NULL) return NULL;

    List* rev = createList(NULL);
    NODE* curr = L->p_head;
    while (curr != NULL) {
        addHead(rev, curr->key);
        curr = curr->p_next;
    }

    return rev;
}

void removeDuplicate(List* L) {
    if (L == NULL || L->p_head == NULL) return;

    NODE* curr = L->p_head;
    while (curr != NULL) {
        NODE* prev = curr;
        NODE* scan = curr->p_next;

        while (scan != NULL) {
            if (scan->key == curr->key) {
                NODE* toDelete = scan;
                prev->p_next = scan->p_next;

                if (toDelete == L->p_tail) {
                    L->p_tail = prev;
                }

                scan = scan->p_next;
                free(toDelete);
            }
            else {
                prev = scan;
                scan = scan->p_next;
            }
        }

        curr = curr->p_next;
    }
}

bool removeElement(List* L, int key) {
    if (!L || !L->p_head) return false;
    if (L->p_head->key == key) {
        return removeHead(L);
    }

    NODE* prev = L->p_head;
    NODE* curr = L->p_head->p_next;

    while (curr) {
        if (curr->key == key) {
            prev->p_next = curr->p_next;
            if (curr == L->p_tail) {
                L->p_tail = prev;
            }
            free(curr);
            return true;
        }
        prev = curr;
        curr = curr->p_next;
    }
    return false;
}


// ham test
bool test_createNode() {
    NODE* n = createNode(10);
    return n && n->key == 10 && n->p_next == nullptr;
}

bool test_createList() {
    NODE* n = createNode(5);
    List* L = createList(n);
    return L && L->p_head == n && L->p_tail == n;
}

bool test_addHead(List* L) {
    addHead(L, 1);
    return L->p_head && L->p_head->key == 1;
}

bool test_addTail(List* L) {
    addTail(L, 2);
    return L->p_tail && L->p_tail->key == 2;
}

bool test_removeHead(List* L) {
    int before = countElements(L);
    removeHead(L);
    return countElements(L) == before - 1;
}

bool test_removeTail(List* L) {
    int before = countElements(L);
    removeTail(L);
    return countElements(L) == before - 1;
}

bool test_addPos(List* L) {
    addHead(L, 1);
    addTail(L, 3);
    bool ok = addPos(L, 2, 1);
    NODE* temp = L->p_head->p_next;
    return ok && temp && temp->key == 2;
}

bool test_removePos(List* L) {
    int before = countElements(L);
    removePos(L, 1);
    return countElements(L) == before - 1;
}

bool test_addBefore(List* L) {
    return addBefore(L, 5, 3);
}

bool test_addAfter(List* L) {
    return addAfter(L, 4, 3);
}

bool test_removeBefore(List* L) {
    int before = countElements(L);
    removeBefore(L, 3);
    return countElements(L) == before - 1;
}

bool test_removeAfter(List* L) {
    int before = countElements(L);
    removeAfter(L, 3);
    return countElements(L) == before - 1;
}

bool test_removeElement(List* L) {
    addTail(L, 99);
    return removeElement(L, 99);
}

bool test_removeAll(List* L) {
    removeAll(L);
    return L->p_head == nullptr && L->p_tail == nullptr;
}

bool test_countElements(List* L) {
    addTail(L, 1);
    addTail(L, 2);
    addTail(L, 3);
    return countElements(L) == 3;
}

bool test_printList(List* L) {
    printList(L);
    return true;
}

bool test_reverseList(List* L) {
    List* R = reverseList(L);
    if (!R) return false;
    return (R->p_head->key == 3 && R->p_tail->key == 1);
}

bool test_removeDuplicate(List* L) {
    addTail(L, 2);
    addTail(L, 2);
    int before = countElements(L);
    removeDuplicate(L);
    return countElements(L) == before - 1;
}
