// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(const std::string& inf) {
 TStack<char, 100> stack;
    std::stringstream postfix;
    bool prevWasDigit = false;
    for (size_t i = 0; i < inf.size(); ++i) {
        char c = inf[i];
        if (isspace(c)) {
            continue;
        }
        if (isdigit(c)) {
            if (prevWasDigit) {
                postfix << c; 
            } else {
                if (i != 0) postfix << ' ';
                postfix << c;
            }
            prevWasDigit = true;
        } 
        else {
            prevWasDigit = false;
            if (c == '(') {
                stack.push(c);
            } 
            else if (c == ')') {
                while (!stack.isEmpty() && stack.top() != '(') {
                    postfix << ' ' << stack.pop();
                }
                stack.pop();
            } 
            else {
                while (!stack.isEmpty() && getPriority(stack.top()) >= getPriority(c)) {
                    postfix << ' ' << stack.pop();
                }
                stack.push(c);
            }
        }
    }
    while (!stack.isEmpty()) {
        postfix << ' ' << stack.pop();
    }
    return postfix.str();
}
  return std::string("");
}
int eval(const std::string& pref) {
   TStack<int, 100> stack;
    std::istringstream iss(post);
    std::string token;
    
    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.push(std::stoi(token));
        } 
        else {
            int b = stack.pop();
            int a = stack.pop();
            switch(token[0]) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }
    return stack.pop();
  return 0;
}
