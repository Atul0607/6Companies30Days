class Solution {
public:
    int mod = 1e9+7;
    typedef long long int ll; 
    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<pair<ll,ll>> q;
        ll day = 1;
        q.push({1,1}); //people,day
        day++;
        while(day<=n){
            ll sz = q.size();
            ll aware = 0;
            while(sz>0){
                auto p = q.front();
                q.pop();
                if(p.second+forget>day){
                    q.push(p);
                    if(p.second+delay<=day) aware = (aware+p.first)%mod;
                }
                sz--;
            }
            if(aware!=0) q.push({aware,day});
            day++;
        }
        ll ans=0;
        while(!q.empty()){
            auto p = q.front();
            ans = (ans+p.first)%mod;
            q.pop();
        }
        return ans;
    }
};