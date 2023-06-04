class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i=0;i<tokens.size();i++){
            if((tokens[i]=="+" || tokens[i]=="-") || (tokens[i]=="*" || tokens[i]=="/")){
                
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                int x = stoi(a);
                int y = stoi(b);
                cout << x << " " << y << endl;
                if(tokens[i]=="+") st.push(to_string(x+y));
                else if(tokens[i]=="-") st.push(to_string(y-x));
                else if(tokens[i]=="*") st.push(to_string(x*y));
                else st.push(to_string(y/x));
                // cout << x << " " << y << " " << st.top() << endl;
            }else{
                st.push(tokens[i]);
            }
        }
        string res = st.top();
        int ans = stoi(res); 
        return ans;
    }
};