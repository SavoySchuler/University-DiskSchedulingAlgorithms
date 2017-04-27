#include <vector>
using namespace std;

int look(vector<int> request_queue, int head)
{
    int i = 0;

    int head_movement = 0;

    bool direction = 0;
    
    bool bounce = false;  

    int largest = 0, smallest;   

    int Disk_Size = 200;

    for (i = 0; i < request_queue.size(); i++)
    {
        if (request_queue[i] < head)
        {
            bounce = true;
            smallest = request_queue[i];
        }

        else if (request_queue[i] > largest)    
        {
            largest = request_queue[i];
        }
    }

    if (bounce = true)
    {
        head_movement = head - smallest + 2*(largest - head);
    }
    
    else
    {
        head_movement = largest - head;
    }
    
    return head_movement;
}
