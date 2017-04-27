#include <stdlib.h>
#include <vector>

using namespace std;

int fcfs(vector<int> request_queue, int head)
{
    int i = 0;

    int head_movement = 0;
    
    for (i = 0; i < request_queue.size(); i ++)
    {
        head_movement = head_movement + abs(head - request_queue[i]);
        head = request_queue[i];
    }

    return head_movement;
}
