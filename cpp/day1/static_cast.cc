#include <iostream>

void test0(){
    // C语言强制转换
    int *p1 = (int *)malloc(sizeof(int));
    *p1=1;
    free(p1);

    int *p2 = static_cast<int*>(malloc(sizeof(int)));
    *p2=10;
    free(p2);
}
int main()
{
    test0();
    return 0;
}

