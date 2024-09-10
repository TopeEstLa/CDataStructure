#include <list.h>

#include <stdio.h>

List *createList() {
    List *list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }

    list->head = NULL;
    list->size = 0;
    return list;
}

int append(List *list, void *data) {
    if (list == NULL) return -1;
    if (data == NULL) return -1;

    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    list->size++;
    return list->size-1;
}

bool prepend(List *list, void *data) {
    if (list == NULL) return false;
    if (data == NULL) return false;

    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return false;
    }

    newNode->data = data;
    newNode->next = list->head;

    list->head = newNode;
    list->size++;

    return true;
}

bool addAt(List *list, void *data, int index) {
    if (list == NULL) return false;
    if (data == NULL) return false;

    if (index < 0 || index > list->size) {
        return false;
    }

    if (index == 0) {
        return prepend(list, data);
    }

    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return false;
    }

    newNode->data = data;

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    list->size++;
    return true;
}

bool removeLast(List *list) {
    if (list == NULL) return false;

    if (list->head == NULL) {
        return false; //nothing to remove here
    }

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        Node *current = list->head; // (1) (2) (3) //we want to check if the next node is the last
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }

    list->size--;
    return true;
}

bool removeFirst(List *list) {
    if (list == NULL) return false;

    if (list->head == NULL) {
        return false; //nothing to remove here
    }

    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);

    list->size--;
    return true;
}

bool removeAt(List *list, int index) {
    if (list == NULL) return false;

    if (index < 0 || index >= list->size) {
        return false;
    }

    if (index == 0) {
        return removeFirst(list);
    }

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);

    list->size--;
    return true;
}

void* get(List *list, int index) {
    if (list == NULL) return false;

    if (index < 0 || index >= list->size) {
        return NULL;
    }

    Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

List* reverseList(List *list) {
    if (list == NULL) return NULL;

    List *reversedList = createList();
    if (reversedList == NULL) {
        return NULL;
    }

    Node *current = list->head;
    while (current != NULL) {
        prepend(reversedList, current->data);
        current = current->next;
    }

    return reversedList;
}

void printList(List *list) {
    if (list == NULL) return;

    Node *current = list->head;
    printf("[ ");
    while (current != NULL) {
        printf("%d, ", *(int*)current->data);
        current = current->next;
    }
    printf(" ]");
    printf("\n");
}