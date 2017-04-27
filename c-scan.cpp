#include <stdlib.h>
#include <vector>

using namespace std;



#include <iostream>

int c_scan(vector<int> request_queue, int head)
{
    int i = 0;

    int head_movement = 0;

    bool direction = 0;
    
    bool bounce = false;  

    int largest = 0, largest_under_head = 0;   

    int Disk_Size = 200;

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
        head_movement = (Disk_Size - 1 - head) + largest_under_head;
    }
    
    else
    {
        head_movement = largest - head;
    }
    
    return head_movement;
}
