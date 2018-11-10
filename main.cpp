#include <iostream>
#include<stdio.h>

using namespace std ;

int main() {
    int *a = new int;
    int *b = new int;
    scanf("%d %d/n",a,b);
    *a =*a+*b;
    *b =*a-*b;
    *a = *a-*b;
    printf("%d %d",*a,*b);
    return 0;
}