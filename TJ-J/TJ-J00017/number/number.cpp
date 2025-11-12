#include<bits/stdc++.h>
using namespace std;
int a[15];
string x;
string ans;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>x;
    int s=x.length();
    for(int i=0;i<=s;i++)
    {
        int c=(int)(x[i])-48;
        if(c>=0 && c<=9)
            a[c]++;
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=a[i];j++)
            ans+=(char)(48+i);
    }
    cout<<ans;
    return 0;
}
