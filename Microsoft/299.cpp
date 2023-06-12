class Solution {
public:
    string getHint(string secret, string guess) {
        map<int,int> mp;
        int bulls = 0;
        for(int i=0;i<secret.size();i++){
            if(secret[i] == guess[i]){
                bulls++;
            }else{
                if(mp.find(secret[i]) == mp.end()){
                    mp[secret[i]] = 1;
                }else{
                    mp[secret[i]]++;
                }
            }
        }
        int cows = 0;
        for(int i=0;i<guess.size();i++){
            if(secret[i]!=guess[i]){
                if(mp.find(guess[i]) != mp.end()){
                    cows++;
                    mp[guess[i]]--;
                    if(mp[guess[i]] == 0){
                        mp.erase(guess[i]);
                    }
                }
            }
        }
        string b = to_string(bulls);
        string m = to_string(cows);
        string s = b+"A"+m+"B";
        return s;
    }
};