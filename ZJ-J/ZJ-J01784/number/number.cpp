#include<bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=1e6+10;
int c[10];
string a;
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    /*char a[maxn];
    scanf("%s",a);*/
    cin>>a;
    for(int i=0;i<=a.size()-1;++i)
    {
        int b=a[i]-'0';
        if(b>=0&&b<=9)
        {
            ++c[b];
        }
    }
    for(int i=9;i>=0;--i)
    {
        for(int j=c[i];j>=1;--j)
        {
            printf("%lld",i);
        }
    }
    return 0;
}