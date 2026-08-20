class Solution {
public:
    bool checkPalindrome(string s){
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }
    vector<vector<string>> ans;
    void backtrack(string& s, int idx, int l, vector<string>& cur){
        if(idx == s.size()){
            ans.push_back(cur);
            return;
        }
        if(idx+l>s.size()) return;
        string a = s.substr(idx,l);
        if(checkPalindrome(a)){
            cur.push_back(a);
            backtrack(s,idx+l,1,cur);
            cur.pop_back();
        }
        backtrack(s,idx,l+1,cur);
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        backtrack(s,0,1,cur);
        return ans;
    }
};
