class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int count = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (s.find(num-1) == s.end()) {
                int start = num;
                int len = 1;

                while (s.find(start+1) != s.end()) {
                    len++;
                    start++;
                }

                count = max(count, len);
            }
        }

        return count;
    }
};
