/**
@file sstf.cpp

@brief This file contains the algorithm for simulating and counting total disk 
head movement with a shortest-seek-time-first disk scheduling algorithm. 

@authors Savoy Schuler

@Date 04/28/17 
*/

/// Include library for vector use. 
#include <vector>

/// Using standard namespace.
using namespace std;

/**
This function is used to simulate a shortest-seek-time-first disk scheduling 
algorithm. The function takes as arguments the starting location of the disk 
head and a queue of requests. After performing the disk scheduling algorithm on 
all requests in the queue, the function will return the sum of movements of the 
disk head. 

@param[in] request_queue    Vector of ints representing cylinder request queue.
@param[in] head             Int representing starting location of disk head. 
@return head_movement       Int summing algorithm's total head movement. 
*/
int sstf(vector<int> request_queue, int head)
{
    /// Initialize iterator variables.
    int i = 0, j = 0;
    
    /// Variable for calculating each request's distance from the head.
    int temp_distance = 0;

    /// Variable for storing the closest found request distance.
    int closest_distance = DISK_SIZE + 1;

    /// Variable for storing the closest found request index.
    int closest_index = -1;

    /// Variable for counting the total disk gead movement. 
    int head_movement = 0;
    
    /// Grab the starting size of the request array.
    int requests = request_queue.size();

    /// For the total number of requests upon start...
    for (i = 0; i < requests; i ++)
    {   
        /// Reset variables for storing closest found request.
        closest_distance = DISK_SIZE + 1;
        closest_index = -1;

        /// For each remaining request...
        for (j = 0; j < request_queue.size(); j++)
        {
            /// Find request's distance from the disk head.
            temp_distance = abs(head - request_queue[j]);

            /// If request is closer than the current closest found...
            if (temp_distance < closest_distance)
            {
                /// Update closest found request to current request.
                closest_distance = temp_distance;
                closest_index = j;
            }
        }

        /// Update head movement to include distance to closest request.
        head_movement += closest_distance;

        /// Update head location to closest request. 
        head = request_queue[closest_index];

        /// Erase request under head from remaining requests.
        request_queue.erase(request_queue.begin()+closest_index);
    }

    /// Return total disk head movement. 
    return head_movement;
}

