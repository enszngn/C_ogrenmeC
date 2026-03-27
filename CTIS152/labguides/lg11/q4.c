#include <stdio.h>

int climbStairs(int numberOfSteps);

int main(){

	int numberOfSteps;
	printf("Enter the number of steps: ");
	scanf("%d", &numberOfSteps);
	int amountOfWays = climbStairs(numberOfSteps);
	printf("Total number of ways to climb %d steps: %d\n", numberOfSteps, amountOfWays);

	return 0;
}

int climbStairs(int numberOfSteps){
	if(numberOfSteps == 1 || numberOfSteps == 2)
		return numberOfSteps;
	else{
		return (climbStairs(numberOfSteps - 1) + climbStairs(numberOfSteps - 2));
	}
}
