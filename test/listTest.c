#include <list.h>

#include <stdio.h>

void main() {
    List *list = createList();
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int g = 50;
    int v = 100;
    int x = 200;

    //Testing the append function
    printf("Testing append function\n");
    append(list, &a);
    append(list, &b);
    append(list, &c);
    append(list, &d);
    append(list, &e);
    printList(list);
    prepend(list, &g);
    printList(list);
    addAt(list, &v, 3);
    printList(list);
    append(list, &x);
    printList(list);
    //ok where are ok for append now remove
    printf("Testing remove function\n");
    removeLast(list);
    printList(list);
    removeAt(list, 3);
    printList(list);
    removeFirst(list);
    printList(list);
    //now trying to get value
    printf("Testing get function\n");
    printf("%d\n", *(int*)get(list, 0));
    printf("%d\n", *(int*)get(list, 1));
    printf("%d\n", *(int*)get(list, 2));
    printf("%d\n", *(int*)get(list, 3));
    printf("%d\n", *(int*)get(list, 4));

    //testing reverseList
    List* reversedList = reverseList(list);
    printList(reversedList);
}
