#include <stdio.h>
#include <math.h>
int main(){

    int week, hour;
    double obligation;
    char type;

    printf("Enter the number of weeks in a semester: ");
    scanf("%d", &week);
    printf("Enter the number of lecture hours in a week: ");
    scanf(" %d", &hour);
    printf("Enter type of lecture, (m/M for must) / (e/E for elective): ");
    scanf(" %c", &type);

    obligation = week * hour;
    
    if(type == 'e' || type == 'E')
        obligation /=2.0;
    else
        obligation = obligation*3/4.0;

    printf("You must attend %.0lf hours.", obligation);

    return 0;
}