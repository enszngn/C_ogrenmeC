#include <stdio.h>
#include <stdlib.h>

typedef struct exam_grades{
	double ales;
	double yds;
}exam_grades_t;

typedef struct student_info{
	char name[20];
	double cgpa;
	exam_grades_t grades;
	double overallGrade;
	int scholarshipPercentage;
}student_info_t;

void calculateScholarship(student_info_t students[], int i);

void readFromFile(FILE *inp, student_info_t students[], int numberOfStudents);

void displayReport(student_info_t students[], int numberOfStudents);

int main(){

	FILE *inp;
	inp = fopen("graduateStudents.txt", "r");
	if(inp == NULL)
		printf("ERROR");
	else{
		student_info_t *students;
		int numberOfStudents;
		fscanf(inp, "%d", &numberOfStudents);
		students = (student_info_t *)malloc(sizeof(student_info_t) * numberOfStudents);
		readFromFile(inp, students, numberOfStudents);
		displayReport(students, numberOfStudents);

		fclose(inp);
	}

	return 0;
}

void calculateScholarship(student_info_t students[], int i){
	(students + i)->overallGrade = (students + i)->cgpa / 4 + (students + i)->grades.ales / 2 + (students + i)->grades.yds / 4;
	if((students + i)->overallGrade > 90)
		(students + i)->scholarshipPercentage = 100;
	else if((students + i)->overallGrade > 80)
		(students + i)->scholarshipPercentage = 75;
	else if((students + i)->overallGrade > 65)
		(students + i)->scholarshipPercentage = 50;
	else
		(students + i)->scholarshipPercentage = 0;
}

void readFromFile(FILE *inp, student_info_t students[], int numberOfStudents){
	for(int i = 0; i < numberOfStudents; i++){
		fscanf(inp, "%s %lf %lf %lf", (students + i)->name, &(students + i)->cgpa, &(students + i)->grades.ales, &(students + i)->grades.yds);
		calculateScholarship(students, i);
	}
}

void displayReport(student_info_t students[], int numberOfStudents){
	printf("STUDENT NAME     CGPA   ALES    YDS      OVERALL   SCHOLARSHIP PERCENTAGE\n");
	printf("************     ****   ****    ***      *******   **********************\n");
	for(int i = 0; i < numberOfStudents; i++){
		printf("%-15s  %5.2f  %5.2f  %5.2f     %5.2f             %3d %%\n", (students + i)->name, (students + i)->cgpa, (students + i)->grades.ales, (students + i)->grades.yds, (students + i)->overallGrade, (students + i)->scholarshipPercentage);
	}
}
