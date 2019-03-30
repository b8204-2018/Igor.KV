#include <iostream>
#include"classes.h"
#include"gtest/gtest.h"
using namespace std;

int main() {
    int a[] = {5,2,1,7,2};
    QuickSort sort1;
    printSortedArray(sort1, a, 5);

    cout<<'q'<<endl;

    int b[] = {5,2,1,7,2};
    ChoiceSort sort2;
    printSortedArray(sort2, b, 5);

    cout<<'c'<<endl;

    int c[] = {5,2,1,7,2};
    MergeSort sort3;
    printSortedArray(sort3, c, 5);
    return 0;
}
