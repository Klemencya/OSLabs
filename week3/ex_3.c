#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct item {
    int data;
    struct item * next;
} node;

void print_list(node *head){
    if (head->next == NULL){
        printf("Empty list!\n");
    } else{
        node * current = head->next;
        while (current->next != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("%d\n", current->data);
    }
}

void insert_node(node *head, int a){
    node * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (node *) malloc(sizeof(node));
    current->next->data = a;
    current->next->next = NULL;
}

void delete_node(node *head, int a){
    node *current = head;
    while (current->next->data != a){
        current = current->next;
    }
    current->next = current->next->next;
}

int main() {
    node * head = NULL;
    head = (node *) malloc(sizeof(node));
    head->data = 0;
    head->next = NULL;

    int command;
    int a;
    bool over = false;

    while (!over){
        printf("Choose number of action [1-insert, 2-print, 3-delete, 4-over]\n");
        scanf("%d", &command);
        if (command == 1){
            printf("Input the value: ");
            scanf("%d", &a);
            insert_node(head, a);
        } else if (command == 2){
            print_list(head);
        } else if (command == 3){
            printf("Input the value: ");
            scanf("%d", &a);
            delete_node(head, a);
        } else if (command == 4){
            over = true;
        } else {
            printf("Such command does not exist!\n");
        }
    }
    return 0;
}
