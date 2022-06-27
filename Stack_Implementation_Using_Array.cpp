// Stack class.
class Stack {
    private:
    int* s;
    int size;
    int top_index;
public:
    
    Stack(int capacity) {
        // Write your code here.
        top_index=-1;
        size=capacity;
        s = new int[size];
    }

    void push(int num) {
        // Write your code here.
        if(isFull())
            return;
        top_index++;
        s[top_index]=num;
    }

    int pop() {
        // Write your code here.
        if(isEmpty())
            return -1;
        int temp=s[top_index];
        top_index--;
        return temp;
    }
    
    int top() {
        // Write your code here.
        if(isEmpty())
            return -1;
        return s[top_index];
    }
    
    int isEmpty() {
        // Write your code here.
        if(top_index==(-1))
            return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(top_index==(size-1))
            return 1;
        return 0;
    }
    
};
