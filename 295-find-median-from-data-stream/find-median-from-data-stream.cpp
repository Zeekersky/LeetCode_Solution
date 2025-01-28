class MedianFinder {
public:
    priority_queue<int, vector<int>> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    int count;
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        count++;
        maxH.push(num);

        if (!minH.empty() && maxH.top() > minH.top()) {
            minH.push(maxH.top());
            maxH.pop();
        }

        // Balance sizes of heaps
        if (maxH.size() > (count + 1) / 2) {
            minH.push(maxH.top());
            maxH.pop();
        } else if (minH.size() > count / 2) {
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        if (count % 2) {
            return maxH.top();
        } else {
            return (maxH.top() + minH.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */