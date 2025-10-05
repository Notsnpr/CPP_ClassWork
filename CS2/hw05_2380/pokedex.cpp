#include "pokedex.h"
#include <iostream>
#include <fstream>  // for ifstream, ofstream
using namespace std;

// Empty Pokedex constructor
Pokedex::Pokedex() {
    for (int i = 0; i < 1000; i++) {
        A[i] = nullptr;
    }
}

// Constructs a Pokedex with the Pokemon found in the specified file. 
Pokedex::Pokedex(string filename) {
    for (int i = 0; i < 1000; i++) {
        A[i] = nullptr;
    }
    // Open file
    ifstream fin(filename.c_str());
    if(!fin.is_open()) {
        return;  // if it fails
    }
    // Read each line
    string line;
    while(true) {
        if(!getline(fin, line)) break;  // no more lines
        if(line.size() == 0) continue;  // ignore blank
        Pokemon* p = new Pokemon(line);
        add(p);
    }
    fin.close();
}

// Writes the Pokedex to the file.
void Pokedex::save(string filename) {
    ofstream fout(filename.c_str());
    if(!fout.is_open()) {
        return; 
    }
    for (int i = 0; i < 1000; i++) {
        if(A[i] != nullptr) {
            fout << A[i]->summary() << endl;
        }
    }
    fout.close();
}

// Adds a pokemon to the pokedex.
// When adding a Pokemon, store its pointer in the array element whose
// index is equal to the Pokemon's Ndex.
void Pokedex::add(Pokemon* p) {
    if (!p) return;
    int nd = p->Ndex();
    if(nd < 0 || nd >= 1000) return;
    // Only store if it's empty
    if(A[nd] == nullptr) {
        A[nd] = p;
    }
}

// Removes a pokemon from the pokedex.
// When removing a Pokemon, do so by setting the corresponding 
// array index equal to nullptr.
void Pokedex::remove(Pokemon* p) {
    if (!p) return;
    int nd = p->Ndex();
    if(nd < 0 || nd >= 1000) return;
    // Just set that slot to nullptr
    A[nd] = nullptr;
}

// Returns a (pointer to a) pokemon in the pokedex with the given name.
// If none exists, returns nullptr.
//
// Hint: loop through all of A, searching for a Pokemon with
// the given name. Return the first one found.
Pokemon* Pokedex::lookup_by_name(string name) {
    for (int i = 0; i < 1000; i++) {
        if(A[i] != nullptr) {
            if(A[i]->name() == name) {
                return A[i];
            }
        }
    }
    return nullptr;
}

// Returns a (pointer to a) pokemon in the pokedex with the given Ndex.
// If none exists, returns nullptr.
//
// Hint: look in A[ndex]. 
Pokemon* Pokedex::lookup_by_Ndex(int ndex) {
    if(ndex < 0 || ndex >= 1000) {
        return nullptr;
    }
    return A[ndex];
}

// Returns the number of pokemon in the pokedex.
int Pokedex::size() {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if(A[i] != nullptr) {
            count++;
        }
    }
    return count;
}
