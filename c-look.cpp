/**
@file c-look.cpp

@brief This file contains the algorithm for simulating and counting total disk 
head movement with a circular-look disk scheduling algorithm. 

@authors Savoy Schuler

@Date 04/28/17 
*/

/// Include library for vector use. 
#include <vector>

/// Using standard namespace.
using namespace std;

/**
This function is used to simulate a c-look disk scheduling algorithm. The 
function takes as arguments the starting location of the disk head and a queue 
of requests. After performing the disk scheduling algorithm on all requests in 
the queue, the function will return the sum of movements of the disk head. 

@param[in] request_queue    Vector of ints representing cylinder request queue.
@param[in] head             Int representing starting location of disk head. 
@return head_movement       Int summing algorithm's total head movement. 
*/
int c_look(vector<int> request_queue, int head)
{
    /// Initialize iterator variable.
    int i = 0;

    /// Start head movement count at 0.
    int head_movement = 0;
    
    bool bounce = false;  

    int largest = 0, largest_under_head = 0, smallest = 201;   

    for (i = 0; i < request_queue.size(); i++)
    {
        if (request_queue[i] < head)
        {
            bounce = true;
            
            if ( request_queue[i] < smallest)
                smallest = request_queue[i];

            if  (request_queue[i] > largest_under_head)
                largest_under_head = request_queue[i];
        }

        else if (request_queue[i] > largest)    
        {
            largest = request_queue[i];
        }
    }

    if (bounce = true)
    {
        head_movement = (largest - head) + (largest_under_head - smallest);
    }
    
    else
    {
        head_movement = largest - head;
    }
    
    return head_movement;
}

