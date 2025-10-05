// trendtracker.cpp
#include "trendtracker.h"
using namespace std;

int Trendtracker::search(string ht) {
    int lo = 0;
    int hi = static_cast<int>(E.size()) - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        const string& midTag = E[mid].hashtag;

        if (midTag == ht) return mid;
        if (midTag < ht)  lo = mid + 1;
        else              hi = mid - 1;
    }
    return -1;
}