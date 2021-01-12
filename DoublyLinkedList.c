//To make doubly linked list:
//Create linked list and include a next and prev pointer
//Make every node point to the one after and before 
//(First node prev is NULL and Last node next is NULL)
//Operations:
//Insert (start,middle,end), Delete (start,middle,end), print(forward and backward) 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node* next;
    struct Node* prev;
};

//checks if linked list is empty
int isEmpty(struct Node* e){

    if(e == NULL){
        return 1;
    }

    return 0;
}

//prints the linked list forward
void printFront(struct Node* f){

    if(f == NULL){
        printf("Linked list is currently empty \n");
        return;
    }

    while(f != NULL){
        printf(" %d" , f -> num);
        f = f-> next;
    }
}

//prints the linked list backwards
void printBack(struct Node* b){

    if(b == NULL){
        return;
    }

    while(b != NULL){
        printf(" %d", b -> num);
        b = b -> prev;
    }
}

//inserts value into linked list
void insert(struct Node* i, int insertNum, struct Node** head){

    int counter = 0;

    //inserting in empty list
    if(isEmpty(i) == 1){
        struct Node* temp = malloc(sizeof(struct Node));
        temp -> num = insertNum;
        temp -> prev = NULL;
        temp -> next = NULL;
        (*head) = temp;
        return;
    }



    //while not at end of linked list
    while(i != NULL){

        //inserting at start of linked list
        if(insertNum < i -> num && counter == 0){

            struct Node* temp = malloc(sizeof(struct Node));

            temp -> num = insertNum;
            temp -> next = i;
            temp -> prev = NULL;
            i -> prev = temp;

            //changes head pointer
            (*head) = temp;

            return;

        }   

        //inserting at the end of linked list
        else if(i -> next == NULL && insertNum > i -> num){

            struct Node* temp = malloc(sizeof(struct Node));

            temp -> num = insertNum;
            i -> next = temp;
            temp -> prev = i;
            temp -> next = NULL;

            return;
        }

        //inserting in the middle of linked list
        else if(i -> num < insertNum && i -> next -> num > insertNum){

            struct Node* temp = malloc(sizeof(struct Node));

            temp -> num = insertNum;
            temp -> next = i -> next;
            i -> next -> prev = temp;
            temp -> prev = i;
            i -> next = temp;

            return;

        }

        i = i -> next;
        counter++;

    }
    printf( "\nCould not insert value, make sure value is not already in the linked list \n");
}

//removes value from linked list
void delete(struct Node* d, int deleteNum, struct Node** head, struct Node** curr){

        int counter = 0;

        //deleting only node in linked list
        if(d -> next == NULL && d-> num == deleteNum){
            free(d);
            d = NULL;
            (*head) = d;
            return;
        }

        //while not at end of linked list
        while(d != NULL){

            //Deleting the first node in linked list
            if(d -> num == deleteNum && counter == 0){

                struct Node* temp = malloc(sizeof(struct Node));

                temp = d;
                d = d -> next;
                d -> prev = NULL;
                (*head) = d;
                
                //deletes node
                free(temp);
                temp = NULL;

                return;

            }

            //Deleting the last node in linked list
            else if(deleteNum == d -> num && d -> next == NULL){

                struct Node* temp = malloc(sizeof(struct Node));

                temp = d;

                d = d -> prev;
                d -> next = NULL;
                (*curr) = d;

                free(temp);
                temp = NULL;

                return;

            }

            //found value to delete in middle of linked list
            else if(deleteNum == d -> num){

                struct Node* temp = malloc(sizeof(struct Node));

                temp = d;
                d = temp -> prev;
                d -> next = temp -> next;
                d -> next -> prev = d;

                free(temp);
                temp = NULL;

                return;


            }

            d = d -> next;
            counter++;
        }

        printf("Could not find value in linked list to delete \n");
    }


int main(){

    struct Node* curr = NULL;
    struct Node* head = NULL;

    curr = (struct Node*)malloc(sizeof(struct Node));
    head = (struct Node*)malloc(sizeof(struct Node));

    head = NULL;
    curr = NULL;

    int userChoice = 0;
    int userInput = 0;

    //While user doesn't want to quit
    while(userChoice != -1){

        printf("\n1. Insert a new value \n");
        printf("2. Delete a value \n");
        printf("3. Print linked list \n");
        printf("4. Quit program \n");
        printf("What would you like to do: ");

        scanf("%d", &userChoice);

        //inputs a new number into linked list
        if(userChoice == 1){

            //linked list is empty
            if(isEmpty(head) == 1){
               curr = head;
            }

            printf("What number would you like to enter into the linked list: ");
            scanf("%d", &userInput);

            insert(head, userInput, &head);
            
            //if only one node in linked list
            if(head -> next == NULL){
                curr = head;
            }

            //More than one node, moves onto next node
            else if(curr -> next != NULL){
                curr = curr ->next;
            }

        }

        //deletes a value in the linked list
        else if(userChoice == 2){

            //linked list is empty
            if(isEmpty(head) == 1){
               printf("Linked list is empty, cannot delete any values\n");

            }
            else{

                printf("\nHere is the current linked list: \n");
            
                printf("Printed forward: ");
                printFront(head);
                printf("\n");
                printf("Printed backward: ");
                printBack(curr);
                printf("\n");

                printf("Which value would you like to delete?: ");
                scanf("%d", &userInput);

                delete(head, userInput, &head, &curr);
            }
        }

        //prints linked list forward and backwards
        else if(userChoice == 3){

            //Linked list is empty
            if(isEmpty(head) == 1){
                printf("Linked list is empty, there are no values to display\n");
            }
            else{

                printf("Printed forward: ");
                printFront(head);
                printf("\n");
                printf("Printed backward: ");
                printBack(curr);
                printf("\n");
            }

        }

        //Quits the program
        else if(userChoice == 4){
            return 0;
        }


    }

    return 0;
}