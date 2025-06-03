#include <iostream>
#include <memory>
template <typename t> class Node{
	public:
		t data;
        std::shared_ptr<Node<t>> left;
        std::shared_ptr<Node<t>> right;
		Node(t val):
			data(val),left(nullptr),right(nullptr){}
};

template <typename t> class BST{
private:
    std::shared_ptr<Node<t>> root;
    
    std::shared_ptr<Node<t>> insert_recursive(int val,std::shared_ptr<Node<t>> ptr){
        if(ptr==nullptr){
            return std::make_shared<Node<t>>(val);
        }
        else if(val<ptr->data){
            ptr->left = insert_recursive(val, ptr->left);
        }
        else if(val>ptr->data){
            ptr->right = insert_recursive(val, ptr->right);
        }
        return ptr;
    }

    void inorder_recursive(std::shared_ptr<Node<t>> ptr){
        if(ptr==nullptr){
            return;
        }
        inorder_recursive(ptr->left);
        std::cout << ptr->data;
        inorder_recursive(ptr->right);
    }

    void search_recursive(t val,std::shared_ptr<Node<t>> ptr){
        if(ptr==nullptr){
            std::cout << "Element not found in tree" << std::endl;
        }
        else if(ptr->data==val){
            std::cout << "Element found in tree" << std::endl;
        }
        else if(val<ptr->data){
            search_recursive(val, ptr->left);
        }
        else if(val>ptr->data){
            search_recursive(val,ptr->right);
        }
    }

    std::shared_ptr<Node<t>> findMin(std::shared_ptr<Node<t>> rt){
        while(rt && rt->left!=nullptr){
            rt = rt->left;
        }
        return rt;
    }

    std::shared_ptr<Node<t>> delete_recur(t val,std::shared_ptr<Node<t>> ptr){
        if(ptr==nullptr){
            return nullptr;
        }
        if(val<ptr->data){
            ptr->left = delete_recur(val,ptr->left);
        }
        else if(val>ptr->data){
            ptr->right = delete_recur(val,ptr->right);
        }
        else{
            if(ptr->left==nullptr && ptr->right==nullptr){
                return nullptr;
            }
            else if(ptr->left==nullptr){
                std::shared_ptr<Node<t>> temp = ptr->right;
                return temp;
            }
            else if(ptr->right==nullptr){
                std::shared_ptr<Node<t>> temp = ptr->left;
                return temp;
            }
            else{
                std::shared_ptr<Node<t>> successor = findMin(ptr->right);
                ptr->data = successor->data;
                ptr->right = delete_recur(successor->data,ptr->right);
            }
        }
        return ptr;
    }


public:
    void insert(t val){
        this->root = insert_recursive(val,root);
    }
    
    void inorder(){inorder_recursive(this->root);std::cout << std::endl;}

    void search(int value) {search_recursive(value,this->root);}

    void deletion(int value){this->root = delete_recur(value,root);}

};


int main(){
    BST<int> bst;
    int ch,val;
    while(1){
        std::cout << "1.INSERT\n2.INORDER\n3.SEARCH\n4.DELETE\n5.EXIT" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> ch;
        switch(ch){
            case 1:
                std::cout << "Enter element to enter: ";
                std::cin >> val;
                bst.insert(val);
                break;
            case 2:
                bst.inorder();
                break;
            case 3:
                std::cout << "Enter element to search: ";
                std::cin >> val;
                bst.search(val);
                break;
            case 4:
                std::cout << "Enter element to delete: ";
                std::cin >> val;
                bst.deletion(val);
                break;    
            case 5:
                exit(0);
                break;
            default:
                std::cout << "Invalid Choice" << std::endl;
        }
    }
}
