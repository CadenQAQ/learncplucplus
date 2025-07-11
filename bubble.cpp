#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    cout<<"please input numbers"<<endl;

    vector<int> numbers;
    int num = 0;

    while(cin>>num)
    {
        if(num == -1)
        break;
        numbers.push_back(num);
    }

    int k = numbers.size();

    while(k>1)
    {
        int m = 0;
        for(int i = 0; i<k-1;i++)
        {
            if(numbers[i]>numbers[i+1])
            {
                swap(numbers[i],numbers[i+1]);
                m=i+1;
            }
            
        }

        k=m;
    }

    for(int num:numbers)
    {
        cout<<num<<endl;
    }

    return 0;

}