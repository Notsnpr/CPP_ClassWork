//*********************************************************************** 
// Team # 13                         CSCI 2380                          Spring 2025                        Homework # 3 
// Victor Munoz
// First and Last Name 
//  
//***********************************************************************
#include "canvas.h"
#include <iostream>

// Allocates a canvas of the given width and height 5 that
// consists entirely of ' ' (space) chars. If the width is 0,
// the canvas is empty (pointer is NULL and _width is 0)
Canvas::Canvas(int width) {
    if (width <= 0) {
        // If width is 0 (or negative, just in case),
        // set everything to empty.
        C = nullptr; 
        _width = 0;
    } 
    else {
        _width = width;

        // Allocate the row pointers.
        C = new char*[5];
        for (int i = 0; i < 5; ++i) {
            // Allocate each row to have 'width' columns.
            C[i] = new char[width];
        }

        // Fill it with spaces.
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < width; ++j) {
                C[i][j] = ' ';
            }
        }
    }
}


// Allocates a canvas with width 5 and height 5 that looks like:
//
//  ###       ####        ####     ####
// #   #      #   #      #         #   #
// #####  or  ####   or  #      or #   #
// #   #      #   #      #         #   #
// #   #      ####        ####     ####
//
// depending upon which character ('A', 'B', 'C', or 'D') is 
// given as a parameter. If some other character is given, 
// allocates a canvas of ' ' chars with width 5 and height 5.
Canvas::Canvas(char x){

    if(x=='\0'){
        _width=0;
        C=nullptr;
        return;
    }

    char **arr = new char*[5];
    for (int i = 0; i < 5; ++i) {
        arr[i] = new char[5];
    }    
    _width = 5;
    C = arr;
    for(int i = 0; i<5; ++i){
        for(int j = 0; j<5; ++j){
            C[i][j] = ' ';
        }
    }
    if(x == 'A'){
        C[0][1] = '#';
        C[0][2] = '#';
        C[0][3] = '#';
        C[1][0] = '#';
        C[1][4] = '#';
        C[2][0] = '#';
        C[2][1] = '#';
        C[2][2] = '#';
        C[2][3] = '#';
        C[2][4] = '#';
        C[3][0] = '#';
        C[3][4] = '#';
        C[4][0] = '#';
        C[4][4] = '#';

    }else if(x == 'B'){
        C[0][0] = '#';
        C[0][1] = '#';
        C[0][2] = '#';
        C[0][3] = '#';
        C[1][0] = '#';
        C[1][4] = '#';
        C[2][0] = '#';
        C[2][1] = '#';
        C[2][2] = '#';
        C[2][3] = '#';
        C[3][0] = '#'; 
        C[3][4] = '#'; 
        C[4][0]=  '#' ;
        C[4][1]=  '#' ;
        C[4][2]=  '#' ;
        C[4][3]=  '#' ;
        
    }else if(x == 'C'){
        C[0][1] = '#';
        C[0][2] = '#';
        C[0][3] = '#';
        C[0][4] = '#';
        C[1][0] = '#';
        C[2][0] = '#';
        C[3][0] = '#';
        C[4][1] = '#';
        C[4][2] = '#';
        C[4][3] = '#';
        C[4][4] = '#';
        
    }else if(x == 'D'){
        C[0][0] = '#';
        C[0][1] = '#';
        C[0][2] = '#';
        C[0][3] = '#';
        C[1][0] = '#';
        C[1][4] = '#';
        C[2][0] = '#';
        C[2][4] = '#';
        C[3][0] = '#';
        C[3][4] = '#';
        C[4][0] = '#';
        C[4][1] = '#';
        C[4][2] = '#';
        C[4][3] = '#';
        
    }else{
        // For any other character, leave as a blank canvas.
    }
}

// Returns the width of the canvas.
int Canvas::width(){
    return _width;
}

// Returns the entire canvas as a single string, consisting of each row
// of the canvas, followed by the newline character ('\n').
// If the canvas is empty, returns an empty string.
string Canvas::to_string() {
    if (C == nullptr) {
        // Empty canvas => return empty string
        return "";
    }

    // Otherwise, build the string as before.
    string str;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < _width; ++j) {
            str += C[i][j];
        }
        str += '\n';
    }
    return str;
}


