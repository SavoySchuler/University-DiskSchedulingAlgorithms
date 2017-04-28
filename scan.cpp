/**
@file scan.cpp

@brief This file contains the algorithm for simulating and counting total disk 
head movement with a scan disk scheduling algorithm. 

@authors Savoy Schuler

@Date 04/28/17 
*/

/// Include library for vector use. 
#include <vector>

/// Using standard namespace.
using namespace std;

/**
This function is used to simulate a scan disk scheduling algorithm by scanning
up and down a disk, serving requests at the needed cylinders as they are 
reached. The function takes as arguments the starting location of the disk head 
and a queue of requests. After performing the disk scheduling algorithm on all 
requests in the queue, the function will return the sum of movements of the disk
head. 

@param[in] request_queue    Vector of ints representing cylinder request queue.
@param[in] arrival_times    Vector of ints representing request arrival times.
@param[in] head             Int representing starting location of disk head. 
@return head_movement       Int summing algorithm's total head movement. 
*/
int scan(vector<int> request_queue, vector<int> arrival_times, int head)
{
    /// Initialize variable for counting total disk head movement.
    int head_movement = 0;

    /// Store number of requests in simulation waiting to be served.
    int requests_remaining = request_queue.size()-1;

    /// Initialize request array filled with zeros.
    int request_array [DISK_SIZE] = {};

    /// Index of next request in request_queue to be added to request array.
    int request_up = 0;

    /// Mark direction of head movement. True == up, false == down. 
    bool direction = true; 

    /// Variable for adding request to request array at random times.
    int request_arriving_at = 0;

    /// Add counter for checking to see if request should be delivered. 
    int request_arriving_count = -1;
 
    /// Run scan while requests remain in simulation. 
    while(requests_remaining > 0)
    {
        /// If the disk head is over a requested cylinder...
        if (request_array[head] != 0)
        {   
            /// Serve the request.
            request_array[head] = 0;
            
            /// Decrement the number of requests remaining in the simulation.
            requests_remaining--;

            /// Pass a unit of time while a request is served.
            request_arriving_count++;  
        }            

        /// If the top of the disk is reached, starting moving down the disk.
        if(head >= DISK_SIZE-1)
            direction = false;

        /// If the bottom of the disk is reached, starting moving up the disk.
        else if ( head <= 0)
            direction = true;
        
        /// If direction is up, step the disk head up.
        if (direction)
            head++;

        /// If direction is down, step the disk head down.        
        else 
            head--;

        /// Keep count of total disk head movement in simulation.
        head_movement++;
    
        /// Pass a unit of time every time the disk head moves.
        request_arriving_count++;   

        /// Add request to queue at their arrival time while requests remain.
        if (request_arriving_count >= request_arriving_at && request_up <= 
            request_queue.size())
        {
            /** If a request already exists at that cyclinder, decrement 
            remaining requests by one as all requests for the cylinder will be 
            served at the same time.*/
            if ( request_array[request_queue[request_up]] == 1 )
                requests_remaining--;

            /// Else, mark request at that cylinder.
            else
                request_array[request_queue[request_up]] = 1;

            /// Mark next request for delivery.
            request_up++;

            /// Get random time for new request to arrive.            
            request_arriving_at = arrival_times[request_up];

            /// Set request arrival count back;
            request_arriving_count = -1;
        }
    }

    /// Return count of total disk head movement. 
    return head_movement;
}

