#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt[10];
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(char c:s)
    {
        if(isdigit(c))
        {
            ++cnt[c-'0'];
        }
    }
    bool flag=false;
    for(int i=9;i>=1;--i)
    {
        while(cnt[i])
        {
            putchar(i+'0');
            --cnt[i];
            flag=true;
        }
    }
    if(flag)
    {
        while(cnt[0])
        {
            putchar('0');
            --cnt[0];
        }
    }
    else
    {
        putchar('0');
    }
    putchar('\n');
}