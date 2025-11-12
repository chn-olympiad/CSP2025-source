#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
char a[1000000];
int b[1000000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<=1000000;i++)
    {
            if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='4'||s[i]=='3'||s[i]=='6'||s[i]=='5'||s[i]=='7'||s[i]=='8'||s[i]=='9')
            {
                a[i]=s[i];
                cout<<a[i];
            }
    }


    return 0;
}
