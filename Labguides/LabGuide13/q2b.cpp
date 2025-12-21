#include <stdio.h>

int main(){

    FILE *inp;
    inp = fopen("sentence.txt", "r");
    if(inp == NULL)
        printf("ERROR");
    else{
        FILE *outp;
        outp = fopen("reverseB.txt", "w");
        int status; 
        char ch, word[20]; 
        status = fscanf(inp, "%c", &ch);
        while(status != EOF){
            int i = 0;
            while(ch != ' ' && status != EOF){
                word[i] = ch;
                status = fscanf(inp, "%c", &ch);
                i++;
            }
            if(ch = ' ')
                status = fscanf(inp, "%c", &ch);
            for(int p = 0; p < i; p++)
                fprintf(outp, "%c", word[i - 1 - p]);
            fprintf(outp, " ");
        }
        fclose(inp);
        fclose(outp);
    }

    return 0;
}