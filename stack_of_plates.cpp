#include <list>
#include <stack>
#include <stdexcept>

const int STACK_SIZE = 3;

std::list< std::stack<int> > Linked_list;

void push(int value) {
    if (Linked_list.empty() || Linked_list.back().size() >= STACK_SIZE) {
        std::stack<int> stack;
        stack.push(value);
        Linked_list.push_back(stack);
    } else {
        Linked_list.back().push(value);
    }
}

int pop() {
    if (Linked_list.empty()) {
        throw std::out_of_range("No elements to pop");
    }

    std::stack<int>& lastStack = Linked_list.back();

    int value = lastStack.top();
    lastStack.pop();

    removeStackIfEmpty();

    return value;
}

void removeStackIfEmpty() {
    if (!Linked_list.empty() && Linked_list.back().empty()) {
        Linked_list.pop_back();
    }
}

