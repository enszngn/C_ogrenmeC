#include <stdio.h>
#include <stdbool.h> //this is for bool type variable. they are either true or false, like a proposition.

int main(){


bool isOnline = true;
bool isStudent = false;

if(isOnline){
    printf("you are online!\n");
}
else{
    printf("you are offline!\n");
}

if(isStudent){
    printf("you are allowed to go in.");
}
else{
    printf("you are not allowed to go in\n");
}

return 0;

}
