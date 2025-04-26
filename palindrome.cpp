#include<iostream>

using namespace std;

bool IsPalindrome(int n)
{
    if(n<0){return false;}

    int div = 1;
    while(n/div>=10)
    {
        div *=10;
    }

    while(n!=0)
    {
        int left = n/div;
        int right = n%10;
        if(left!=right)
        {
            return false;
        }

        n = (n%div)/10;//去掉两边的数
        div /=100;
    }
    return true;
}

int main()
{
    int data[5] = {100,121,2332,45554,213};
    for(auto v:data)
    {
        if(IsPalindrome(v))
        {
            cout<<"True"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }
    };
}