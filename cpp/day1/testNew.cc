#include <iostream>
int main()
{
    int *p=new int[10]();//开辟数组的时候要记得采用[]
    for(int idx=0;idx!=10;idx++){
        p[idx]=idx*idx;
    }
    for(int idx=0;idx!=10;idx++){
        std::cout<<p[idx]<<std::endl;;
    }
    delete []p;//回收的时候，也采用[]
    return 0;
}

