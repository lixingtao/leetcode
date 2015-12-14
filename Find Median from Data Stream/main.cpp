#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

class MedianFinder {
public:

    MedianFinder() {
        small_heap.push_back(0);
        big_heap.push_back(0);
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        if (!big_heap[0]) {
            ++big_heap[0];
            big_heap.push_back(num);
            return;
        }

        if (num <= big_heap[1]) {
            if (big_heap[0] <= small_heap[0]) {
                ++big_heap[0];
                big_heap.push_back(num);
                push_up(big_heap, big_heap[0], big);
            }
            else {
                ++small_heap[0];
                small_heap.push_back(big_heap[1]);
                push_up(small_heap, small_heap[0], small);
                big_heap[1] = num;
                push_down(big_heap, 1, big);
            }
        }
        else {
            if (small_heap[0] < big_heap[0]) {
                ++small_heap[0];
                small_heap.push_back(num);
                push_up(small_heap, small_heap[0], small);
            }
            else {
                if (num > small_heap[1]) swap(small_heap[1], num);
                push_down(small_heap, 1, small);
                ++big_heap[0];
                big_heap.push_back(num);
                push_up(big_heap, big_heap[0], big);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        //printf("find_median: big_heap num %d, small_heap num %d\n", big_heap[0], small_heap[0]);
        //printf("big_heap: "); print_vector(big_heap);
        //printf("small_heap: "); print_vector(small_heap);
        if (big_heap[0] > small_heap[0]) return big_heap[1];
        return (double)(big_heap[1] + small_heap[1]) / 2;
    }

private:
    enum heap_type {small = -1, big = 1};
    vector<int> small_heap;
    vector<int> big_heap;

    void push_down(vector<int> &heap, int cur, heap_type type) {
        int l = cur * 2;
        int r = l + 1;
        int p = cur;
        if (l <= heap[0] && heap[p]*type < heap[l]*type) p = l;
        if (r <= heap[0] && heap[p]*type < heap[r]*type) p = r;

        if (p == cur) return;
        swap(heap[cur], heap[p]);
        
        push_down(heap, p, type);
    }
    
    void push_up(vector<int> &heap, int cur, heap_type type) {
        if (cur == 1) return ;
        int fa = cur >> 1;
        if (heap[fa]*type >= heap[cur]*type)
            return ;
        swap(heap[fa], heap[cur]);
        push_up(heap, fa, type);
    }
    void print_vector(vector<int> vet) {
        for (int i = 0; i < vet.size(); i++) {
            cout<<vet[i]<<"\t";
        }
        cout<<endl;
    }
};

int main()
{
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    mf.addNum(2);
    mf.addNum(3);
    mf.addNum(4);
    mf.addNum(5);
    double ret = mf.findMedian();
    cout<<ret<<endl;

    return 0;
}
