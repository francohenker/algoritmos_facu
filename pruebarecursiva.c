#include<stdio.h>

 
int sumacall(int num){
    if(num > 9){
        int x = 1 + sumacall(num / 10);
    }
}

int main(){

    int result = sumacall(1234567890);
    printf("JASDJ %d", result);
    return 0;
}