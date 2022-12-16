class MyQueue {
private:
    stack<int> stk1, stk2;
    
    void stk1tostk2() {
        while(!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
    }
    void stk2tostk1() {
        while(!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        stk1tostk2();
        int ele = stk2.top();
        stk2.pop();
        stk2tostk1();
        
        return ele;
    }
    
    int peek() {
        stk1tostk2();
        int ele = stk2.top();
        stk2tostk1();

        return ele;
    }
    
    bool empty() {
        if(stk1.empty() && stk2.empty()) return true;
        else return false;
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