// Replaces every instance in the canvas of old_char with new_char.
// For instance, if old_char is '#' and new char is '@', then: 
// 
//  ###             @@@
// #   #           @   @
// #####  becomes  @@@@@ 
// #   #           @   @
// #   #           @   @
//
void Canvas::replace(char old_char, char new_char){
    for(int i = 0; i<5; ++i){
        for(int j = 0; j<_width; ++j){
            if(C[i][j] == old_char){
                C[i][j] = new_char;
            }
        }
    }
}

// Destructor. Deallocates all of the memory allocated by the canvas.
Canvas::~Canvas() {
    if (C != nullptr) {
        for (int i = 0; i < 5; ++i) {
            delete[] C[i];
        }
        delete[] C;
    }
}


void Canvas::add(char x){
    int maxwidth = _width;
    if(_width != 0)
    {
        maxwidth += 7;
    }
    else
    {
        maxwidth += 5;
    }
    char **newCanvas = new char*[5];
    for (int i = 0; i < 5; ++i) {
        newCanvas[i] = new char[maxwidth];
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < _width; ++j) {
            newCanvas[i][j] = C[i][j];
        }
        for (int j = _width; j < maxwidth; ++j) {
            newCanvas[i][j] = ' ';
        }
    }

    // Only delete the old canvas if it exists.
    if(C != nullptr) {
        for (int i = 0; i < 5; ++i) {
            delete[] C[i];
        }
        delete[] C;
    }

    C = newCanvas;
    _width = maxwidth;

    switch (x) {
        case 'A':
            C[0][_width - 4] = '#';
            C[0][_width - 3] = '#';
            C[0][_width - 2] = '#';
            C[1][_width - 5] = '#';
            C[1][_width - 1] = '#';
            C[2][_width - 5] = '#';
            C[2][_width - 4] = '#';
            C[2][_width - 3] = '#';
            C[2][_width - 2] = '#';
            C[2][_width - 1] = '#';
            C[3][_width - 5] = '#';
            C[3][_width - 1] = '#';
            C[4][_width - 5] = '#';
            C[4][_width - 1] = '#';
            break;
        case 'B':
            C[0][_width - 5] = '#';
            C[0][_width - 4] = '#';
            C[0][_width - 3] = '#';
            C[0][_width - 2] = '#';
            C[1][_width - 5] = '#';
            C[1][_width - 1] = '#';
            C[2][_width - 5] = '#';
            C[2][_width - 4] = '#';
            C[2][_width - 3] = '#';
            C[2][_width - 2] = '#';
            C[3][_width - 5] = '#';
            C[3][_width - 1] = '#';
            C[4][_width - 5] = '#';
            C[4][_width - 4] = '#';
            C[4][_width - 3] = '#';
            C[4][_width - 2] = '#';
            break;
        case 'C':
            C[0][_width - 4] = '#';
            C[0][_width - 3] = '#';
            C[0][_width - 2] = '#';
            C[0][_width - 1] = '#';
            C[1][_width - 5] = '#';
            C[2][_width - 5] = '#';
            C[3][_width - 5] = '#';
            C[4][_width - 4] = '#';
            C[4][_width - 3] = '#';
            C[4][_width - 2] = '#';
            C[4][_width - 1] = '#';
            break;
        case 'D':
            C[0][_width - 5] = '#';
            C[0][_width - 4] = '#';
            C[0][_width - 3] = '#';
            C[0][_width - 2] = '#';
            C[1][_width - 5] = '#';
            C[1][_width - 1] = '#';
            C[2][_width - 5] = '#';
            C[2][_width - 1] = '#';
            C[3][_width - 5] = '#';
            C[3][_width - 1] = '#';
            C[4][_width - 5] = '#';
            C[4][_width - 4] = '#';
            C[4][_width - 3] = '#';
            C[4][_width - 2] = '#';
            break;
        default:
            // For any non A, B, C, or D character, leave the block as spaces.
            break;
    }
}



Canvas::Canvas(string s) : _width(0), C(nullptr) {
    for(int w=0; w< s.length(); w++){
        add(s[w]);
    }
}
