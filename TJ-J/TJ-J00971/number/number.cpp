#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);// 
    freopen("number.out","w",stdout);
    int once=0;
    char a[1000005];
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if('0'<=s[i]&&s[i]<='9') a[++once]=s[i];
    }
    sort(a+1,a+1+once,cmp);
    for(int i=1;i<=once;i++)
    {
        cout<<a[i];
    }
}
   
