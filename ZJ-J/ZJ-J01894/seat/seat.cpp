#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e4+10;
int a[maxn];
int r;
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1; i<=n*m; ++i)
    {
        scanf("%lld",&a[i]);
    }
    r=a[1];
    sort(a+1,a+1+n*m);
    int col=1,row=1,f=1;
    for(int i=n*m; i>=1; --i)
    {
        if(a[i]==r)
        {
            printf("%lld %lld\n",col,row);
            return 0;
        }
        if(f)
        {
            ++row;
            if(row>n) 
            {
                row=n;
                ++col;
                f=0;
            }
        }
        else if(!f)
        {
            --row;
            if(row<1)
            {
                row=1;
                ++col;
                f=1;
            }
        }
    }



    return 0;
}