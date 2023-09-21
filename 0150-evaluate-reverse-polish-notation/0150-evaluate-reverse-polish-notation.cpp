class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token: tokens){
            int a;
            int b;
            int res;
            if(token=="+"){
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                res=a+b;
                st.push(res);
            }else if(token=="-"){
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                res=a-b;
                st.push(res);
            }else if(token=="*"){
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                res=a*b;
                st.push(res);
            }else if(token=="/"){
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                res=a/b;
                st.push(res);
            }else{
                int n=stoi(token);
                st.push(n);
            }
        }
        int ans=st.top();
        return ans;
    }
};