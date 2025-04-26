#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int counter = 0; int i = 0;
    char c;
    bool flag=false;
    int maxSize = 255;
    char sentence[maxSize];
    cout<<"Please input a sentence"<<endl;
    cin.getline(sentence, maxSize);

    while(c=sentence[i])
    {
        if(isalpha(c) || c=='-')
        {
            flag = true;
        }
        else
        {
            flag=false;
            counter++;
        };
        i++;
    }
    if(flag)//计算最后一个单词
    {
        counter++;
    }

    cout<<"counter:"<<counter;

    return 0;
}