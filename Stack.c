//Stack using a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node* next;
    
};

//checks if the stack is empty
int isEmpty(struct Node* top){

    if(top == NULL){
        return 1;
    }

    return 0;
}

//pushes a new value onto the stack
void push(struct Node* top, int data, struct Node** head){

    struct Node* temp = malloc(sizeof(struct Node));
    temp -> num = data;
    temp -> next = NULL;

    if(isEmpty(top) == 1){
        
        (*head) = temp;
        return;

    }

    temp -> next = top;
    (*head) = temp;


}

//pops a value off the top of the stack
void pop(struct Node* top, struct Node** head){

    struct Node* temp = malloc(sizeof(struct Node));

    (*head)= top -> next;
    free(top);
    top = NULL;
    //(*head) = temp;


}

//prints the top value on the stack
void top(struct Node* top){

    printf("%d", top ->num);
}

//prints the entire stack
void print(struct Node* top){

    while(top != NULL){

        printf("%d ", top -> num);
        top = top -> next;
    }
}

int main(){

    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head = NULL;

    int userInput = 0;
    int userNum = 0;

    //while user chooses not to quit
    while(userInput != -1){

        printf("\n1.Push to stack\n");
        printf("2.Pop stack\n");
        printf("3.Check the top of stack\n");
        printf("4.Print stack\n");
        printf("5.Quit\n");
        printf("What would you like to do?: ");

        scanf("%d", &userInput);

        //push to stack
        if(userInput == 1){

            printf("\nWhat number would you like to push to the stack: ");
            scanf("%d", &userNum);

            push(head, userNum, &head);


        }
        //pop from stack
        else if(userInput == 2){

            if(isEmpty(head) == 1){
                printf("Stack is empty, cannot pop\n");
            }
            else{
                pop(head, &head);

            }
        }
        //check top
        else if(userInput == 3){
            if(isEmpty(head) == 1){
                printf("Stack is empty\n");
            }
            else{
                top(head);
            }

        }
        //print
        else if(userInput == 4){

            if(isEmpty(head) == 1){
                printf("Stack is empty, cannot print\n");
            }
            else{
                print(head);
            }

        }
        //quit
        else if(userInput == 5){
            return 0;


        }
    }





    return 0;
}