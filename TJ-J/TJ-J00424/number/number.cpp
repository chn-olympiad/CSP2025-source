#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int h[10001],t,n=0;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            continue;
        }
        else
        {
            h[n]+=s[i];
            n++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i+1]>s[i])
        {
            t=s[i];
            s[i]=s[i+1];
            s[i+1]=t;
        }

    }
    cout<<h;
    return 0;
}
