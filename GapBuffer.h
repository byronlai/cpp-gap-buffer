#ifndef GAP_BUFFER_H
#define GAP_BUFFER_H

#include "RingBuffer.h"

template <typename T, int N>
class GapBuffer {
    RingBuffer<T, N> items;
    int gapStart;
    int gapLength;

public:
    GapBuffer() {
        gapStart = 0;
        gapLength = N;
    }

    T& operator[](int index) {
        if (index < gapStart)
            return items[index];
        return items[index + gapLength];
    }

    bool isFull() {
        return gapLength == 0;
    }

    void shift(int count) {
        if (count < gapStart) {
            items.shift(count);
            gapStart -= count;
            auto source = gapStart + gapLength;
            items.copyBackward(source, N - source, source + count);
            gapLength += count;
        } else {
            gapLength += count - gapStart;
            gapStart = 0;
        }
    }

    void seek(int index) {
        if (index < gapStart)
            items.copyBackward(index, index + gapLength, gapStart - index);
        else if (index > gapStart)
            items.copyBackward(gapStart + gapLength, gapStart, index - gapStart);
        gapStart = index;
    }

    void insert(T item) {
        items[gapStart] = item;
        gapStart++;
        gapLength--;
    }

    void remove() {
        gapLength++;
    }
};

#endif
