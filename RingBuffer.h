#ifndef RING_BUFFER_H
#define RING_BUFFER_H

template <typename T, int N>
class RingBuffer {
    T items[N];
    int head;

public:
    RingBuffer() {
        head = 0;
    }

    T& operator[](int index) {
        return items[(head + index) % N];
    }

    void shift(int count) {
        head = (head + count) % N;
    }

    void copyBackward(int source, int dest, int length) {
        for (auto i = length - 1; i >= 0; i--)
            this[dest + i] = this[source + i];
    }
};

#endif
