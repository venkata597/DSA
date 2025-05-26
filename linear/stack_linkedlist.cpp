#include <iostream>

template <typename t> struct Node{
    t data;
    Node<t>* next;
};

template <typename t> class Stack{
private:
    Node<t>* tos = nullptr;
    Node<t>* temp = nullptr;
public:
    void push(t val){
        Node<t>*  newn = new Node<t>;
        newn->data = val;
        newn->next = nullptr;
        if(tos==nullptr){
            tos = newn;
        }
        else{
            newn->next = tos;
            tos = newn;
        }
    }

    t pop(){
        if(tos==nullptr){
            std::cout << "Stack is empty!! Push Elements first" << std::endl;
        }
        else{
            temp = tos;
            tos = tos->next;
            temp->next = nullptr;
            t popped = temp->data;
            delete temp;
            return popped;
        }
    }

    void peek(){
        if(tos==nullptr){
            std::cout << "Stack is empty!! Push Elements first" << std::endl;
        }
        else{
            std::cout << "Top element of the stack is :" << tos->data << std::endl;
        }
    }

    void display(){
        if(tos==nullptr){
            std::cout << "Stack is empty!! Push Elements first" << std::endl;
        }
        else{
            temp = tos;
            while(temp!=nullptr){
                std::cout << temp->data << std::endl;
                temp = temp->next;
            }
        }
    }

    ~Stack() {delete tos;delete temp;}
};

int main(){
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    std::cout << "Popped element is: " << stack.pop() << std::endl;
    stack.peek();
    stack.display();
}