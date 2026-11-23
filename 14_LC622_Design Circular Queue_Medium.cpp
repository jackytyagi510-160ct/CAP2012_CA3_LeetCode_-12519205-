#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> buf;
    int capacity;
    int frontIdx;
    int rearIdx;
    int count;

public:
    MyCircularQueue(int k)
        : buf(k, 0), capacity(k), frontIdx(0), rearIdx(-1), count(0) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        rearIdx = (rearIdx + 1) % capacity;
        buf[rearIdx] = value;
        ++count;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        frontIdx = (frontIdx + 1) % capacity;
        --count;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return buf[frontIdx];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return buf[rearIdx];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};