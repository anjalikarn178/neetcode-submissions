class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(0,s,curr, ans);
        return ans;
    }

    void backtrack(int start, string s, vector<string>&curr, vector<vector<string>> &ans) {
        if(start == s.size()) {
            ans.push_back(curr);
            return;
        }

        for(int end = start; end<s.size(); end++) {
            if(isPalindrome(s,start,end)) {
                curr.push_back(s.substr(start, end-start+1));
                backtrack(end+1, s, curr, ans);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while(start<end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
