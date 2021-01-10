// Given a string s, find the length of the longest substring without repeating characters.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int res = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            vector<bool> vis(256);
            for(int j=i; j<n; j++){
                if(vis[s[j]] == true)
                    break;
                else{
                    res = max(res, j-i+1);
                    vis[s[j]] = true;
                }
            }
            vis[s[i]] = false;
        }
        return res;
    }
};

