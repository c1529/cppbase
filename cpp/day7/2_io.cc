#include <iostream>
#include <vector>
#include <unistd.h>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
void test0(){
    for (int i=0;i<100;i++){
        cout<<'a';
    }
    sleep(3);
}
int main()
{
    test0();
    return 0;
}

