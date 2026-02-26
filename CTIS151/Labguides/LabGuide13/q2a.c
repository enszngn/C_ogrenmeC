#include <stdio.h>

int main(){

    FILE *inp;
    inp = fopen("sentence.txt", "r");
    if(inp == NULL)
        printf("ERROR");
    else{
        FILE *outp;
        outp = fopen("reverseA.txt", "w");
        int status, i = 0;
        char ch, sentence[1000];
        status = fscanf(inp, "%c", &ch);
        while(status != EOF){
            sentence[i] = ch;
            status = fscanf(inp, "%c", &ch);
            i++;
        }
        for(int p = 0; p < i; p++)
            fprintf(outp, "%c", sentence[i - 1 - p]);
        fclose(inp);
        fclose(outp);
    }

    return 0;
}