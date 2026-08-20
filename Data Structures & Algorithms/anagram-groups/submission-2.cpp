class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto s: strs) {
            vector<int>cnt(26,0);
            for(auto ch : s)
                cnt[ch-'a']++;

            string key;
            for(auto ch:cnt)
                key+='#' + to_string(ch);
                mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto s:mp){
            ans.push_back(s.second);
        }

        return ans;
    }
};