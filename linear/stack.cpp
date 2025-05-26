#include <iostream>

template <typename t,int size> class Stack{
private:
    t stack[size];
    int tos = -1;
public:
    void push(t dat){
        if(tos==size-1){
            std::cout << "Stack is full!! OVERFLOW!!" << std::endl;
        }
        else{
            stack[++tos] = dat;
        }
    }

    t pop(){
        if(tos==-1){
            std::cout << "Stack is empty!! UNDERFLOW!!" << std::endl;
        }
        else{
            t popped = stack[tos];
            stack[tos--] = '\0';
            return popped;
        }
    }

    void peek(){
        if(tos==-1){
            std::cout << "Stack is empty!! No elements to peek" << std::endl;
        }
        else{
            std::cout << "Top element of the stack is: " << stack[tos] << std::endl;
        }
    }

    void display(){
        if(tos==-1){
            std::cout << "Stack is empty!" << std::endl;
        }
        else{
            for(int i = tos;i>=0;i--){
                std::cout << stack[i] << std::endl;
            }
        }
    }

};

int main(){
    Stack<int,10> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    std::cout << "Popped element is: " << stack.pop() << std::endl;
    stack.peek();
    stack.display();
}