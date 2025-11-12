#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[1000005]={},j=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[j]=s[i]-'0';
            j++;
        }
    }
    j--;
    sort(a+1,a+j+1);
    for(int i=j;i>=1;i--)cout<<a[i];
}
