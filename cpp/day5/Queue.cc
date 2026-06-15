#include <iostream>
using namespace std;
class Queue{
public:
    Queue(int size=10)
        :_front(0)
         ,_rear(0)
         ,_size(size)
         ,_data(new int[_size]()){
             cout<<"Queue(int)"<<endl;
         }
    bool empty() const{
        return _front==_rear;
    }
    bool full() const{
        return _front==(_rear+1)%_size;
    }
    void push(int num){
        if(!full()){
            _data[_rear++]=num;
            _rear%=_size;
        }else{
            cout<<"queue is full!"<<endl;
        }
    }
    void pop(){
        if(!empty()){
            _front++;
            _front%=_size;
        }else{
            cout<<"queue is empty!"<<endl;
        }
    }
    int front() const{
        return _data[_front];
    }
    int back() const{
        return _data[(_rear-1+_size)%_size];
    }
    ~Queue(){
        delete [] _data;
        _data=nullptr;
    }
private:
    int _front;
    int _rear;
    int _size;
    int * _data;
};
void test0(){
    Queue queue;
    cout<<"队列是否为空"<<queue.empty()<<endl;
    queue.push(1);
    cout<<"队列是否为空"<<queue.empty()<<endl;
    cout<<"队列是否为满"<<queue.full()<<endl;
    for(int i=2;i<12;i++){
        queue.push(i);
    }
    cout<<"队列是否为满"<<queue.full()<<endl;
    while(!queue.empty()){
        queue.pop();
    }
}
int main()
{
    test0();
    return 0;
}

