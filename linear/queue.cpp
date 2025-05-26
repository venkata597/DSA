#include <iostream>

template <typename t,int size> class Queue{
private:
    t queue[size];
    int front = -1,rear = -1;
public:
    void enqueue(t data){
        if(rear==size-1){
            std::cout << "Queue is full!!" << std::endl;
        }
        else{
            queue[++rear] = data;
        }

        if(front==-1){
            front = 0;
        }
    }

    t dequeue(){
        if(front==-1){
            std::cout << "Stack is empty!!" << std::endl;
        }
        else{
            t dequeued = queue[front];
            queue[front++] = '\0';
            return dequeued;
        }
    }

    void peek(){
        if(front==-1){
            std::cout << "Stack is empty!!" << std::endl;
        }
        else{
            std::cout << "Front of the queue: " << queue[front] << std::endl;
        }
    }

    void display(){
        if(front==-1){
            std::cout << "Stack is empty!!" << std::endl;
        }
        else{
            for(int i = front;i<=rear;i++){
                std::cout << queue[i] << " ";
            }
        }
    }
};


int main(){
    Queue<int,10> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    queue.peek();
    queue.display();
}