#include "disk.h"
#include <vector>
#include <stdlib.h>

using namespace std;

int sstf(vector<int> request_queue, vector<int> batch_sizes, int head)
{
    int i = 0, j = 0, k = 0, l = 0;
    
    int temp_distance = 0;

    int closest_distance = DISK_SIZE + 1;
    int closest_index = -1;

    int head_movement = 0;
    


    for (k = 0; k < batch_sizes.size(); k++)
    {
    
        l = batch_sizes[k];

        for (; i < l ; i ++)
        {   
            closest_distance = DISK_SIZE + 1;
            closest_index = -1;

            for (j = 0; j < request_queue.size(); j++)
            {
                temp_distance = abs(head - request_queue[j]);
                if (temp_distance < closest_distance)
                {
                    closest_distance = temp_distance;
                    closest_index = j;
                }
            }

            head_movement += closest_distance;
            head = request_queue[closest_index];
            request_queue.erase(request_queue.begin()+closest_index);
        }
    
    }

    return head_movement;
}
