class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        vector<int> ans;

        for(auto num: nums) {
            mp[num]++;
        }
        
         priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

         for(auto p: mp) {
            int fir = p.first;
            int sec = p.second;
            pq.push({sec, fir});

            if(pq.size()>k) pq.pop();
         }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

         return ans;
    }
};
