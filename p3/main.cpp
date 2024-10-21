#include <iostream>
#include <thread>
#include <stdint.h>
#include <mutex>

std::mutex mtx;// mutex for critical section

void incrementTask()
{
    while (1)
    {
        /* Delay for 3 seconds. */
        sleep(3);

        /* Wait for the mutex to become available. */
        mtx.lock();

        gSharedVariable++;
        std::cout << "Increment Task: shared var is " << gSharedVariable << std::endl;

        /* Release the mutex for other task to use. */
        mtx.unlock();
    }
}

void decrementTask()
{
    while (1)
    {
        /* Delay for 7 seconds. */
        sleep(7);
        /* Wait for the mutex to become available. */
        mtx.lock();

        gSharedVariable--;
        std::cout << "Decrement Task: shared var is "<< gSharedVariable << std::endl;

        /* Release the mutex. */
        mtx.unlock();
    }
}

int main(void)
{
    /* Create the increment and decrement tasks using the default task
    * attributes. Do not pass in any parameters to the tasks. */
    std::thread incrementTaskObj (incrementTask);
    std::thread decrementTaskObj (decrementTask);
    
    /* Allow the tasks to run. */
    incrementTaskObj.join();
    decrementTaskObj.join();
    
    return 0;
}


