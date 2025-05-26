#include <iostream>

template <typename t,int size>class array{
private:
    t* arr = new t[size];
    int index = -1;
public:
    void insert(t ele){
        arr[++index] = ele;
    }
    t deletion(){
        t deleted = arr[index];
        arr[index] = '\0';
        index--;
        return deleted;
    }

    void insert_at_pos(t ele,int pos){
        for(int i = index;i>=pos;i--){
            arr[i+1] = arr[i];
        }
        index++;
        arr[pos] = ele;
    }

    void display(){
        for(int i = 0;i<=index;i++){
            std::cout << arr[i] << std::endl;
        }
    }

    void update(int nindex,t ele){
        if(index>ele){
            std::cout << "NO ELEMENTS EXIST AT " << index << " INDEX" << std::endl;
        }
        else{
            arr[nindex] = ele;
        }
    }

    ~array(){
        delete[] arr;
    }
};


int main(){
    array<int,10> arr;
    arr.insert(5);
    arr.insert(6);
    arr.insert(7);
    arr.insert(8);
    arr.update(0,3);
    arr.insert_at_pos(4,2);
    arr.display();
    auto del = arr.deletion();
    std::cout << "Deleted element is: " << del << std::endl;
}