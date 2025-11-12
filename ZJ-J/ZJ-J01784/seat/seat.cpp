#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int b,c;
    int bw=1;
    scanf("%lld%lld",&n,&m);
    scanf("%lld",&b);
    for(int i=1;i<=n*m-1;++i)
    {
        scanf("%lld",&c);
        if(c>b)
        {
            ++bw;
        }
    }
    int h,l;
    l=((bw-1)/n)+1;
    if(l%2==1)
    {
        h=(bw-1)%n+1;
    }
    else
    {
        h=n-(bw%n)+1;
    }
    printf("%lld %lld",l,h);
    return 0;
}