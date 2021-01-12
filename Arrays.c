#include <stdlib.h>
#include <stdio.h>

int main(){

    int list[10] = {12,34,12,54,34,12,34,34,34,10};

    int i = 0;
    for(i = 0; i < 10; i++){

        printf("list[%d] = %d\n" , i , list[i]);
    }

    int x, y;
    int currNum = 0;
    int counter = 0;
    int count = 0;
    int bigNum = 0;

    //finds max number
    for(x = 0; x < 10; x++){

        counter = 0;    
        currNum = list[x];

        for(y = x; y < 10-x; y++){

            if(currNum == list[y]){
                counter++;
            }

        }

        

        //first number in array
        if(x == 0){
            count = counter;
            bigNum = currNum;
        }

        //new max number
        else if(counter > count){
            count = counter;
            bigNum = currNum;
        }

        }

    printf("The biggest number is: %d" , bigNum);

    return 0;
}