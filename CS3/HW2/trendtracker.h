#ifndef TRENDTRACKER_H
#define TRENDTRACKER_H

//These are the only libraries you may use,
//do not include any additional libaries.
#include <cassert>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Trendtracker
{
	// For the mandatory running times below:
	// n is the number of hashtags in the Trendtracker.

	public:
		// Creates a Trendtracker containing hashtags
		// found in the provided file.
		// The file is promised to have the following format:
		//
		// string1
		// string2
		// ...
		// stringN
		//
		// where string1 < string2 < ... < stringN
		//
		// Must run in O(n) time.
		Trendtracker(string filename){
			ifstream f(filename);
			assert(f.is_open()); // If this fails, the file is missing
			string line;
			while (getline(f, line))
			{
				Entry e;
				e.hashtag = line;
				e.pop = 0;
				E.push_back(e);
			}
			f.close();
            S.clear();
            if (!E.empty())      S.push_back(0);
            if (E.size() >= 2)   S.push_back(1);
            if (E.size() >= 3)   S.push_back(2);
		}

		// Return the number of hashtags in the Trendtracker.
		//
		// Must run in O(1) time.
		int size(){
            return E.size();
        }

		// Adds 1 to the total number times a hashtag has been tweeted.
		// If the hashtag does not exist in TrendTracker, does nothing.
		//
		// Must run in O(log(n)) time.
		void tweeted(string ht) {
            int index = search(ht);
            if (index == -1) return;

            // increment count
            E[index].pop++;

            // remove index if already in S
            for (auto it = S.begin(); it != S.end(); ++it) {
                if (*it == index) { S.erase(it); break; }
            }

            // find insert position: higher pop first; on tie, lower index first
            auto pos = S.begin();
            while (pos != S.end()) {
                if (E[index].pop > E[*pos].pop) break;
                if (E[index].pop == E[*pos].pop && index < *pos) break;
                ++pos;
            }
            S.insert(pos, index);

            // keep only top 3
            if (S.size() > 3) S.pop_back();
        }

		// Returns the number of times a hashtag has been tweeted.
		// If the hashtag does not exist in Trendtracker, returns -1.
		//
		// Must run in O(log(n)) time.
		int popularity(string name){
            int index = search(name);
            if (index != -1)
                return E[index].pop;
            else
                return -1;
        }

		// Returns a most-tweeted hashtag.
		// If the Trendtracker has no hashtags, returns "".
		//
		// Must run in O(1) time.
		string top_trend(){
            if (S.size() == 0)
                return "";
            else
                return E[S[0]].hashtag;
        }

		// Fills the provided vector with the 3 most-tweeted hashtags,
		// in order from most-tweeted to least-tweeted.
		//
		// If there are fewer than 3 hashtags, then the vector is filled
		// with all hashtags (in most-tweeted to least-tweeted order).
		//
		// Must run in O(1) time.
		void top_three_trends(vector<string> &T){
            T.resize(0);
            for (int i = 0; i < S.size(); i++)
                T.push_back(E[S[i]].hashtag);
        }

	private:
		// A simple class representing a hashtag and
		// the number of times it has been tweeted.
		class Entry
		{
			public:
				string hashtag;
				int pop;
		};

		// Optional helper method.
		// Returns the index of E containing an Entry with hashtag ht.
		// If no such hashtag is found, returns -1.
		//
		// Should run in O(log(n)).
		int search(string ht);

		// Entries sorted (lexicographically) by hashtag.
		vector<Entry> E;

		// Stores indices of the (up to) three most-tweeted
		// entries in E.
		vector<int> S;
};

#endif
