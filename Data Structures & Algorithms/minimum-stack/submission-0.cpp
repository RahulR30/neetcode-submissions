class MinStack {
private:
    stack<int> mainstack;
    stack<int> minstack;

public:

    MinStack() {
    }
    
    void push(int val) {
        mainstack.push(val);
        if (minstack.empty() || val <= minstack.top()) {
            minstack.push(val);
        } else {
            minstack.push(minstack.top());
        }
    }
    
    void pop() {
        mainstack.pop();
        minstack.pop();
    }
    
    int top() {
        return mainstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
