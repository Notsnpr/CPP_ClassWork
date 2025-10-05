//***********************************************************************
// Team #13                            CSCI 2380                          Spring 2025                      Homework # 5 
// Victor Munoz
// Luis Elizondo
// Angel Morales
//  
//*********************************************************************** 

#include "pokemon.h"
#include <iostream>  // for basic I/O
#include <cctype>    // for isspace
#include <cstdlib>   // for atoi
using namespace std;

static void trim_string(string &s);
static string ndex_to_3digits(int n);

// HW1
Pokemon::Pokemon(string n, int dex, Type t1) {
    _name      = n;
    _ndex      = dex;
    types[0]   = t1;
    type_count = 1;
}

Pokemon::Pokemon(string n, int dex, Type t1, Type t2) {
    _name      = n;
    _ndex      = dex;
    types[0]   = t1;
    types[1]   = t2;
    type_count = 2;
}

string Pokemon::name() {
    return _name;
}

int Pokemon::Ndex() {
    return _ndex;
}

Pokemon::Type Pokemon::type1() {
    return types[0];
}

bool Pokemon::is_multitype() {
    return (type_count == 2);
}

Pokemon::Type Pokemon::type2() {
    return types[1];
}

float Pokemon::damage_multiplier(Type attack_type) {


    float table[4][4] = {
        {1.0, 1.0, 1.0, 1.0},    
        {2.0, 1.0, 0.5, 0.5},    
        {1.0, 2.0, 1.0, 1.0},    
        {1.0, 1.0, 1.0, 0.5}     
    };

    if (type_count == 1) {
        return table[attack_type][types[0]];
    } else {
        return table[attack_type][types[0]] * table[attack_type][types[1]];
    }
}

// A summary string is a single string that contains 
// all of a Pokemon's information.
// 
// A Pokemon with one type and Ndex 5 has 
// a summary string of the form:
// "Name, #005, type1,"
// 
// Similarly, a Pokemon with two types and Ndex 12 has 
// a summary string of the form:
// "Name, #012, type1, type2," 

// Initializes a Pokemon from a summary string
//
// Hint: check out the stoi function in <string>
Pokemon::Pokemon(string summary) {
    size_t c1 = summary.find(',');
    _name = summary.substr(0, c1);
    trim_string(_name);
    _ndex = 0;  // default if parse fails
    if (c1 != string::npos) {
        size_t hashPos = summary.find('#', c1);
        if (hashPos != string::npos) {
            size_t c2 = summary.find(',', hashPos);
            if (c2 == string::npos) c2 = summary.size();
            string digitsOnly = "";
            for (size_t i = hashPos; i < c2; i++) {
                if (isdigit(summary[i])) {
                    digitsOnly.push_back(summary[i]);
                }
            }
            if (!digitsOnly.empty()) {
                _ndex = atoi(digitsOnly.c_str());
            }
        }
    }
    type_count = 0;
    size_t commaAfterNum = summary.find(',', summary.find('#'));
    if (commaAfterNum == string::npos) {
        types[0] = Normal;
        type_count = 1;
        return;
    }

    //first type
    size_t c3 = summary.find(',', commaAfterNum + 1);
    if (c3 == string::npos) c3 = summary.size();
    string t1 = summary.substr(commaAfterNum + 1, c3 - (commaAfterNum + 1));
    trim_string(t1);
    if (!t1.empty()) {
        types[0] = string_to_type(t1);
        type_count = 1;
    } else {
        types[0] = Normal;
        type_count = 1;
    }
    //possible second type
    size_t c4 = summary.find(',', c3 + 1);
    if (c4 == string::npos) c4 = summary.size();
    string t2 = summary.substr(c3 + 1, c4 - (c3 + 1));
    trim_string(t2);
    if (!t2.empty()) {
        types[1] = string_to_type(t2);
        type_count = 2;
    }
}

// Returns the summary string of the Pokemon
string Pokemon::summary() {
    string ndexStr = ndex_to_3digits(_ndex); 
    string s = _name + ", #" + ndexStr + ", " + type_to_string(types[0]) + ",";
    if (is_multitype()) {
        s += " " + type_to_string(types[1]) + ",";
    }
    return s;
}

//functions
string type_to_string(Pokemon::Type t) {
    switch(t) {
        case Pokemon::Normal:   return "Normal";
        case Pokemon::Fighting: return "Fighting";
        case Pokemon::Flying:   return "Flying";
        case Pokemon::Poison:   return "Poison";
    }
    return "Normal";
}

Pokemon::Type string_to_type(string s) {
    if (s == "Normal")   return Pokemon::Normal;
    if (s == "Fighting") return Pokemon::Fighting;
    if (s == "Flying")   return Pokemon::Flying;
    if (s == "Poison")   return Pokemon::Poison;
    return Pokemon::Normal;
}

// Helper: trims leading/trailing spaces
static void trim_string(string &s) {
    while (!s.empty() && isspace(s[0])) {
        s.erase(s.begin());
    }
    while (!s.empty() && isspace(s[s.size() - 1])) {
        s.erase(s.end() - 1);
    }
}

// Converts an int to a 3-digit string with basic array logic.
static string ndex_to_3digits(int n) {
    // We'll build an array of 4 chars: 3 digits + null terminator
    char buf[4];
    buf[3] = '\0'; // null-terminate

    // Fill from right to left with '0'+digit
    int temp = n;
    for (int i = 2; i >= 0; i--) {
        int digit = temp % 10;
        temp /= 10;
        buf[i] = static_cast<char>(digit + '0');
    }
    // e.g.  56 -> "056",   7 -> "007",   641 -> "641"
    return string(buf);
}
