#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e2+10;
int n,m;
typedef struct kc
{
    int fs,idx;
    bool operator<(const kc &other)const
    {
        return this->fs>other.fs;
    }
}kc;
kc ks[maxn];
int x,y;
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    int k=n*m;
    for(int i=1;i<=k;++i)
    {
        scanf("%lld",&ks[i].fs);
        ks[i].idx=i;
    }
    sort(ks+1,ks+1+k);
    for(int i=1;i<=k;++i)
    {
        if(ks[i].idx==1)
        {
            //printf("%lld\n",i);
            if(i%n)
            {
                x=i/n+1;
                if(x&1)
                {
                    y=i%n;
                }
                else
                {
                    y=n-(i%n)+1;
                }
            }
            else
            {
                //printf("%lld %lld\n",n,m);
                x=i/n;
                if(x&1)
                {
                    y=n;
                }
                else
                {
                    y=1;
                }
            }
            break;
        }
    }
    printf("%lld %lld\n",x,y);
    return 0;
}
