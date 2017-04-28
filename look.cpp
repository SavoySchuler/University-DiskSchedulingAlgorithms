/**
@file look.cpp

@brief This file contains the algorithm for simulating and counting total disk 
head movement with a look disk scheduling algorithm. 

@authors Savoy Schuler

@Date 04/28/17 
*/

/// Include library for vector use. 
#include <vector>

/// Using standard namespace.
using namespace std;

/**
This function is used to simulate a look disk scheduling algorithm. The 
function takes as arguments the starting location of the disk head and a queue 
of requests. After performing the disk scheduling algorithm on all requests in 
the queue, the function will return the sum of movements of the disk head. 

@param[in] request_queue    Vector of ints representing cylinder request queue.
@param[in] head             Int representing starting location of disk head. 
@return head_movement       Int summing algorithm's total head movement. 
*/
int look(vector<int> request_queue, int head)
{
    int i = 0;

    int head_movement = 0;

    bool direction = 0;
    
    bool bounce = false;  

    int largest = 0, smallest;   

    for (i = 0; i < request_queue.size(); i++)
    {
        if (request_queue[i] < head)
        {
            bounce = true;
            smallest = request_queue[i];
        }

        else if (request_queue[i] > largest)    
        {
            largest = request_queue[i];
        }
    }

    if (bounce = true)
    {
        head_movement = head - smallest + 2*(largest - head);
    }
    
    else
    {
        head_movement = largest - head;
    }
    
    return head_movement;
}

