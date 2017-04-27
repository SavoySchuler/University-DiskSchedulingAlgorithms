#include "disk.h"
#include "c-look.cpp"
#include "c-scan.cpp"
#include "fcfs.cpp"
#include "look.cpp"
#include "scan.cpp"
#include "sstf.cpp"

#include <iostream>
#include <vector>

/// Include libraries for use of rand. 
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<int> populate_request_queue()
{
/*    /// Initialize iterator variable.
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
----/
        request_queue.push_back(rand()%(DISK_SIZE-1));
    }

    /// Return the temporary request queue to main.
    return request_queue;*/

    vector<int> request_queue;

    int myints[] = {98, 183, 37, 122, 14, 124, 65, 67};
    request_queue.assign (myints,myints+8);

    return request_queue;
}

int main( int argc, char *argv[])
{
    if (argc != 2) 
    {
        cerr << "\nUsage: " << argv[0] << " <int>\n\n";
        exit(1);
    }

    int head = atoi(argv[1]);

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


    cout << "\nDISK SCHEDULING ALGORITHMS:\n\n" <<
        "Initial position of disk head: " << head << "\n"
        "Num Cylinders on disk: " << DISK_SIZE << "\n" <<
        "Num Random Cylinder Requests: " << NUM_REQUESTS << "\n\n" <<
        "HEAD MOVEMENT REQUIRED PER ALGORITHM:\n\n";


    cout << "FCFS: " << fcfs(request_queue_fcfs, head) << "\n\n";

    cout << "SSTF: " << sstf(request_queue_sstf, head) << "\n\n";
    
    cout << "SCAN: " << scan(request_queue_scan, head) << "\n\n";

    cout << "C-SCAN: " << c_scan(request_queue_c_scan, head) << "\n\n";

    cout << "LOOK: " <<  look(request_queue_look, head) << "\n\n";

    cout << "C-LOOK: " << c_look(request_queue_c_look, head) << "\n\n";

}

/*
    cout<<"\n\n";
    for (int i = 0; i < NUM_REQUESTS; i++)
    {
        cout << request_queue4[i] << "\n"; 
    }
    cout<<"\n\n"; 
*/