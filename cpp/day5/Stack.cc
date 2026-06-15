#include <iostream>
using namespace std;
class Stack{
public:
    Stack(int size=10)
    :_size(size)
    ,_top(-1)
    ,_data(new int[_size]())
    {
        cout<<"Stack 已经构建完成"<<endl;
    }
    bool empty() const;
    bool full() const;
    void push(int num);
    void pop();
    int top() const;
    ~Stack(){
        delete[] _data;
        _data=nullptr;
    }
private:
    int _size;
    int _top;
    int *_data;
};
bool Stack::empty() const{
    return _top==-1;
}
bool Stack::full() const{
    return _top==_size-1;
}
void Stack::push(int num){
    if(full()){
        cout<<"stack is full!"<<endl;
    }else{
        _top++;
        _data[_top]=num;
    }
}
void Stack::pop(){
    if(empty()){
        cout<<"stack is emty!"<<endl;
    }else{
        _top--;
    }
}
int Stack::top() const{
    return _data[_top];
}
void test0(){
    Stack stack;
    cout<<"此时栈是否为空?"<<stack.empty()<<endl;
    stack.push(1);
    cout<<"此时栈是否为空?"<<stack.empty()<<endl;
    for(int i=2;i<12;i++){
        stack.push(i);
    }
    cout<<"此时栈是否为满?"<<stack.full()<<endl;
    while(!stack.empty()){
        cout<<stack.top()<<endl;
        stack.pop();
    }
}
int main()
{
    test0();
    return 0;
}

