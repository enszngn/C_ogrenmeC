#include <stdio.h>
#include <stdbool.h> //this is for bool type variable. they are either true or false, like a proposition.

/*
int=whole numbers(4 bytes in modern systems)
float=single precision decimal number(4 bytes)
double=double precision decimal bumber(8 bytes)
char=single character(1 byte)
char[]=array of characters(size varies)
bool=true or false (1 byte, requires <stdbool.h>)  
*/

int main(){

    //variable=degisken=x=y=z

    int yas = 19;
    int yeariwasborn = 2006;
    int urunsayisi = 178293450;
    // i don't know the difference between float and double.
    float gpa = 3.8;
    float fiyat = 19.19238;
    float sicaklik = -12.5;
    // oh so float has 6 digits after 0, double has 15-16.
    double pi = 3.1415926535897;
    double euler = 2.718281828;

    char grade = 'A';
    char bestchar = 'E';

    char isim[] = "Enes Zengin";  //this is basically a string hence %s is used.
    char yemek[] = "Hatay Usulu Tavuk Doner";
    char mail[] = "e.zengin@ug.bilkent.edu.tr";


    printf("i'm %d years old!\n", yas);
    printf("i was born in %d!\n", yeariwasborn);
    printf("you have ordered %d items.\n", urunsayisi);
    printf("your gpa is %f.\n", gpa);
    printf("this products price is %f.\n", fiyat);
    printf("the temperature is %f°C.\n", sicaklik);
    printf("first 14 digits of pi is %.13lf.\n", pi);
    printf("first 10 digits of e is %.10lf.\n", euler);
    printf("your grade is %c!\n", grade);
    printf("best character is %c.\n", bestchar);
    printf("hello, my name is %s.\n", isim);
    printf("my favorite food is %s.\n", yemek);
    printf("my school mail is %s\n", mail);


    return 0;
}