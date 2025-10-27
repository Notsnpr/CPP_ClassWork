#include "autocompleter.h"

Autocompleter::Autocompleter() {
	root = new Node();
	count = 0;
}

void Autocompleter::insert(string x, int freq) {
    Node* curr = root;

    // Step 1: Insert characters into the trie
    for (char c : x) {
        unsigned char idx = static_cast<unsigned char>(c);
        if (!curr->children[idx])
            curr->children[idx] = new Node();
        curr = curr->children[idx];
    }

    // Step 2: Mark end of word and store entry
    if (!curr->marked) {
        curr->marked = true;
        ++count;
    }

    // Step 3: Update or insert the entry in this node's top list
    bool found = false;
    for (auto& entry : curr->top) {
        if (entry.s == x) {
            entry.freq = freq;
            found = true;
            break;
        }
    }
    if (!found)
        curr->top.push_back({x, freq});

    // Step 4: Update top completions for every prefix node (including root)
    curr = root;
    for (size_t i = 0; i <= x.size(); ++i) {
        // For i > 0, move deeper in the trie
        if (i > 0) {
            unsigned char idx = static_cast<unsigned char>(x[i - 1]);
            curr = curr->children[idx];
        }

        bool foundPrefix = false;
        for (auto& entry : curr->top) {
            if (entry.s == x) {
                entry.freq = freq;
                foundPrefix = true;
                break;
            }
        }
        if (!foundPrefix)
            curr->top.push_back({x, freq});

        // Sort by frequency (descending) and trim to top 3
        sort(curr->top.begin(), curr->top.end(), [](const Entry& a, const Entry& b) {
            return a.freq > b.freq;
        });
        if (curr->top.size() > 3)
            curr->top.resize(3);
    }
}

int Autocompleter::size() {
	return count;
}

void Autocompleter::completions(string x, vector<string> &T) {
    T.clear();
    Node* curr = root;
    if (x.empty()) {
        for (const auto& entry : curr->top)
            T.push_back(entry.s);
        return;
    }
    for (char c : x) {
        unsigned char idx = static_cast<unsigned char>(c);
        if (!curr->children[idx])
            return;
        curr = curr->children[idx];
    }
    for (const auto& entry : curr->top)
        T.push_back(entry.s);
}

