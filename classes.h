//
// Created by igor on 29.03.19.
//
#include<stack>
#include<string.h>
#include "gtest/gtest.h"

using namespace std;

#ifndef UNTITLED30_CLASSES_H
#define UNTITLED30_CLASSES_H

class Sort {
public:
    virtual void sort(int *arr, int n) = 0;
};
void printSortedArray(Sort &sort, int *arr, int n) {
    int *res = new int[n];
    memcpy(res, arr, n * sizeof(int));

    sort.sort(res, n);

    for (int i = 0; i < n; i++) {
        cout << " " << res[i];
    }
}

#endif //UNTITLED30_CLASSES_H
