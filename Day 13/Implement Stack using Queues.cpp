MyStack() {
         queue<int> q1;
    queue<int> q2;
    }
    
    void push(int x) {
       q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> t=q1;
        q1=q2;
        q2=t;
    }
    
    int pop() {
        if(q1.empty() ){
            return -1;
        }
        int d=q1.front();
        q1.pop();
        return d;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }
        return false;
    }