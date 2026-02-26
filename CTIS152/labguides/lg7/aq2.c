#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 6

typedef struct codes{
    char name[5];
    char code[3];
} codes_t;

int search_courses(codes_t code_list[], char name[]);

int main(){

    FILE *inp;
    inp = fopen("course.txt", "r");
    if(inp == NULL)
        printf("ERROR\n");
    else{
        codes_t code_list[MAX] = {{"CS","11"}, {"THM","61"}, {"CTIS","62"}, {"ECON","32"}, {"MBA","94"}, {"TURK","95"}};
        int status;
        char name[4];
        int code;
        int name_index;
        status = fscanf(inp, "%s %d", name, &code);
        while(status != EOF){
            printf("%4s %d -> ", name, code);
            name_index = search_courses(code_list, name);
            if(name_index != -1)
                printf("%s%d\n", code_list[name_index].code, code);
            else
                printf("ERROR\n");
            status = fscanf(inp, "%s %d", name, &code);
        }
        fclose(inp);
    }

    return 0;
}

int search_courses(codes_t code_list[], char name[]){
    for(int i = 0; i < MAX; i++)
        if(strcmp(code_list[i].name, name) == 0)
            return i;
    return -1;
}