#include<iostream>
#include"autotimer.h"

using namespace std;

int fib(int n)
{
    if(n<=1)
    {
        return 1;
    }

    return fib(n-1) + fib(n-2);
   
}

int fibonacci[50] = {0};

int fib2(int n)
{
    if(n<=1)
    {
        return 1;
    }

    if(n>=50)
    {
        return -1;
    }

    if(fibonacci[n])
    {
        return fibonacci[n];//如果等于零代表还没算过/
    }

    fibonacci[n] = fib(n-1)+fib(n-2);

    return fibonacci[n];

}

int main()
{
    {
        AutoTimer autoTimer("直接递归");
        int a =fib(20);
        cout<<"fib:"<<a<<endl;
    }

    {
        AutoTimer autoTimer("带缓存的的递归");
        int b =fib2(20);
        cout<<"fib2:"<<fib2(20)<<endl;
    }

    
   
}