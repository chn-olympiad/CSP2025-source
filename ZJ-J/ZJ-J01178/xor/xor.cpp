#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e5+10;
int n,k;
int a[maxn];
int ans;
int res[maxn];
int ret[maxn];
//void solve1()
//{
//    int res=-1;
//    for(int i=1;i<=n;++i)
//    {
//        if(a[i]==k)
//        {
//            ++ans;
//            res=-1;
//            continue;
//        }
//        if(i==1||res==-1)
//        {
//            res=a[i];
//            continue;
//        }
//        if((a[i]^a[i-1])==k)
//        {
//            ++ans;
//            res=-1;
//            continue;
//        }
//        if((res!=-1)&&((res^a[i])==k))
//        {
//            ++ans;
//            res=-1;
//        }
//    }
//    printf("%lld\n",ans);
//}
void solve()
{
    for(int i=2;i<=n;++i)
    {
        if(ret[i]==-1)
        {
            continue;
        }
        if(i==2)
        {
            if(ret[1]==-1)
            {
                continue;
            }
            if(res[i]==k)
            {
                ++ans;
                ret[i]=-1;
            }
            continue;
        }
        for(int j=1;j<=i;++j)
        {
            if(ret[i-j]==-1)
            {
                break;
            }
           // printf("%lld %lld %lld %lld\n",i,j,res[i],res[i-(j-1)]);
            if((res[i]^res[i-(j+1)])==k)
            {
                ++ans;
                ret[i]=-1;
                break;
            }
        }
    }
    printf("%lld\n",ans);
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",a+i);
        if(i==1)
        {
            res[i]=a[i];
            if(a[i]==k)
            {
                ++ans;
                ret[i]=-1;
                //printf("!");
            }
            continue;
        }
        if(a[i]==k)
        {
            ++ans;
            res[i]=(res[i-1]^a[i]);
            ret[i]=-1;
        }
        else
        {
            res[i]=(res[i-1]^a[i]);
        }
    }
    solve();
    return 0;
}
