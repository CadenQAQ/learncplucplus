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
    int count[26] = {0};
    cout<<"Please input a sentence"<<endl;
    cin.getline(sentence, maxSize);


    int idx = 0;//字母索引

    while(c=sentence[i])
    {
        
        if(isalpha(c))
        {
            idx = c-'a';
            count[idx]++;
        }

        i++;
    }

    for(int j=0;j<26;j++)
    {
        cout<<char('a'+j)<<":"<<count[j]<<endl;
    }

 
    return 0;
}