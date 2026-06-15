#include <iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
void test0(){
    vector<int> number(10,1);
    for(auto & num:number){
        cout<<num<<" ";
    }
    cout<<endl;
    cout<<"number size = "<<number.size()<<endl;
    int arr[5]={5,4,3,2,1};//数组天然就是一个迭代器
    vector<int> number1(arr,arr+5);
    for(auto & num:number1){
        cout<<num<<" ";
    }
    cout<<endl;
    cout<<"number1 size = "<<number1.size()<<endl;
}
void display(const vector<int> &number){
    for (auto num:number){
        cout<<num<<" ";
    }
    cout<<endl;
}
void test1(){
    vector<int> numbers={1,2,3,4,5};
    numbers.push_back(6);
    numbers.push_back(7);
    cout<<"number(7):"<<endl;;
    display(numbers);
    cout<<"sizeof(numbers)"<<sizeof(numbers)<<endl;
    numbers.push_back(8);
    cout<<"number(8):"<<endl;;
    display(numbers);
    cout<<"sizeof(numbers)"<<sizeof(numbers)<<endl;
}
int main()
{
    //test0();
    test1();
    return 0;
}

