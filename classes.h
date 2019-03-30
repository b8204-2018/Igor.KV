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

class QuickSort : public Sort {
    void sort(int *arr, int n) {
        int mid, left, right, l, r;
        long int sw = 0;
        int srav = 0;
        mid = left = right = l = r = 0;
        stack<int> st;
        st.push(n - 1);
        st.push(0);
        do {
            left = st.top();
            st.pop();
            right = st.top();
            st.pop();
            {
                mid = arr[(right)];
                l = left;
                r = right;
                while (l < r) {
                    while (arr[l] < mid) l++;
                    {
                        srav++;
                        while (mid < arr[r]) r--;
                        {
                            srav++;
                            if (l <= r) {
                                swap(arr[l], arr[r]);
                                sw++;
                                l++;
                                r--;
                            }
                        }
                    }
                }
            }
            if (left < r) {
                st.push(r);
                st.push(left);
            }
            if (l < right) {
                st.push(right);
                st.push(l);
            }
        } while (st.size() != NULL);
    };
};

//class BubbleSort : public Sort {
  //  void sort(int *arr, int n) {

    //};
//};
class BinarySort :public Sort{
    void sort(int *arr,int n){
        int i, j, m, L, R, x;
        for (i = 1; i < n; i++) {
            x = arr[i];
            L = 0;
            R = i;
            while (L < R) {
                m = (L + R) / 2;
                if (arr[m] <= x) {
                    L = m + 1;
                } else {

                    R = m;
                }
            }
            for (j = i; R + 1 <= j; j--) {
                arr[j] = arr[j - 1];
            }
            arr[R] = x;
        }
    }
};


class ChoiceSort : public Sort {
    void sort(int *arr, int n) {

        int temp = 0, min = 0, x;
        bool change = false;
        for (int y = 0; y < n; y++) {
            change = false;
            for (x = y; x < n; x++) {
                if (arr[x] <= arr[min]) {
                    min = x;
                    change = true;
                }
            }

            if (change) {
                temp = arr[y];
                arr[y] = arr[min];
                arr[min] = temp;
            }
        }

    };
};

class MergeSort : public Sort {
    void sort(int *a, int l) {
        size_t BlockSizeIterator;
        size_t BlockIterator;
        size_t LeftBlockIterator;
        size_t RightBlockIterator;
        size_t MergeIterator;

        size_t LeftBorder;
        size_t MidBorder;
        size_t RightBorder;
        for (BlockSizeIterator = 1; BlockSizeIterator < l; BlockSizeIterator *= 2) {
            for (BlockIterator = 0; BlockIterator < l - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator) {
                //Производим слияние с сортировкой пары блоков начинающуюся с элемента BlockIterator
                //левый размером BlockSizeIterator, правый размером BlockSizeIterator или меньше
                LeftBlockIterator = 0;
                RightBlockIterator = 0;
                LeftBorder = BlockIterator;
                MidBorder = BlockIterator + BlockSizeIterator;
                RightBorder = BlockIterator + 2 * BlockSizeIterator;
                RightBorder = (RightBorder < l) ? RightBorder : l;
                int *SortedBlock = new int[RightBorder - LeftBorder];

                //Пока в обоих массивах есть элементы выбираем меньший из них и заносим в отсортированный блок
                while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder) {
                    if (a[LeftBorder + LeftBlockIterator] < a[MidBorder + RightBlockIterator]) {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
                        LeftBlockIterator += 1;
                    } else {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
                        RightBlockIterator += 1;
                    }
                }
                //После этого заносим оставшиеся элементы из левого или правого блока
                while (LeftBorder + LeftBlockIterator < MidBorder) {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
                    LeftBlockIterator += 1;
                }
                while (MidBorder + RightBlockIterator < RightBorder) {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
                    RightBlockIterator += 1;
                }

                for (MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++) {
                    a[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
                }
                delete SortedBlock;
            }
        }
    }
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
