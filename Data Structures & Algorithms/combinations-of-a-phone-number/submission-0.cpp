class Solution {
public:

    void backtrack(int start, string& digits, string &curr, vector<string> &ans, unordered_map<int, string>& mp) {
        if(curr.size()==digits.size()) {
            ans.push_back(curr);
            return;
        }

        
        string temp = mp[digits[start]-'0'];
        for( auto ch : temp) {
            curr.push_back(ch);
            backtrack(start+1, digits, curr, ans, mp);
            curr.pop_back();
        }
        
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty()) {
            return {};
        }
        
        int n = digits.size();
        unordered_map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string curr = "";
        vector<string> ans;
        backtrack(0, digits, curr, ans, mp);
        return ans;
    }
};
