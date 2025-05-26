#include <iostream>

template <typename t> struct Node{
    t data;
    Node<t>* next;
};

template <typename t> class Queue{
private:
    Node<t>* front = nullptr;
    Node<t>* rear = nullptr;
    Node<t>* temp;
public:
    void enqueue(t val){
        Node<t>* newn = new Node<t>;
        newn->data = val;
        newn->next = nullptr;
        if(rear==nullptr){
            rear = newn;
            front = newn;
        }
        else{
            rear->next = newn;
            rear = newn;
        }
    }

    t dequeue(){
        if(rear==nullptr){
            std::cout << "Stack is empty!!" << std::endl;
        }
        else{
            temp = front;
            front = front->next;
            t dequeued = temp->data;
            temp->next = nullptr;
            delete temp;
            return dequeued;
        }
    }

    void peek(){
        if(rear==nullptr){
            std::cout << "Stack is empty!!" << std::endl;
        }
        else{
            std::cout << "Front element in the queue is:" << front->data << std::endl;
        }
    }

    void display(){
        if(rear==nullptr){
            std::cout << "Stack is empty!!" << std::endl;
        }
        else{
            temp = front;
            while(temp!=nullptr){
                std::cout << temp->data << std::endl;
                temp = temp->next;
            }
        }
    }

    ~Queue(){delete front;delete rear;delete temp;}
};

int main(){
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    queue.peek();
    queue.display();
}