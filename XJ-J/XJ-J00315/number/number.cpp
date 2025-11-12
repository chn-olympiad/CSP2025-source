#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int a,int b)
{
    return a>b;
}
int n,a[92345678],j;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            a[j]=s[i];
            j++;
        }
    }
    sort(a,a+j,cmp);
    for(int i=0;i<j;i++)
    {
        cout<<a[i]-48;
    }
    return 0;
}
