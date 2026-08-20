class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left =0;
        int right = heights.size()-1;
        int water =0;
        int curr =0;

        while(left<right) {
            int temp = min(heights[left], heights[right]);
            curr = temp*(abs(right-left));
            water = max(curr, water);
            if(heights[left]<heights[right]) left++;
            else right--;
        }
        return water;
    }
};
