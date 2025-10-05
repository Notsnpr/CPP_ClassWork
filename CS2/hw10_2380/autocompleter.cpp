//***********************************************************************
// Team #13                            CSCI 2380                          Spring 2025                      Homework # 10
// Victor Munoz
// Luis Elizondo
// Angel Morales
//  
//*********************************************************************** 
#include "autocompleter.h"

// Creates a new, empty autocompleter. Initial capacity is 100 elements.
Autocompleter::Autocompleter() {
    capacity = 100;
    count = 0;
    A = new string[capacity];
}

// Returns the number of strings in the Autocompleter.
int Autocompleter::size() {
    return count;
}

// Helper method.
//
// Assumes A is SORTED.
// If x is in A, returns the index of A containing x.
// Otherwise, returns the index of A where x should be inserted 
// (that is, the position where it would be after calling insert(x)).
//
// MUST run in O(log(n)) time (use binary search). 
int Autocompleter::index_of(string x, string* A, int n) {
    int left = 0;
    int right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// Adds x to the list of potential suggestions in the Autocompleter in the position that will keep
// Autocompleter sorted after the insertion.
// MUST double the capacity when necessary.
// If the word is already in the Autocompleter, does nothing.
//
// MUST run in O(n) time.
void Autocompleter::insert(string x) {
    int pos = index_of(x, A, count);
    // if already present, skip
    if (pos < count && A[pos] == x)
        return;
    // resize if full
    if (count == capacity) {
        int newCap = capacity * 2;
        string* B = new string[newCap];
        for (int i = 0; i < count; ++i)
            B[i] = A[i];
        delete[] A;
        A = B;
        capacity = newCap;
    }
    // shift right to make room
    for (int i = count; i > pos; --i)
        A[i] = A[i - 1];
    A[pos] = x;
    ++count;
}

// Returns the number of strings that are completions of
// the parameter string x. 
//
// MUST run in O(log(n)) time.
int Autocompleter::completion_count(string x) {
    // find first index where a string >= x would be
    int start = index_of(x, A, count);
    if (start == count)
        return 0;
    // construct upper bound for prefix by appending high char
    string x_end = x;
    x_end.push_back(char(127));
    int end = index_of(x_end, A, count);
    return end - start;
}

// Takes a string (parameter x) and string array of length 5 (parameter suggestions) 
// Sets the first five elements of suggestions equal 
// to the first five (in lexicographic order) strings
// in the Autocompleter that start with x. 
//
// If there are less than five such strings, the remaining
// entries of the suggestions array are set to "" (the empty string) 
//
// MUST run in O(log(n)) time.
void Autocompleter::completions(string x, string* suggestions) {
    int start = index_of(x, A, count);
    // count matching words
    string x_end = x;
    x_end.push_back(char(127));
    int end = index_of(x_end, A, count);
    int total = end - start;
    // fill up to 5 suggestions
    for (int i = 0; i < 5; ++i) {
        if (i < total)
            suggestions[i] = A[start + i];
        else
            suggestions[i] = "";
    }
}
