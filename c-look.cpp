#include <vector>
using namespace std;

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
