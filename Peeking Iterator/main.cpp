#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        is_peek = peek_num = 0;
        
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (is_peek) return peek_num;
        peek_num = Iterator::next();
        is_peek = 1;
        return peek_num;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (is_peek) {
            is_peek = 0;
            return peek_num;
        }
        return Iterator::next();
    }

    bool hasNext() const {
        return (is_peek || Iterator::hasNext());
    }
private:
    int is_peek;
    int peek_num;
};

int main()
{
    return 0;
}
