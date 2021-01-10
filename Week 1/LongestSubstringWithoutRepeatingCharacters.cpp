// Given a string s, find the length of the longest substring without repeating characters.


// O(n^2)
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


// O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int res = 0;
        int n = s.size();
        vector<int> lastIndex(256, -1);
        for(int i=0, j=0; j<n; j++){
            i = max(i, lastIndex[s[j]] + 1);
            res = max(res, j-i+1);
            lastIndex[s[j]] = j;
        }
        return res;
    }
};


