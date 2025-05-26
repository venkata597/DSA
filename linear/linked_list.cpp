#include <iostream>

template <typename t> struct Node{
    t data;
    Node* next;  
};

template<typename tp> class LinkedList{
private:
    Node<tp>* head = new Node<tp>;
    Node<tp>* temp;
public:
    void insert_at_beginning(tp ele){
        Node<tp>* newn = new Node<tp>;
        newn->data = ele;
        newn->next = nullptr;
        if(head==nullptr){
            head = newn;
        }
        else{
            newn->next = head;
            head = newn;
        }
    }

    void delete_from_beginning(){
        temp = head;
        head = head->next;
        temp->next = nullptr;
        std::cout << "Deleted: " << temp->data << std::endl;
        delete temp;
    }

    void display(){
        temp = head;
        while(temp!=nullptr){
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
    }

    ~LinkedList(){
        delete head;
    }

};


int main(){
    LinkedList<int> linkedlist;
    linkedlist.insert_at_beginning(4);
    linkedlist.insert_at_beginning(8);
    linkedlist.insert_at_beginning(12);
    linkedlist.display();
    linkedlist.delete_from_beginning();
    linkedlist.display();
}