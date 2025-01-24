#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int digital_root(int n){
    int i = 1, temp = n;
    while(temp > 0){
        temp = temp - (temp % (int)pow(10, i));
        printf("%d\n", temp);
        i++;
    }
    int digit = i - 1;
    return digit;
}
int main(){
    int n = 941;
    printf("Type your number: ");
    //scanf("%d", &n);
    printf("%d", digital_root(n));
    return 0;
}