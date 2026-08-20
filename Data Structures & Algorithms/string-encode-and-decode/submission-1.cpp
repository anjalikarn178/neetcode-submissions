class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto ch: strs) {
            res+=to_string(ch.size());
            res+='#';
            res+=ch;
        }
         return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i=0;
        while(i<s.size()){
            int j = i;

            while(s[j]!='#') j++;

            int len = stoi(s.substr(i, j-i));
            j++;

            ans.push_back(s.substr(j,len));

            i = j+len;
        }

        return ans;
    }
};
