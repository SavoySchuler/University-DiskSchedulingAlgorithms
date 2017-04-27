#include "disk.h"

#include <stdlib.h>
#include <vector>


int c_scan(vector<int> request_queue, int head)
{
    int i = 0;

    int head_movement = 0;

    bool direction = 0;
    
    bool bounce = false;  

    int largest = 0, largest_under_head = 0;   

    for (i = 0; i < request_queue.size(); i++)
    {
        if (request_queue[i] < head && request_queue[i] > largest_under_head)
        {
            bounce = true;
            largest_under_head = request_queue[i];
        }

        else if (request_queue[i] > largest)    
        {
            largest = request_queue[i];
        }
    }

    if (bounce = true)
    {
        head_movement = (DISK_SIZE - 1 - head) + largest_under_head;
    }
    
    else
    {
        head_movement = largest - head;
    }
    
    return head_movement;
}

