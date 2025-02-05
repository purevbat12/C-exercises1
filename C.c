#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int solve(int size, const int arr[size]){
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
                    printf("\n%d + %d = 0", *(arr + i), *(arr + j));
                    count++;
                    couples[count - 1][0] = *(arr + i);
                    couples[count - 1][1] = *(arr + j);
                    printf("\ncouples[%d][%d] = %d\n\n", count - 1, 0, couples[count - 1][0]);
                    printf("\ncouples[%d][%d] = %d\n\n", count - 1, 1, couples[count - 1][1]);
                }
            }
        }
        printf("couples:\n");
        for(int i = 0; i < (size - 2) / 2; i++){
            for(int j = 0; j < 2; j++){
                printf("couples[%d][%d] = %d\n", i, j, couples[i][j]);
            }
        }
        if(size / 2 == count){
            ret = *(arr + size - 1);
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
    if(first){
            ret = *(arr + size - 1);
        }
        else if(last){
            ret = *(arr);
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