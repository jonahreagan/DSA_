#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* addLists(Node* list1, Node* list2) {
    Node *result = NULL;
    int carry = 0;

    while (list1 || list2 || carry) {
        int sum = carry;
        if (list1) {
            sum += list1->data;
            list1 = list1->prev;
        }
        if (list2) {
            sum += list2->data;
            list2 = list2->prev;
        }
        append(&result, sum % 10);
        carry = sum / 10;
    }

    return result;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    while (head) {
        Node* next = head->next;
        head->next = prev;
        head->prev = next;
        prev = head;
        head = next;
    }
    return prev;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    append(&list1, 2);
    append(&list1, 5);
    append(&list1, 9);

    append(&list2, 3);
    append(&list2, 8);
    append(&list2, 1);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    Node* sumList = addLists(reverseList(list1), reverseList(list2));
    printf("Sum List: ");
    printList(reverseList(sumList));

    return 0;
}
