//A normal linked list implementation

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node* next;
};

//prints the linked list
void printList(struct Node* n){

    while(n != NULL){
        printf(" %d" , n -> num);
        n = n-> next;
    }
}

int main(){

    struct Node* start = NULL;
    struct Node* head = NULL;

    start = (struct Node*)malloc(sizeof(struct Node));
    head = (struct Node*)malloc(sizeof(struct Node));
    
    start ->num = 0;
    start -> next = NULL;
    head = start;

    //inserts starting values into linked list
    int a = 1;
    for(a = 1; a < 10; a=a+1){

        struct Node* start2 = malloc(sizeof(struct Node));
        start -> next = start2;
        start2 -> num = a*2;
        start2 -> next = NULL;
        start = start2;
    }

    printList(head);
    printf("\n");

    int toInsert = 180;
    start = head;

    //while not at the end of linked list
    while(start != NULL){

        //At the end of the linked list and toInsert is greater than current value
         if(start -> next == NULL && toInsert > start -> num){
            struct Node* temp = malloc(sizeof(struct Node));

            start -> next = temp;
            temp -> next = NULL;
            temp -> num = toInsert;

            break;
        }

        //Value to insert is in middle of linked list
        else if((toInsert > start -> num && toInsert < start -> next -> num)){
            struct Node* temp = malloc(sizeof(struct Node));

            temp -> next = start -> next;
            start -> next = temp;
            temp -> num = toInsert;

            break;
        }

        
        start = start -> next;
    }

    printList(head);


    return 0;
}