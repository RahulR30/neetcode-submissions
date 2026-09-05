class MinStack {
private:
    stack<int> normal_stack;
    stack<int> min_stack;
public:
    MinStack() {
    }
    
    void push(int val) {
        normal_stack.push(val);
        if (min_stack.empty() || val <= min_stack.top()){
            min_stack.push(val);
        } 
    }
    
    void pop() {
        if (normal_stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        normal_stack.pop();
    }
    
    int top() {
        if(!normal_stack.empty()){
            return normal_stack.top();
        }
        return 0;
    }
    
    int getMin() {
        if(!min_stack.empty()){
            return min_stack.top();
        }
        return 0;
    }
};
