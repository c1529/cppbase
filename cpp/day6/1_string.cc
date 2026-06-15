#include<iostream>
using std::cout;
using std::endl;
using std::string;
void test0(){
    string s1;
    string s2(3,'a');
    string s3("hello");
    cout<<"s1:"<<s1<<endl;
    cout<<"s2:"<<s2<<endl;
    cout<<"s3:"<<s3<<endl;
    cout<<"s2.size()="<<s2.size()<<endl;
    cout<<"s3.length()="<<s3.length()<<endl;
    //遍历
    for(size_t idx=0;idx<s3.size();idx++){
        cout<<s3[idx]<<" ";
    }
    cout<<endl;
    for(auto &ch:s3){
        cout<<ch<<" ";
    }
    cout<<endl;
}
void test1(){
    string s1="hello";
    string s2("world");
    auto it = s2.begin();
    cout<<"*it = "<<*it<<endl;
    s2.append(s1);
    s2.append("bbb");
    cout<<"s2 = "<<s2<<endl;
    string s4 = s2.substr(2,3);
    cout<<"s4 = "<<s4<<endl;
    size_t pos = s2.find("llo");
    cout<<"pos = "<<pos<<endl;
    //insert
    s4.insert(1,5,'c');
    cout<<"s4 = "<<s4<<endl;
    s4.erase(1,5);
    cout<<"s4 = "<<s4<<endl;
}
int main(){
    //test0();
    test1();
    return 0;
}
