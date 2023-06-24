class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> mp;
        int count=0;
        int i=0,j=0;
        int end = s.size()-1;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()<3) j++;
            else if(mp.size() == 3){
                while(mp.size() == 3){
                    count+=1+end-j;
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return count;
    }
};