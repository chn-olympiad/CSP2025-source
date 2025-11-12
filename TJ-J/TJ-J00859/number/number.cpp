#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],ans=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        int cnt=0;
        if(s[i]>=49 && s[i]<=57)
        {
            a[cnt]=s[i];
            cnt++;
        }
    }
    for(int i=0;i<s.length();i++)
    {
        int n=10,bh,q=1;
        for(int j=0;i<s.length();j++)
        {
            if(a[j]<n)
            {
                n=a[j];
                bh=j;
            }
        }
        for(int j=1;j<=i;j++)
        {
            q*=10;
        }
        ans+=(n*q);
        a[bh]=10;
    }
    cout<<ans;
    return 0;
}
