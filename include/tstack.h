// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    T data[SIZE];
    int topIndex;
    
public:
    TStack() : topIndex(-1) {}
    
    void push(const T& value) {
        if (topIndex >= SIZE - 1) throw "Stack overflow";
        data[++topIndex] = value;
    }
    
    T pop() {
        if (isEmpty()) throw "Stack underflow";
        return data[topIndex--];
    }
    
    T top() const {
        if (isEmpty()) throw "Stack is empty";
        return data[topIndex];
    }
    
    bool isEmpty() const {
        return topIndex == -1;
    }
};

#endif  // INCLUDE_TSTACK_H_
