#include <iostream>

template<typename t,int size>class array{
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

    ~array(){
        delete arr;
    }
};


int main(){
    array<int,10> arr;
    arr.insert(5);
    arr.insert(6);
    auto del = arr.deletion();
    std::cout << "Deleted element is: " << del << std::endl;
}