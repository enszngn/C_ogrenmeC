#include <stdio.h>
#define MINUTE 300

int main(){

    //declare variables
    double neededHour = 0;
    double batterySituation;

    //get the battery situation from the user
    printf("Please enter your battery situation ( Full : 1 / Half : 0.5 / Empty : 0 ):  ");
    scanf("%lf", &batterySituation);

    //calculate battery needed to use the cordless car for one hour
    neededHour = MINUTE * batterySituation;
    neededHour = MINUTE - neededHour;

    //output given
    printf("Your Battery Situation is %lf \n You need to charge the battery for %0.2lf minute(s)\n", batterySituation, neededHour);
    
    return 0;
    
}