#include <stdlib.h>
#include <vector>


#include <iostream>

using namespace std;

int fcfs(vector<int> request_queue, vector<int> batch_sizes, int head)
{
    int i = 0;
    int j = 0;
    int k = 0;

    int head_movement = 0;
    
    for (i = 0; i < batch_sizes.size(); i ++)
    {
        k = batch_sizes[i];

        for (; j < k; j++)
        {
            head_movement = head_movement + abs(head - request_queue[j]);
            head = request_queue[j];
        }
    }

    return head_movement;
}
