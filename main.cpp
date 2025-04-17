#include "list.h"

int main() {

    NODE* node = createNode(100);
    List* list = createList(node);

    cout << "1. createNode: " << (test_createNode() ? "Passed" : "Failed") << endl;
    cout << "2. createList: " << (test_createList() ? "Passed" : "Failed") << endl;
    cout << "3. addHead: " << (test_addHead(list) ? "Passed" : "Failed") << endl;
    cout << "4. addTail: " << (test_addTail(list) ? "Passed" : "Failed") << endl;
    cout << "5. removeHead: " << (test_removeHead(list) ? "Passed" : "Failed") << endl;
    cout << "6. removeTail: " << (test_removeTail(list) ? "Passed" : "Failed") << endl;
    cout << "7. addPos: " << (test_addPos(list) ? "Passed" : "Failed") << endl;
    cout << "8. removePos: " << (test_removePos(list) ? "Passed" : "Failed") << endl;
    cout << "9. addBefore: " << (test_addBefore(list) ? "Passed" : "Failed") << endl;
    cout << "10. addAfter: " << (test_addAfter(list) ? "Passed" : "Failed") << endl;
    cout << "11. removeBefore: " << (test_removeBefore(list) ? "Passed" : "Failed") << endl;
    cout << "12. removeAfter: " << (test_removeAfter(list) ? "Passed" : "Failed") << endl;
    cout << "13. removeElement: " << (test_removeElement(list) ? "Passed" : "Failed") << endl;
    cout << "14. removeAll: " << (test_removeAll(list) ? "Passed" : "Failed") << endl;
    cout << "15. countElements: " << (test_countElements(list) ? "Passed" : "Failed") << endl;
    cout << "16. printList: " << (test_printList(list) ? "Passed" : "Failed") << endl;
    cout << "17. reverseList: " << (test_reverseList(list) ? "Passed" : "Failed") << endl;
    cout << "18. removeDuplicate: " << (test_removeDuplicate(list) ? "Passed" : "Failed") << endl;



    d_NODE* Node = createDNode(100);
    d_List* List = createDList(Node);

    cout << "1. createDNode: " << (test_createDNode() ? "Passed" : "Failed") << endl;
    cout << "2. createDList: " << (test_createDList() ? "Passed" : "Failed") << endl;
    cout << "3. addHeadD: " << (test_addHeadD(List) ? "Passed" : "Failed") << endl;
    cout << "4. addTailD: " << (test_addTailD(List) ? "Passed" : "Failed") << endl;
    cout << "5. removeHeadD: " << (test_removeHeadD(List) ? "Passed" : "Failed") << endl;
    cout << "6. removeTailD: " << (test_removeTailD(List) ? "Passed" : "Failed") << endl;
    cout << "7. addPosD: " << (test_addPosD(List) ? "Passed" : "Failed") << endl;
    cout << "8. removePosD: " << (test_removePosD(List) ? "Passed" : "Failed") << endl;
    cout << "9. addBeforeD: " << (test_addBeforeD(List) ? "Passed" : "Failed") << endl;
    cout << "10. addAfterD: " << (test_addAfterD(List) ? "Passed" : "Failed") << endl;
    cout << "11. removeBeforeD: " << (test_removeBeforeD(List) ? "Passed" : "Failed") << endl;
    cout << "12. removeAfterD: " << (test_removeAfterD(List) ? "Passed" : "Failed") << endl;
    cout << "13. removeElementD: " << (test_removeElementD(List) ? "Passed" : "Failed") << endl;
    cout << "14. removeAllD: " << (test_removeAllD(List) ? "Passed" : "Failed") << endl;
    cout << "15. countDElements: " << (test_countDElements(List) ? "Passed" : "Failed") << endl;
    cout << "16. printDList: " << (test_printDList(List) ? "Passed" : "Failed") << endl;
    cout << "17. reverseDList: " << (test_reverseDList(List) ? "Passed" : "Failed") << endl;
    cout << "18. removeDuplicateD: " << (test_removeDuplicateD(List) ? "Passed" : "Failed") << endl;

    return 0;
}
