#include <stdio.h>
#include <math.h>

int convertToBase(int num, int base, int wantedBase);

int main(){

    int num, base = 1, wantedBase;

    if(base < 2 || base > 10){
        printf("Enter the base and the number: ");
        scanf("%d %d", &base, &num);

        do {
        printf("Enter the base to be converted: ");
        scanf("%d", &wantedBase);
        } while (!(wantedBase >= 2 && wantedBase <= 9));

        printf("Number in base %d = %d\n", wantedBase, convertToBase(num, base, wantedBase));
    }

    return 0;
}

int convertToBase(int num, int base, int wantedBase){
    int digitNum = 1, modifiableNum, decimalValue = 0, modifiableDecimalValue, inWantedBase = 0;
    modifiableNum = num;
    modifiableDecimalValue = decimalValue;

    while(modifiableNum > 0){
        modifiableNum /= 10;
        digitNum++;
    }

    for(int i = 1, p = 0; i <= digitNum; i++, p++){
        decimalValue += num % 10 * pow(base, p);
        num /= 10;
    }

    for(int i = 1; decimalValue >= wantedBase; i++){
        inWantedBase += decimalValue % wantedBase * pow(10, i - 1); //inwantedbase is 3 right now
        decimalValue /= wantedBase; //decimal value was 73 so it's 10 rn
        if(decimalValue / wantedBase == 1){ // 10 / 7 = 1 so we enter
            inWantedBase += decimalValue % wantedBase * pow(10, i); //inwantedbase = 3, decimalvalue is 10 so 10 % 7 = 3, 3 * 10 to the power of 1, so 30, inwantedbase = 33 rn
            inWantedBase += 1 * pow(10, i + 1); //inwantedbase was 33 that + 1 * 10 to the power of 2 so 100, it is 133 now. And the value of decimalvalue = 10 so we enter the loop again that's the problem.
            decimalValue /= wantedBase;
        }
    }

    return inWantedBase;
}