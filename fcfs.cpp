/**
@file fcfs.cpp

@brief This file contains the algorithm for simulating and counting total disk 
head movement with a first-come, first-served disk scheduling algorithm. 

@authors Savoy Schuler

@Date 04/28/17 
*/

/// Include library for absolute value.
#include <stdlib.h>

/// Include library for vector use. 
#include <vector>

/// Using standard namespace.
using namespace std;

/**
This function is used to simulate a first-come, first-served disk scheduling 
algorithm by serving random cylinder requests in the order that they arrive. 
The function takes as arguments the starting location of the disk head and a 
queue of requests. After performing the disk scheduling algorithm on all 
requests in the queue, the function will return the sum of movements of the 
disk head. 

@param[in] request_queue    Vector of ints representing cylinder request queue.
@param[in] head             Int representing starting location of disk head. 
@return head_movement       Int summing algorithm's total head movement. 
*/
int fcfs(vector<int> request_queue, int head)
{
    /// Initialize iterator variable.
    int i = 0;

    /// Start head movement count at 0.
    int head_movement = 0;
    
    /** Service each random request in first-come, first-serve order, counting 
    total disk head movement. 
    */
    for (i = 0; i < request_queue.size(); i ++)
    {
        /// Calculate distance between head and next request.
        head_movement = head_movement + abs(head - request_queue[i]);

        /// Add that distance to the total count for head movement. 
        head = request_queue[i];
    }

    /// Return count of total disk head movement. 
    return head_movement;
}

