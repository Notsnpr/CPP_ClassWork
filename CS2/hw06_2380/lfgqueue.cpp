//***********************************************************************
// Team #13                            CSCI 2380                          Spring 2025                      Homework # 6 
// Victor Munoz
// Luis Elizondo
// Angel Morales
//  
//*********************************************************************** 

#include "lfgqueue.h"
#include <iostream>

// Helper function
void removeAtIndex(Player** arr, int& count, int pos){
    for (int i = pos; i < count - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    count--;
}

LFGQueue::LFGQueue(){
    capacity = 100;
    players = new Player*[capacity];
    count = 0;
}

int LFGQueue::size(){
    return count;
}

void LFGQueue::push_player(Player* p){
    if (count == capacity)
    {
        capacity *= 2;
        Player** bigger = new Player*[capacity];
        for (int i = 0; i < count; i++)
        {
            bigger[i] = players[i];
        }
        delete[] players;
        players = bigger;
    }

    for (int i = count; i > 0; i--)
    {
        players[i] = players[i - 1];
    }

    players[0] = p;
    count++;
}

Player* LFGQueue::front_player(Player::Role r){
    for (int i = count - 1; i >= 0; i--)
    {
        if (players[i]->role() == r)
        {
            return players[i];
        }
    }
    return nullptr;
}

void LFGQueue::pop_player(Player::Role r){
    for (int i = count - 1; i >= 0; i--)
    {
        if (players[i]->role() == r)
        {
            removeAtIndex(players, count, i);
            return; 
        }
    }
}

bool LFGQueue::front_group(Player** group){
    group[0] = nullptr; 
    group[1] = nullptr; 
    group[2] = nullptr; 

    int idxDef = -1, idxHun = -1, idxBar = -1;

    for (int i = count - 1; i >= 0; i--)
    {
        Player::Role r = players[i]->role();
        if (r == Player::Defender && idxDef < 0)
        {
            idxDef = i;
        }
        else if (r == Player::Hunter && idxHun < 0)
        {
            idxHun = i;
        }
        else if (r == Player::Bard && idxBar < 0)
        {
            idxBar = i;
        }
        if (idxDef >= 0 && idxHun >= 0 && idxBar >= 0)
        {
            break;
        }
    }

    if (idxDef < 0 || idxHun < 0 || idxBar < 0)
    {
        if (idxDef >= 0) group[0] = players[idxDef];
        if (idxHun >= 0) group[1] = players[idxHun];
        if (idxBar >= 0) group[2] = players[idxBar];
        return false;
    }

    group[0] = players[idxDef];
    group[1] = players[idxHun];
    group[2] = players[idxBar];
    return true;
}

void LFGQueue::pop_group(){
    int idxDef = -1, idxHun = -1, idxBar = -1;

    for (int i = count - 1; i >= 0; i--)
    {
        Player::Role r = players[i]->role();
        if (r == Player::Defender && idxDef < 0)
        {
            idxDef = i;
        }
        else if (r == Player::Hunter && idxHun < 0)
        {
            idxHun = i;
        }
        else if (r == Player::Bard && idxBar < 0)
        {
            idxBar = i;
        }

        if (idxDef >= 0 && idxHun >= 0 && idxBar >= 0)
        {
            break;
        }
    }

    if (idxDef < 0 || idxHun < 0 || idxBar < 0)
    {
        return;
    }

    int idxArr[3] = {idxDef, idxHun, idxBar};

    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (idxArr[i] < idxArr[j])
            {
                int tmp = idxArr[i];
                idxArr[i] = idxArr[j];
                idxArr[j] = tmp;
            }
        }
    }
    removeAtIndex(players, count, idxArr[0]);
    removeAtIndex(players, count, idxArr[1]);
    removeAtIndex(players, count, idxArr[2]);
}
