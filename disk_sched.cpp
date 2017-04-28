/**
@file disk_sched.cpp

@brief 

    Program Description:
    
        This program provides a simulation of FCFS, SSTF, SCAN, C-SCAN, LOOK, 
        and C-LOOK disk-scheduling algorithms performed on a disk with 5,000 
        cylinders numbered 0 to 4,999 and servicing the same 1,000 randomly 
        generated cylinder requests by each algorithm. The program is passed the
        initial position of the disk head as a commadn line parameter from the 
        user and reports the total disk head movement required by each 
        algorithm.

    File Description:
    
        This file contains the program main and a function used to generate
        1,000 random cylinder requests.

    Class: CSC 456 Operating Systems

    Instructor: Dr. Chrsiter Karlsson

    Compilation Instructions: make

    Run Instructions: ./disk_sched <int> 

        Where <int> is the starting position of the disk head.

@author Savoy Schuler

@Date 04/28/2017     
*/

/// Include program .h for disk size and num request defines.
#include "disk.h"

/// Include disk scheduling algorithms to be simulated.
#include "c-look.cpp"
#include "c-scan.cpp"
#include "fcfs.cpp"
#include "look.cpp"
#include "scan.cpp"
#include "sstf.cpp"

/// Include library for cout output.
#include <iostream>

/// Include library for vectors.
#include <vector>

/// Include libraries for use of rand and absolute value. 
#include <stdlib.h>
#include <time.h>

/// Using standard namespace. 
using namespace std;

/**
This function is used to generate 1,000 random cylinder requests and return them
in a vector.

@return request_queue   A vector containing 1,000 randomly generated cylinder 
                        requests.
*/
vector<int> populate_request_queue()
{
    /// Initialize iterator variable.
    int i = 0;

    /// Initialize temporary queue for holding random cylinder requests.
    vector<int> request_queue;

    /// Seed rand.
    srand(time(NULL));

    /// Populate the request queue with random cylinder requests.    
    for (i = 0; i < NUM_REQUESTS; i++)
    {
        /** Simulate random cylinder request by generating random number and 
        modding by max cylinder address. Push value to back of request queue.
        Request queue should be of length NUM_REQUESTS by end of loop.
        */
        request_queue.push_back(rand()%(DISK_SIZE-1));
    }

    /// Return the temporary request queue to main.
    return request_queue;
}

/**
This is the main function of the program. It will check for proper command line 
parameters, set the starting location of the disk head to that indicated by the 
user input. It will then call a function to generate 1,000 random cylinder 
requests and make a copy of this vector for each algorithm. It will then run 
each algorithm, passing each its own copy of the request vector, and output the 
total head movement needed for each algorithm to the terminal before returning 
successfully.  

@return 0 Indicates successful run of disk scheduling algorithm simulations.
*/
int main( int argc, char *argv[])
{
    /// Check for proper number of command line parameters entered.
    if (argc != 2) 
    {
        /// If not, print usage to user.
        cerr << "\nUsage: " << argv[0] << " <int>\n"  
            << "Where <int> is the starting location of the disk head.\n\n";
        
        /// Exit with error.
        exit(1);
    }

    /// Convert user-entered starting head position to int.
    int head = atoi(argv[1]);

    /// Make sure user did not set head passed total disk size.
    if(head >= DISK_SIZE)
    {
        /// If so, set head at top of disk. 
        head = DISK_SIZE - 1;
    }

    /// Make sure user did pass negative value for location of disk head.
    else if(head < 0)
    {
        /// If so, set head to bottom of disk
        head = 0;
    }

    /** Create multiple copies of a randomly generated request queue so that 
        they can be passed into algorithm simulation functions and altered and 
        destroyed as they are processed.
    */

    /// Populate the first request queue with random cylinder requests.
    vector<int> request_queue_fcfs = populate_request_queue();

    /// Make copies of that initial request queue to use for each algorithm.
    vector<int> request_queue_sstf (request_queue_fcfs); 
    vector<int> request_queue_scan (request_queue_fcfs); 
    vector<int> request_queue_c_scan (request_queue_fcfs); 
    vector<int> request_queue_look (request_queue_fcfs); 
    vector<int> request_queue_c_look (request_queue_fcfs); 

    /// Ensure all request queues have been properly initialized. 
    if ( request_queue_fcfs.size() != NUM_REQUESTS 
        || request_queue_sstf.size() != NUM_REQUESTS 
        || request_queue_scan.size() != NUM_REQUESTS 
        || request_queue_c_scan.size() != NUM_REQUESTS 
        || request_queue_look.size() != NUM_REQUESTS 
        || request_queue_c_look.size() != NUM_REQUESTS )
    {
        /// If not, inform the user.
        cout << "\nFailed to populate request queues. Exiting.\n\n";

        /// And exit with error.
        exit(1);
    }

    /// Print to user header info and simulation parameters. 
    cout << "\nDISK SCHEDULING ALGORITHMS:\n\n" <<
        "Initial position of disk head: " << head << "\n"
        "Num Cylinders on disk: " << DISK_SIZE << "\n" <<
        "Num Random Cylinder Requests: " << NUM_REQUESTS << "\n\n" <<
        "HEAD MOVEMENT REQUIRED PER ALGORITHM:\n\n";

    /** 
    Call each algorithm simulation on the same random requests and output
    total head movement for each.
    */ 
    cout << "FCFS: " << fcfs(request_queue_fcfs, head) << "\n\n";

    cout << "SSTF: " << sstf(request_queue_sstf, head) << "\n\n";
    
    cout << "SCAN: " << scan(request_queue_scan, head) << "\n\n";

    cout << "C-SCAN: " << c_scan(request_queue_c_scan, head) << "\n\n";

    cout << "LOOK: " <<  look(request_queue_look, head) << "\n\n";

    cout << "C-LOOK: " << c_look(request_queue_c_look, head) << "\n\n";

    /// Exit normally.
    return 0;
}

