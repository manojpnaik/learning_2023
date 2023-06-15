#include <stdio.h>

void biggest(int n, int m){
int a;
a=n>m ? n : m;
printf("%d is the biggest of 2 numbers %d and %d",a,n,m);
}

int main(){
    int num1,num2;
    printf("Enter 2 numbers : ");
    scanf("%d %d",&num1, &num2);
    biggest(num1,num2);
}