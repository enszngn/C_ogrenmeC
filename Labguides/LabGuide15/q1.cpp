#include <stdio.h>

int findColdest(int day[], int size);

void display(int day[], int night[], int size);

int main(){

	FILE *inp;
	inp = fopen("weather.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		int day[10], night[10], i = 0, status;
		status = fscanf(inp, "%d %d", &day[i], &night[i]);
		while(status != EOF){
			i++;
			status = fscanf(inp, "%d %d", &day[i], &night[i]);
		}
		display(day, night, i);
		int coldestIndex = findColdest(day, i);
		int weekDay = coldestIndex % 7;
		printf("\nThe coldest day is ");
		switch(weekDay){
			case 0: printf("Monday");
				break;
			case 1: printf("Tuesday");
				break;
			case 2: printf("Wednesday");
				break;
			case 3: printf("Thursday");
				break;
			case 4: printf("Friday");
				break;
			case 5: printf("Saturday");
				break;
			case 6: printf("Sunday");
		}
		printf(". The degree is: %d", day[coldestIndex]);
		fclose(inp);
	}

	return 0;
}

void display(int day[], int night[], int size){
	printf("DAY   NIGHT\n");
	printf("---   -----\n");
	for(int p = 0; p < size; p++)
		printf("%3d %5d\n", day[p], night[p]);
}

int findColdest(int day[], int size){
	int p, coldest, coldestIndex;
	for(p = 0; p < size; p++){
		if(p == 0){
			coldest = day[p];
			coldestIndex = p;
		}
		else if(day[p] < coldest){
				coldest = day[p];
				coldestIndex = p;
		}
	}
	return coldestIndex;	
}
