#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char extension[10];
	char description[100];
} ext_t;

int read(FILE *inp, ext_t extensions[]);

int search(ext_t extensions[], char searched[], int numberOfExtensions);

int main(){

	FILE *inp;
	inp = fopen("extensions.txt", "r");
	if(inp == NULL)
		printf("ERROR\n");
	else{
		ext_t *extensions;
		extensions = (ext_t *)malloc(sizeof(ext_t) * 20);
		int numberOfExtensions = read(inp, extensions);
		char url[100];
		int count = 0;
		printf("Enter a website URL: ");
		scanf("%s", url);
		int urlLen = strlen(url);
		int found = 0;
		char ext[10];
		for(int i = 0; i < urlLen && found != 1; i++){
			if(*(url + i) == '.')
				count++;
			if(count == 2 && *(url + i) != '.'){
				for(int p = 0, a = i; *(url + a) != '.'; p++, a++)
					ext[p] = *(url + a);
				found = 1;
			}
		}
		int whichExt = search(extensions, ext, numberOfExtensions);

		printf("%s extension is used for %s\n", extensions[whichExt].extension, extensions[whichExt].description);

		fclose(inp);
		free(extensions);
	}

	return 0;
}

int read(FILE *inp, ext_t extensions[]){
	int i = 0;
	while(fscanf(inp, "%s %[^\n]", extensions[i].extension, extensions[i].description) == 2)
		i++;
	return i;
}

int search(ext_t extensions[], char searched[], int numberOfExtensions){
	for(int i = 0; i < numberOfExtensions; i++)
		if(strcmp(extensions[i].extension, searched) == 0)
			return i;
	return -1;
}
