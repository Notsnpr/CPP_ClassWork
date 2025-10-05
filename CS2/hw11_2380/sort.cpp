//***********************************************************************
// Team #13                            CSCI 2380                          Spring 2025                      Homework # 11
// Victor Munoz
// Luis Elizondo
// Angel Morales
//  
//*********************************************************************** 

#include "sort.h"
#include <algorithm>
using namespace std;

/***********************************************************************
    The plan is to first check if the input is alreadt sorted or sorted 
    backwards if its already sorted we can just return it, if its sorted
    backwards we can reverse the array inplace.
    then if len is less than 32 then we can do insertion sort,
    if len is inbetween 32 and 200000 then we will do merge sort,
    and if len is greater than 200000 then we do quick sort
***********************************************************************/

//detect_order
//+1  ascending,  -1  descending,  0  mixed
int detect_order(const int* a, int n)
{
    bool asc  = true;
    bool desc = true;

    for (int i = 1; i < n; ++i) {
        if (a[i - 1] > a[i]) {
            asc = false;   // break ascending chain
        }
        if (a[i - 1] < a[i]) {
            desc = false;  // break descending chain
        }
        if (!asc && !desc) {
            break;        // early stop
        }
    }

    if (asc)  return  1;
    if (desc) return -1;
    return 0;
}

//INSERTION SORT O(n^2) time, O(1) memory, best for n < 32
void insertion_sort(int* a, int n)
{
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j   = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}


//MERGE SORT O(n log n) time, O(n) memory
void merge_pass(int* a, int l, int m, int r, int* buf)
{
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            buf[k++] = a[i++];
        } else {
            buf[k++] = a[j++];
        }
    }

    while (i <= m) {
        buf[k++] = a[i++];
    }
    while (j <= r) {
        buf[k++] = a[j++];
    }

    for (int t = l; t <= r; ++t) {
        a[t] = buf[t];
    }
}

void merge_sort_rec(int* a, int l, int r, int* buf)
{
    if (r - l < 32) {
        insertion_sort(a + l, r - l + 1);
        return;
    }

    int m = l + (r - l) / 2;
    merge_sort_rec(a, l, m, buf);
    merge_sort_rec(a, m + 1, r, buf);

    // merge only if necessary
    if (a[m] > a[m + 1]) {
        merge_pass(a, l, m, r, buf);
    }
}

void merge_sort(int* a, int n)
{
    int* tmp = new int[n];
    merge_sort_rec(a, 0, n - 1, tmp);
    delete[] tmp;
}


//QUICK SORT avg O(n log n), O(1) mem, median‑of‑three pivot
int median_of_three(int* a, int l, int r)
{
    int m = l + (r - l) / 2;

    if (a[l] > a[m]) {
        swap(a[l], a[m]);
    }
    if (a[l] > a[r]) {
        swap(a[l], a[r]);
    }
    if (a[m] > a[r]) {
        swap(a[m], a[r]);
    }

    return a[m];
}

void quick_sort_rec(int* a, int l, int r, int depth_limit)
{
    while (r - l >= 32) {
        if (depth_limit == 0) {
            // bail out to Merge Sort to avoid worst‑case O(n²)
            merge_sort(a + l, r - l + 1);
            return;
        }
        --depth_limit;

        int pivot = median_of_three(a, l, r);
        int i = l;
        int j = r;

        while (true) {
            while (a[i] < pivot) {
                ++i;
            }
            while (a[j] > pivot) {
                --j;
            }
            if (i >= j) {
                break;
            }
            swap(a[i], a[j]);
            ++i;
            --j;
        }

        // recurse on smaller half first to keep stack shallow
        if (j - l < r - j) {
            quick_sort_rec(a, l, j, depth_limit);
            l = j + 1;      // tail call on larger half
        } else {
            quick_sort_rec(a, j + 1, r, depth_limit);
            r = j;
        }
    }

    // finish off the tiny slice with insertion
    insertion_sort(a + l, r - l + 1);
}

//sort public entry
void sort(int* A, int len)
{
    if (len < 2 || A == nullptr) {
        return;
    }

    // fast path if already ordered
    int order = detect_order(A, len);
    if (order == 1) {
        return;               // ascending == done
    }
    if (order == -1) {
        // reverse descending array inplace
        for (int i = 0, j = len - 1; i < j; ++i, --j) {
            swap(A[i], A[j]);
        }
        return;
    }

    const int SMALL = 32;
    const int HUGE  = 200000;

    if (len < SMALL) {
        insertion_sort(A, len);
    } else if (len > HUGE) {
        merge_sort(A, len);
    } else {
        int max_depth = 64;        // 2 * log2(HUGE) ≈ 64
        quick_sort_rec(A, 0, len - 1, max_depth);
    }
}


// References
// CLRS 3e, ch. 2, 7, 8
// Knuth TAOCP v3, 2nd ed.
// Skiena TADM 3e, ch. 4
// Wikipedia: Insertion / Quick / Merge sort
// GeeksForGeeks: median‑of‑three pivot, tail recursion, linked‑list merge