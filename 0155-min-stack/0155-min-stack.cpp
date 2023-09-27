class MinStack {
public:
    stack<int> st;
    stack<int> ms;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(ms.empty()){
            ms.push(val);
        }else{
            if(val<=ms.top()){
                ms.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top()==ms.top()){
            st.pop();
            ms.pop();
        }else{
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()){
            return INT_MIN;
        }
        return st.top();
    }
    
    int getMin() {
        return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */