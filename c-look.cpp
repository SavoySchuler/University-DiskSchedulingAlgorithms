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
This function is used to simulate a c-look disk scheduling algorithm which 
circularly scans the disk for requests, skipping to the smallest cylinder 
request every time the largest outstanding cylinder request is reached. The 
function takes as arguments the starting location of the disk head and a queue 
of requests. After performing the disk scheduling algorithm on all requests in 
the queue, the function will return the sum of movements of the disk head. 

@param[in] request_queue    Vector of ints representing cylinder request queue.
@param[in] arrival_times    Vector of ints representing request arrival times.
@param[in] head             Int representing starting location of disk head. 
@return head_movement       Int summing algorithm's total head movement. 
*/
int c_look(vector<int> request_queue, vector<int> arrival_times, int head)
{
    /// Initialize iterator variable.
    int i = 0;

    /// Initialize variable for counting total disk head movement.
    int head_movement = 0;

    /// Store number of requests in simulation waiting to be served.
    int requests_remaining = request_queue.size()-1;

    /// Initialize request array filled with zeros.
    int request_array [DISK_SIZE] = {};

    /// Index of next request in request_queue to be added to request array.
    int request_up = 0;

    /// Variable for adding request to request array at random times.
    int request_arriving_at = 0;

    /// Add counter for checking to see if request should be delivered. 
    int request_arriving_count = -1;

    /// Keep track of largest request cylinder as turning point. 
    int smallest_requested_cylinder = DISK_SIZE;

    /// Keep track of smallest request cylinder as turning point. 
    int largest_requested_cylinder = -1;
 
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

            /// If the request was at the largest cylinder with a request...
            if(head == largest_requested_cylinder)
            {
                /// Search for the next largest cylinder request.
                for (i = 0; i < DISK_SIZE; i++)
                {
                    /// If a cylinder has a request waiting...
                    if (request_array[i] == 1)
                    {
                        /// Store its index in largest_requested_cylinder.
                        largest_requested_cylinder = i;
                    }
                }   
            }

            /// If the request was at the smallest cylinder with a request...
            if(head == smallest_requested_cylinder)
            {
                //Default to zero in case no outstanding requests.
                smallest_requested_cylinder = 0;

                /// Search for the first (smallest) cylinder request.
                for (i = 0; i < DISK_SIZE; i++)
                {
                    /// If a cylinder has a request waiting...
                    if (request_array[i] == 1)
                    {
                        /// Store its index in smallest_requested_cylinder.
                        smallest_requested_cylinder = i;
    
                        /// And break.
                        break;
                    }
                } 
            }               
        }            

        /// If end of disk or largest request reached, head to smallest request.
        if(head >= DISK_SIZE-1 || head >= largest_requested_cylinder)
            head = smallest_requested_cylinder;

        /// Else, keep moving up.
        else
            head++;


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

            /// Else...
            else
            {
                /// Mark a request at that cylinder.
                request_array[request_queue[request_up]] = 1;

                /// Update smallest request index if new request is smaller.
                if (request_queue[request_up] < smallest_requested_cylinder)
                    smallest_requested_cylinder = request_queue[request_up]; 

                /// Update largest request index if new request is larger.
                if (request_queue[request_up] > largest_requested_cylinder)
                    largest_requested_cylinder = request_queue[request_up];
            }

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

