#include <list>
#include <stack>
#include <stdexcept>

const int STACK_SIZE = 3;

std::list< std::stack<int> > stacks;
#include <list>
#include <stack>
#include <stdexcept>

const int STACK_SIZE = 3;

std::list< std::stack<int> > stacks;

void push(int value) {
    // If there is no stack or the last stack is full
    if (stacks.empty() || stacks.back().size() >= STACK_SIZE) {
        // Create a new stack and push the value into it
        std::stack<int> stack;
        stack.push(value);
        // Add the new stack to the list of stacks
        stacks.push_back(stack);
    } else {
        // Add the value to the last stack
        stacks.back().push(value);
    }
}

int pop() {
    // Check if there are no stacks
    if (stacks.empty()) {
        throw std::out_of_range("No elements to pop");
    }

    // Find the last stack
    std::stack<int>& lastStack = stacks.back();

    // Pop the value from the last stack
    int value = lastStack.top();
    lastStack.pop();

    // If the last stack is empty, remove it from the list of stacks
    removeStackIfEmpty();

    return value;
}

void removeStackIfEmpty() {
    if (!stacks.empty() && stacks.back().empty()) {
        stacks.pop_back();
    }
}

void push(int value) {
    // If there is no stack or the last stack is full
    if (stacks.empty() || stacks.back().size() >= STACK_SIZE) {
        // Create a new stack and push the value into it
        std::stack<int> stack;
        stack.push(value);
        // Add the new stack to the list of stacks
        stacks.push_back(stack);
    } else {
        // Add the value to the last stack
        stacks.back().push(value);
    }
}

int pop() {
    // Check if there are no stacks
    if (stacks.empty()) {
        throw std::out_of_range("No elements to pop");
    }

    // Find the last stack
    std::stack<int>& lastStack = stacks.back();

    // Pop the value from the last stack
    int value = lastStack.top();
    lastStack.pop();

    // If the last stack is empty, remove it from the list of stacks
    removeStackIfEmpty();

    return value;
}

void removeStackIfEmpty() {
    if (stacks.back().empty()) {
        stacks.pop_back();
    }
}
