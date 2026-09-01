class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(auto num: stones) {
            maxHeap.push(num);
        }
        
        while(maxHeap.size()>1) {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            
            if(abs(y-x) !=0) {
                maxHeap.push(abs(y-x));
            }
        }

        return (maxHeap.size() == 1) ? maxHeap.top() : 0;
    }
};
