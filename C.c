#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int solve(int size, int arr[size]){
    printf("Sorted array:\n");
    printf("[");
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
    }
    printf("]");
    int count = 0, ret;
    bool first, last;
    if(size % 2 == 0){
        printf("\nThe size is even.");
        int couples[(size - 2) / 2][2];
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(*(arr + i) + *(arr + j) == 0){
                    count++;
                    if(count % 2 == 0){
                        couples[(count) / 2 - 1][0] = *(arr + i);
                        couples[(count) / 2 - 1][1] = *(arr + j);
                        printf("\ncouples[%d][%d] = %d\n\n", (count) / 2 - 1, 0, couples[count / 2 - 1][0]);
                        printf("\ncouples[%d][%d] = %d\n\n", count / 2 - 1, 1, couples[count / 2 - 1][1]);
                    }

                }
            }
        }
        int *arr1;
        arr1 = arr;
        for(int i = 0; i < sizeof(couples) / sizeof(couples[0]); i++){
            for(int j = 0; j < sizeof(couples[0]) / sizeof(couples[0][0]); j++){
                for(int k = 0; k < size; k++){
                    if(*(arr1 + k) == couples[i][j]){
                        *(arr1 + k) = 0;
                    }
                }
            }
        }
        printf("arr[] = {");
        for(int i = 0; i < size; i++){
            if(i == 0){
                for(int k = 0; k < size; k++){
                    printf("%d ", *(arr1 + k));
                }
                printf("}\n");
            }
            if(*(arr + i) != 0){
                printf("arr[%d] =! 0 => %d =! 0\n", i, *(arr1 + i));
                ret = *(arr + i);
                printf("Ret = %d\n\ntesting arr[4] = %d\t", *(arr1 + i), *(arr1 + 4));

            }
        }
    }
    else{
        printf("\nThe size is not even.");
        for(int i = 0; i < size; i++){
            if(*(arr) + *(arr + i) == 0){
                printf("\nfirst: arr[0] + arr[%d] => %d + %d = %d\n", i, *(arr), *(arr + i), *(arr) + *(arr + i));
                first = true;
            }
            else{
                printf("\nfirst: arr[0] + arr[%d] => %d + %d =! %d\n", i, *(arr), *(arr + i), 0);
            }
            if(*(arr + size - 1) + *(arr + i) == 0){
                printf("\nlast: arr[%d] + arr[%d] => %d + %d = %d\n", size - 1, *(arr + size - 1), *(arr + i), *(arr + size - 1) + *(arr + i));
                last = true;
            }
            else{
                printf("\nlast: arr[%d] + arr[%d] => %d + %d =! %d\n", size - 1, i, *(arr + size - 1), *(arr + i), 0);
            }
        }
    }
    return ret;
}
int main(){
    int size = 6, num, temp;
    int *arr = NULL;
    printf("Size of the array: ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        arr = (int*)realloc(arr, sizeof(int) * (i + 1));
        printf("\nElement arr[%d] = ", i);
        scanf("%d", &num);
        *(arr + i) = num;
    }
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            if(*(arr + j) > *(arr + j + 1)){
                temp = *(arr + j + 1);
                *(arr + j + 1) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
    printf("\n\n%d", solve(size, arr));
    return 0;
}