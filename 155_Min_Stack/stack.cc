/**********************************************************************

 Design a stack that supports push, pop, top, and retrieving the minimum 
 element in constant time.

 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 getMin() -- Retrieve the minimum element in the stack.

**********************************************************************/

class MinStack {
public:
    void push(int x) {
        int min = x;
        
        if (!minEle.empty() && minEle.back() < x)
            min = minEle.back();
            
        stack.push_back(x);
        minEle.push_back(min);
    }

    void pop() {
        stack.pop_back();
        minEle.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return minEle.back();
    }
    
private:
    vector<int> stack;
    vector<int> minEle;
};
