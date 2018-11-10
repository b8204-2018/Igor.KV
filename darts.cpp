//
// Created by igor on 10.11.18.
//
#include "darts.h"
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    int a;
    int b;
    std::cout <<"Enter x coordinate"<< std::endl;
    cin>>a;
    std::cout << "Enter y coordinate" << std::endl;
    cin>>b;
    printf("%d\n",  dartsio(a,b));
    return 0;
}
