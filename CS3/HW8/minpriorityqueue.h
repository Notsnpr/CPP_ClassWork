
#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

// NOTE: You may not include any other libraries!
#include <unordered_map>
#include <vector>
#include <utility> // Has pair and swap

using namespace std;

template <typename T>
class MinPriorityQueue
{
	// For the mandatory running times below:
	//
	// n is the number of elements in the MinPriorityQueue.
	//
	// Assume that the operations of unordered_map are O(1) time 
	// (they are average case, but not worst-case).

	public:
		// Creates an empty MinPriorityQueue
		MinPriorityQueue()
		{
			// TODO
		}
		// Returns the number of elements in the MinPriorityQueue.
		//
		// Must run in O(1) time.
		int size()
		{
			return H.size();
		}

		// Pushes a new value x with priority p
		// into the MinPriorityQueue.
		//
		// Must run in O(log(n)) time.		 
		void push(T x, int p)
		{
			// TODO
			// Step 1: Add the new element (value + priority) to the end of the heap
			H.push_back({x, p});

			// Step 2: Get the index of the inserted element
			int i = H.size() - 1;
			I[x] = i;
			// Step 3: Sift up — check if the new node should move up
			while (i > 0) {
				int par = parent(i);

				// If the parent's priority is smaller or equal, heap is balanced
				if (H[par].second <= H[i].second)
					break;

				// Otherwise, swap child and parent
				swap(H[par], H[i]);
				// Update their positions in the map
				I[H[par].first] = par;
				I[H[i].first] = i;
				// Move up
				i = par;
			}
		}

		// Returns the value at the front of the MinPriorityQueue.
		// Undefined behavior if the MinPriorityQueue is empty.
		// 
		// Must run in O(1) time.
		T front()
		{
			// TODO	
			 if (H.empty()) {
				// Optional: handle empty case safely
				return T();  // returns a default-constructed value (like "" or 0)
			}
			return H[0].first;
		}

		// Removes the value at the front of the MinPriorityQueue.
		// Undefined behavior if the MinPriorityQueue is empty.
		//
		// Must run in O(log(n)) time. 
		void pop()
		{
			// TODO	
			if (H.empty()) return;

			// remove mapping for root
			I.erase(H[0].first);

			if (H.size() == 1) {
				H.pop_back();
				return;
			}

			// move last to root
			H[0] = H.back();
			I[H[0].first] = 0;
			H.pop_back();

			int i = 0, n = H.size();

			while (true) {
				int left = 2 * i + 1;
				int right = 2 * i + 2;
				int smallest = i;

				if (left < n && H[left].second < H[smallest].second)
					smallest = left;
				if (right < n && H[right].second < H[smallest].second)
					smallest = right;

				if (smallest == i) break;

				std::swap(H[i], H[smallest]);

				// update map indices
				I[H[i].first] = i;
				I[H[smallest].first] = smallest;

				i = smallest;
			}
	}

		// If x is in the MinPriorityQueue 
		// with current priority at least new_p,  
		// then changes the priority of x to new_p.
		// Undefined behavior otherwise.
		//
		// Must run in O(log(n)) time. 
		void decrease_key(T x, int new_p)
		{
			// TODO
			// Step 1: Check if element exists in the map
			auto it = I.find(x);
			if (it == I.end()) return;  // element not found

			int i = it->second;  // index in the heap

			// Step 2: Only continue if new priority is smaller
			if (new_p >= H[i].second)
				return;

			// Step 3: Update the priority
			H[i].second = new_p;

			// Step 4: Sift up — move the node upward while needed
			while (i > 0) {
				int par = parent(i);

				// If heap property satisfied, stop
				if (H[par].second <= H[i].second)
					break;

				// Swap node with parent
				std::swap(H[par], H[i]);

				// Update their positions in the map
				I[H[par].first] = par;
				I[H[i].first] = i;

				// Move up
				i = par;
			}
		}

	private:
		// You don't need any other instance variables,
		// but you can add some if you want to.
		int parent(int i) {
    		if (i == 0) 
        		return -1;  // root has no parent
    		return (i - 1) / 2;
		}
		vector< pair<T, int> > H; // The heap.
		unordered_map<T, int> I;  // Maps values to their indices in H.
};

#endif 
