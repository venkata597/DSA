#include <iostream>

template <typename t> struct Node{
    Node<t>* prev;
    t data;
    Node<t>* next;
};

template <typename t> class Doubly_LinkedList{
private:
    Node<t>* head = nullptr;
    Node<t>* temp = nullptr;
public:
    void insert_at_beginning(t dat){
        Node<t>* newn = new Node<t>;
        newn->data = dat;
        newn->prev = newn->next = nullptr;
        if(head == nullptr){
            head = newn;
        }
        else{
            head->prev = newn;
            newn->next = head;
            head = newn;
        }
    }

    void delete_from_beginning(){
        if(head == nullptr){
            std::cout << "Linked List Empty" << std::endl;
        }
        else{
            temp = head;
            head = head->next;
            temp->next = nullptr;
            std::cout << "Deleted element is: " << temp->data << std::endl;
            head->prev = nullptr;
            delete temp;
        }
    }

    void display(){
        if(head==nullptr) std::cout << "Linked List Empty" << std::endl;
        else{
            temp = head;
            while(temp!=nullptr){
                std::cout << temp->data << " -> ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }

    ~Doubly_LinkedList(){
        delete head;
    }
};

int main(){
    Doubly_LinkedList<int> list;
    list.insert_at_beginning(55);
    list.insert_at_beginning(66);
    list.insert_at_beginning(77);
    list.display();
    list.delete_from_beginning();
    list.display();
}