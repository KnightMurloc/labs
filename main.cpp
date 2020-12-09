#include "Queue.h"

using namespace std;

int main() {
    Queue<int> queue;
    {
        queue.push(1);
        queue.push(5);
        queue.push(10);
    }

    {
        int test = 0;
        int a = queue.pop();
        int b = queue.pop();
        int c = queue.pop();

//        ASSERT_EQ(a,1);
//        ASSERT_EQ(b,5);
//        ASSERT_EQ(c,1);
    }
    return 0;
}
