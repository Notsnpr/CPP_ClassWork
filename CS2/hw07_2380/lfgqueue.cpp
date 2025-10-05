//***********************************************************************
// Team #13                            CSCI 2380                          Spring 2025                      Homework # 6 
// Victor Munoz
// Luis Elizondo
// Angel Morales
//  
//*********************************************************************** 

#include "lfgqueue.h"
#include <iostream> 

using namespace std;

// Constructs a new empty queue
LFGQueue::LFGQueue()
{
    for (int i = 0; i < 3; i++)
    {
        heads[i] = nullptr;
        tails[i] = nullptr;
        counts[i] = 0;
    }
}

// Returns the number of players in the queue.
int LFGQueue::size()
{
    return counts[0] + counts[1] + counts[2];
}

// Adds a player to the back of the queue.
void LFGQueue::push_player(Player* plyr)
{
    // Create a new node and set its fields
    Node* newNode = new Node;
    newNode->p = plyr;
    newNode->next = nullptr;

    int r = plyr->role(); // 0 for Defender, 1 for Hunter, 2 for Bard

    // If that particular role's list is empty, both head and tail become newNode
    if (heads[r] == nullptr)
    {
        heads[r] = newNode;
        tails[r] = newNode;
    }
    else
    {
        // Otherwise, append to the tail
        tails[r]->next = newNode;
        tails[r] = newNode;
    }

    // Increase count for that role
    counts[r]++;
}

// Returns a pointer to the frontmost player 
// with the specified role. If no such player 
// exists, returns nullptr.
Player* LFGQueue::front_player(Player::Role r)
{
    if (heads[r] == nullptr)
        return nullptr;

    return heads[r]->p;
}

// Removes the frontmost player with the
// specified role. If no such player exists
// does nothing.
void LFGQueue::pop_player(Player::Role r)
{
    // If the queue for that role is empty, do nothing
    if (heads[r] == nullptr)
        return;

    // Otherwise, remove the head node
    Node* temp = heads[r];
    heads[r] = heads[r]->next;

    // If after removing, the list is empty, tail should be nullptr as well
    if (heads[r] == nullptr)
        tails[r] = nullptr;

    // Decrement the count for that role
    counts[r]--;

    // Free the node (but not the Player*, which belongs to the caller)
    delete temp;
}

// Returns whether the queue contains a complete group
// (a Defender, a Hunter, and a Bard).
//
// If the queue contains a complete group, the method
// sets the first three elements of the array parameter
// equal to the addresses of the frontmost:
// 1. Defender (index 0)
// 2. Hunter (index 1)
// 3. Bard (index 2)
bool LFGQueue::front_group(Player** group)
{
    // We need at least one of each role
    if (counts[0] > 0 && counts[1] > 0 && counts[2] > 0)
    {
        group[0] = heads[0]->p; // Defender
        group[1] = heads[1]->p; // Hunter
        group[2] = heads[2]->p; // Bard
        return true;
    }
    return false;
}

// Removes the frontmost Defender, Hunter, 
// and Bard from the queue. If some role
// has no player with that role, then
// no players are removed.
void LFGQueue::pop_group()
{
    // Check if we have at least one of each
    if (counts[0] > 0 && counts[1] > 0 && counts[2] > 0)
    {
        // Remove the front of each queue
        pop_player(Player::Defender);
        pop_player(Player::Hunter);
        pop_player(Player::Bard);
    }
}
