//To make doubly linked list:
//Create linked list and include a next and prev pointer
//Make every node point to the one after and before 
//(First node prev is NULL and Last node next is NULL)
//Operations:
//  Insert (start,middle,end), Delete (start,middle,end), print(forward and backward) 

//THIS PROGRAM USES A DEFAULT LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node* next;
    struct Node* prev;
};

int isEmpty(struct Node* e){

    if(e == NULL){
        return 1;
    }

    return 0;
}

//prints the linked list forward
void printFront(struct Node* f){
    
    while(f != NULL){
        printf(" %d" , f -> num);
        f = f-> next;
    }
}

//prints the linked list backwards
void printBack(struct Node* b){

    while(b != NULL){
        printf(" %d", b -> num);
        b = b -> prev;
    }
}

//inserts into linked list
void insert(struct Node* i, int insertNum, struct Node** head){

    int counter = 0;

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

        //inserting in the middle
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
    printf( "\n Could not insert value, make sure value is not already in the linked list \n");
}

//removes a value from the linked list
void delete(struct Node* d, int deleteNum, struct Node** head, struct Node** curr){

        int counter = 0;

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

    char preset = ' ';

    struct Node* curr = NULL;
    struct Node* head = NULL;

    curr = (struct Node*)malloc(sizeof(struct Node));
    head = (struct Node*)malloc(sizeof(struct Node));

   

    curr -> num = 0;
    curr -> next = NULL;
    curr -> prev = NULL;
    head = curr;

    //fills up linked list with numbers 1-9
    int i = 1;
    for(i = 1; i < 10; i = i+1){

        struct Node* curr2 = malloc(sizeof(struct Node));
        curr -> next = curr2;
        curr2 -> num = i*2;
        curr2 -> next = NULL;
        curr2 -> prev = curr;
        curr = curr2;

    }

    int userChoice = 0;
    int userInput = 0;

    printf("Here is the current linked list: \n");
    printf("Printed forward: ");
    
    printFront(head);
    printf("\n");
    printf("Printed backward: ");
    printBack(curr);
    printf("\n");

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

            printf("What number would you like to enter into the linked list: ");
            scanf("%d", &userInput);

            insert(head, userInput, &head);

        }

        //deletes a value in the linked list
        else if(userChoice == 2){
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

        //prints linked list forward and backwards
        else if(userChoice == 3){

            printf("Printed forward: ");
            printFront(head);
            printf("\n");
            printf("Printed backward: ");
            printBack(curr);
            printf("\n");


        }

        //Quits the program
        else if(userChoice == 4){
            return 0;
        }


    }

    return 0;
}