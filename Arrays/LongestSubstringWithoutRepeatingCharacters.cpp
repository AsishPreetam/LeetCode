class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        int max_len = 0;
        int i=0, j=0;
        while(j<n && i<n){
            if(freq.find(s[j]) == freq.end()){
                freq[s[j]]++;
                max_len = max(max_len, j-i+1);
                j++;
            }
            else if(freq.find(s[j]) != freq.end()){
                freq.clear();
                i++;
                j=i;
            }  
        }
        return max_len;
    }
};
