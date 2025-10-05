//***********************************************************************
// Team #13                            CSCI 2380                          Spring 2025                      Homework # 9
// Victor Munoz
// Luis Elizondo
// Angel Morales
//  
//*********************************************************************** 

#include "hack.h"
#include <string>
#include <iostream>

using namespace std;

bool isHacked(EvilComputer* ec, const string& user)
{
    return ec->is_hacked(user);
}

void hackDave(EvilComputer* ec);
void hackDaveRec(EvilComputer* ec, const string& current);

void hackMrMean(EvilComputer* ec);
void hackMrMeanRec(EvilComputer* ec, const string& current, int depth);

void hackMsChief(EvilComputer* ec);
void hackMsChiefRec(EvilComputer* ec, const string& current, int maxLength);

void hackDrEvil(EvilComputer* ec);
void hackDrEvilRec(EvilComputer* ec, const string& current, int totalLength, bool prefix);


// This function receives the address of the computer to be hacked and hacks its five accounts.
// It calls four recursive functions to hack the different accounts except for the Guest account
// since it is not necessary a recursive function to hack it.
void hack(EvilComputer* ec)
{
    // we already know Guest's password is "passw123".
    ec->guess("Guest", "passw123");
    hackDave(ec);
    hackMrMean(ec);
    hackMsChief(ec);
    hackDrEvil(ec);
}

void hackDave(EvilComputer* ec)
{
    if (!isHacked(ec, "Dave"))
    {
        hackDaveRec(ec, "");
    }
}

void hackDaveRec(EvilComputer* ec, const string& current)
{
    // if length = 4 make a guess.
    if (current.size() == 4)
    {
        ec->guess("Dave", current);
        return;  // Return after each guess.
    }

    for (int d = 0; d < 10; ++d)
    {
        // if already hacked stop
        if (ec->is_hacked("Dave")) 
            return;

        hackDaveRec(ec, current + static_cast<char>('0' + d));
    }
}

void hackMrMean(EvilComputer* ec)
{
    if (!isHacked(ec, "Mr. Mean"))
    {
        hackMrMeanRec(ec, "", 0);
    }
}

// depth indicates how many characters we have chosen so far.
void hackMrMeanRec(EvilComputer* ec, const string& current, int depth)
{
    // if we have at least 1 character, guess that password.
    if (depth > 0) 
    {
        ec->guess("Mr. Mean", current);
        if (ec->is_hacked("Mr. Mean"))
            return;
    }

    if (depth == 8) 
        return;

    hackMrMeanRec(ec, current + 'g', depth + 1);
    if (ec->is_hacked("Mr. Mean")) return;

    hackMrMeanRec(ec, current + 'r', depth + 1);
}

void hackMsChief(EvilComputer* ec)
{
    if (!isHacked(ec, "Ms. Chief"))
    {
        hackMsChiefRec(ec, "haha", 8);  
    }
}

void hackMsChiefRec(EvilComputer* ec, const string& current, int maxLength)
{
    ec->guess("Ms. Chief", current);
    if (ec->is_hacked("Ms. Chief"))
        return;

    // If we maxLength = 8 stop
    if ((int)current.size() == maxLength)
        return;
        
    for (int i = 0; i < 36; i++)
    {
        if (ec->is_hacked("Ms. Chief")) 
            return;

        char c;
        if (i < 10)
            c = '0' + i;
        else
            c = 'a' + (i - 10);

        hackMsChiefRec(ec, current + c, maxLength);

        if (ec->is_hacked("Ms. Chief"))
            return;
    }
}

void hackDrEvil(EvilComputer* ec)
{
    if (!isHacked(ec, "Dr. Evil"))
    {
        hackDrEvilRec(ec, "", 4, true);
        hackDrEvilRec(ec, "", 5, true);
        hackDrEvilRec(ec, "", 6, true);
        hackDrEvilRec(ec, "", 7, true);
        hackDrEvilRec(ec, "", 8, true);
        
        
        if (!ec->is_hacked("Dr. Evil"))
        {
            hackDrEvilRec(ec, "", 4, false);
            hackDrEvilRec(ec, "", 5, false);
            hackDrEvilRec(ec, "", 6, false);
            hackDrEvilRec(ec, "", 7, false);
            hackDrEvilRec(ec, "", 8, false);
        }
    }
}

void hackDrEvilRec(EvilComputer* ec, const string& current, int totalLength, bool prefix)
{
    if (ec->is_hacked("Dr. Evil")) 
        return;

    if ((int)current.size() + 4 == totalLength)
    {
        string attempt;
        if (prefix)
            attempt = "gato" + current;  // "gatoXYZ..."
        else
            attempt = current + "gato";  // "XYZ...gato"

        ec->guess("Dr. Evil", attempt);
        return;
    }

    for (int i = 0; i < 36; i++)
    {
        if (ec->is_hacked("Dr. Evil")) 
            return;

        char c;
        if (i < 10) 
            c = '0' + i;
        else 
            c = 'a' + (i - 10);

        hackDrEvilRec(ec, current + c, totalLength, prefix);

        if (ec->is_hacked("Dr. Evil"))
            return;
    }
}
