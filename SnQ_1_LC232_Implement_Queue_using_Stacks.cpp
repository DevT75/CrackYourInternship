class MyQueue {
public:
    stack<int> temp;
    stack<int> q;
    MyQueue() {

    }
    
    void push(int x){
        if(!q.empty()){
            while(!q.empty()){
                temp.push(q.top());
                q.pop();
            }
        }
        temp.push(x);
    }
    
    int pop() {
        if(temp.empty()){
            int tp = q.top();
            q.pop();
            return tp;
        }
        else{
            while(!temp.empty()){
                q.push(temp.top());
                temp.pop();
            }
            int tp = q.top();
            q.pop();
            return tp;
        }
    }
    
    int peek(){
        if(temp.empty()){
            int tp = q.top();
            return tp;
        }
        else{
            while(!temp.empty()){
                q.push(temp.top());
                temp.pop();
            }
            int tp = q.top();
            return tp;
        }
    }
    
    bool empty() {
        return q.empty() && temp.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */