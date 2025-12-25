#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void spiralDraw(int matrix[][5]);

int main(){

	srand(time(NULL));
	int ch = rand() % ('Z' - 'A') + 'A';
	int matrix[5][5];
	for(int i = 0; i < 5; i++){
		for(int p = 0; p < 5; p++){
			matrix[i][p] = ch;
			ch++;
			if(ch > 'Z')
				ch = 'A';
		}
	}
	for(int i = 0; i < 5; i++){
		printf("  ");
		for(int p = 0; p < 5; p++)
			printf("%c  ", matrix[i][p]);
		printf("\n");
	}
	printf("Spiral\n\n");
	spiralDraw(matrix);

	return 0;
}

void spiralDraw(int matrix[][5]){
	int rightWall = 4, leftWall = 0, upWall = 0, downWall = 4;
	int r, d, l, u;
	int total;
	for(total = 0; total < 25;){
		for(r = leftWall; r <= rightWall && total != 25; r++, total++){
			printf("%c  ", matrix[upWall][r]);
		}
		upWall++;
		for(d = upWall; d <= downWall && total != 25; d++, total++){
			printf("%c  ", matrix[d][rightWall]);
		}
		rightWall -= 1;
		for(l = rightWall; l >= leftWall && total != 25; l--, total++){
			printf("%c  ", matrix[downWall][l]);
		}
		downWall -= 1;
		for(u = downWall; u >= upWall && total != 25; u--, total++){
			printf("%c  ", matrix[u][leftWall]);
		}
		leftWall++;
	}
	printf("\n");
}
