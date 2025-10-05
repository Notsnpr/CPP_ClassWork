//***********************************************************************
// Team #13                            CSCI 2380                          Spring 2025                      Homework # 1 
// Victor Munoz 
// First and Last Name 
//  
//*********************************************************************** 

#include "pokemon.h"
#include <iostream>

Pokemon::Pokemon(string n, int dex, Type t1){
    _ndex=dex;
    _name=n;
    types[0]=t1;
    type_count=1;
}

Pokemon::Pokemon(string n, int dex, Type t1, Type t2){
    _ndex=dex;
    _name=n;
    types[0]=t1;
    types[1]=t2;
    type_count=2;
}

string Pokemon::name(){
    return _name;
}

int Pokemon::Ndex(){
    return _ndex;
}

Pokemon::Type Pokemon::type1(){
    return types[0];
}

bool Pokemon::is_multitype(){
    return type_count==2;
}

Pokemon::Type Pokemon::type2(){
    return types[1];
}

float Pokemon::damage_multiplier( Type ATK){
    float p_multi[4][4]={{1.0,1.0,1.0,1.0},
                         {2.0,1.0,.5,.5},
                         {1.0,2.0,1.0,1.0},
                         {1.0,1.0,1.0,.5}};
    if (type_count == 1) {
        return p_multi[ATK][types[0]];
    } else {
        return p_multi[ATK][types[0]] * p_multi[ATK][types[1]];
    }
}