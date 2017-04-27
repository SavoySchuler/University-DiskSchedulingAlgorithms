/// Include library for absolute value.
#include <stdlib.h>

/// Include library for vector use. 
#include <vector>

/// Using standard namespace.
using namespace std;

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
