#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;            
    struct Node* next;  
} Node;


Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void insertHead(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}


void insertEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void deleteHead(Node** head) {
    if (*head == NULL) {
        printf("rong\n");
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    free(temp);
    printf("xoa dau tien\n");
}

void deleteEnd(Node** head) {
   
     if (*head == NULL) {
     	   printf("rong\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}


void printList(Node* head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



int main() {
    Node* head = NULL; 
    int choice;
    int value;

    do {
        printf("\n=========== MENU ===========\n");
        printf("1. them phan tu vao dau danh sach\n");
        printf("2. them phun tu vao cuoi danh sach\n");
        printf("3. xoa phan tu dau danh sach\n");
        printf("4. xoa phan tu cuoi danh sach\n");
        printf("5. hien thi danh sach\n");
        printf("6. thoat\n");
        printf("moi nhap\n ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("nhap dau ");
                scanf("%d", &value);
                insertHead(&head, value);
                break;
            case 2:
                printf("nhap cuoi ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 3:
                deleteHead(&head);
                break;
            case 4:
                deleteEnd(&head);
                break;
            case 5:
              
                printList(head);
                break;
            case 6:
               	exit(0);
                break;
            default:
                printf("chon lai di\n");
        }
    } while (1== 1);

    return 0;
}

