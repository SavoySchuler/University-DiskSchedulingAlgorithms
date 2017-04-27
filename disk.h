/// Define disk size as 5000 cyclinders.
#define DISK_SIZE 200 //5000

/// Define simulation's number of requests.
#define NUM_REQUESTS 8 //1000

/** Array for simulating request queue. Same request queue will be passed to all
algortihms to allow for accurate comparison.*/
int request_queue[NUM_REQUESTS];

/// Starting location of the disk head.
int head_start;

