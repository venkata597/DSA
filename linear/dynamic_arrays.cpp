#include <iostream>

template <typename t>class dynamic_array{
private:
    int size = 4;
    t* darr = new t[size];
    int index = -1;
    void resize(){
        int nsize = size * 2;
        t* narr = new t[nsize];
        for(int i = 0;i<size;i++){
            narr[i] = darr[i];
        }
        size = nsize;
        darr = narr;
    }

    bool check_if_avail(){
        if(index==size){
            return false;
        }
        else{
            return true;
        }
    }   

public:
    void push_back(t ele){
        index++;
        if(check_if_avail()){
            darr[index] = ele;
        }
        else{
            resize();
            darr[index] = ele;
        }
    }

    void deletion(){
        t deleted = darr[index];
        darr[index] = '\0';
        index--;
    }

    void insert_at(t ele,int pos){
        if(check_if_avail()){
            for(int i = index;i>=pos;i++){
                darr[i+1] = darr[i];
            }
            index++;
            darr[pos] = ele;
        }
        else{
            resize();
            for(int i = index;i>=pos;i++){
                darr[i+1] = darr[i];
            }
            index++;
            darr[pos] = ele;
        }
    }

    void display(){
        for(int i = 0;i<=index;i++){
            std::cout << darr[i] << " ";
        }
    }

    ~dynamic_array(){
        delete[] darr;
    }
};


int main(){
    dynamic_array<int> intvect;
    intvect.push_back(10);
    intvect.push_back(11);
    intvect.push_back(12);
    intvect.push_back(13);
    intvect.push_back(14);
    intvect.push_back(15);
    intvect.display();
}