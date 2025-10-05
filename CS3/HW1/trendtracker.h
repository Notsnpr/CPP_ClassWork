
#ifndef TRENDTRACKER_H
#define TRENDTRACKER_H


//You may not include any additional libraries for this assignment,
//other than those listed below.
#include <vector>
#include <string>

using namespace std;

class Trendtracker
{
	// For the mandatory running times below:
	// n is the number of hashtags in the Trendtracker.

	public:
		// Creates a new Trendtracker tracking no hashtags.
		//
		// Must run in O(1) time.
		Trendtracker(){
            E.clear();
            E.push_back(Entry{"", 0});
        };

		// Inserts a hashtag (tweeted 0 times) into the Trendtracker.
		// If the hashtag already is in Trendtracker, does nothing.
		//
		// Must run in O(n) time.
		void insert(string ht){
            for (Entry &e : E) {
                if (e.hashtag == ht) {
                    return;
                }
            }
            E.push_back(Entry{ht, 0});
        };

		// Return the number of hashtags in the Trendtracker.
		//
		// Must run in O(1) time.
		int size(){
            return E.size() - 1;
        };

		// Adds 1 to the total number times a hashtag has been tweeted.
		// If the hashtag does not exist in TrendTracker, does nothing.
		//
		// Must run in O(n) time.
		void tweeted(string ht){
            for (Entry &e : E) {
                if (e.hashtag == ht) {
                    e.pop++;
                    return;
                }
            }
        };

		// Returns the number of times a hashtag has been tweeted.
		// If the hashtag does not exist in Trendtracker, returns -1.
		//
		// Must run in O(n) time.
		int popularity(string name){
            for (Entry &e : E) {
                if (e.hashtag == name) {
                    return e.pop;
                }
            }
            return -1;
        };

		// Returns a most-tweeted hashtag.
		// If the Trendtracker has no hashtags, returns "".
		//
		// Must run in O(n) time.
		string top_trend(){
            if (E.size() <= 1) {
                return "";
            }
            Entry *top = &E[1];
            for (Entry &e : E) {
                if (e.pop > top->pop) {
                    top = &e;
                }
            }
            return top->hashtag;
        };

		// Fills the provided vector with the 3 most-tweeted hashtags,
		// in order from most-tweeted to least-tweeted.
		//
		// If there are fewer than 3 hashtags, then the vector is filled
		// with all hashtags (in most-tweeted to least-tweeted order).
		//
		// Must run in O(n) time.
		void top_three_trends(vector<string> &T){
            T.clear();
            vector<Entry> copy = E;
            int k = min(3, (int)E.size() - 1);
            for (int i = 0; i < k; i++) {
                Entry *top = &copy[1];
                for (Entry &e : copy) {
                    if (e.pop > top->pop) {
                        top = &e;
                    }
                }
                T.push_back(top->hashtag);
                top->pop = -1; // So it won't be picked again
            }
        };

		// Remove the given hashtag from the trendtracker.
		//
		// Must run in O(n) time.
		void remove(string ht){
            for (auto it = E.begin(); it != E.end(); ++it) {
                if (it->hashtag == ht) {
                    E.erase(it);
                    return;
                }
            }
        };

		// Fills the provided vector with the k most-tweeted hashtags,
		// in order from most-tweeted to least-tweeted.
		//
		// If there are fewer than k hashtags, then the vector is filled
		// with all hashtags (in most-tweeted to least-tweeted order).
		//
		// Must run in O(nk) time.
		void top_k_trends(vector<string> &T, int k){
            T.clear();
            vector<Entry> copy = E;
            for (int i = 0; i < k; i++) {
                Entry *top = &copy[1];
                for (Entry &e : copy) {
                    if (e.pop > top->pop) {
                        top = &e;
                    }
                }
                T.push_back(top->hashtag);
                top->pop = -1; // So it won't be picked again
            }
        };

	private:
		// A simple class representing a hashtag and
		// the number of times it has been tweeted.
		class Entry
		{
			public:
				string hashtag;
				int pop;
		};


		// Entries containing each hashtag and its popularity.
		vector<Entry> E;
};

#endif
