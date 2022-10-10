class MinStack {
    stack<long long> st;
    long long minn;

public:

    MinStack() {
        while(!st.empty()){
            st.pop();
            minn=INT_MAX;
        }
    }
    
    void push(int value) {
        long long val=value;
        if(st.empty()){
            minn=val;
            st.push(val);
        } 
        else{
            if(val<minn){
                st.push(2*val*1LL-minn);
                minn=val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty())return;
        long long ele=st.top();
        st.pop();

        if(ele<minn){
            minn=2*minn-ele;
        }

    }
    
    int top() {
        if(st.empty()) return -1;
        long long ele=st.top();
        if(ele<minn) return minn;
        return ele;
    }
    
    int getMin() {
        return minn;
    }
};
