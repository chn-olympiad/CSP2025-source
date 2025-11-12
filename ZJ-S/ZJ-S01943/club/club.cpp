#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e5+10;
typedef struct node
{
    int a1,a2,a3;
}node;
bool cmp1(node a,node b)
{
    return a.a1>b.a1;
}
bool cmp2(node a,node b)
{
    return a.a2>b.a2;
}
bool cmp3(node a,node b)
{
    return a.a3>b.a3;
}
node a[maxn],b[maxn];
int maxx;
int ans=0;

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%lld",&t);
    while(t--)
    {
        int n,fa=1,fb=1;
        scanf("%lld",&n);
        int cnt1=0,cnt2=0,cnt3=0;
        int ren=n/2;
        for(int i=1; i<=n; ++i)
        {
            scanf("%lld%lld%lld",&a[i].a1,&a[i].a2,&a[i].a3);
            if(a[i].a2!=0 || a[i].a3!=0) fa=0;
            if(a[i].a3!=0) fb=0;
        }
        ans=0;
        if(fa)
        {
            for(int i=1; i<=n; ++i)
            {
                ans+=a[i].a1;
            }
            printf("%lld\n",ans);
            continue;
        }
        else if(n==2)
        {
            int a12=a[1].a1+a[2].a2;
            int a13=a[1].a1+a[2].a3;
            int a21=a[1].a2+a[2].a1;
            int maxx1=max({a12,a13,a21});
            int a23=a[1].a2+a[2].a3;
            int a31=a[1].a3+a[2].a1;
            int a32=a[1].a3+a[2].a2;
            int maxx2=max({a23,a31,a32});
            printf("%lld\n",max(maxx1,maxx2));
        }
        else
        {
            ans=0;
        int maxx1=0,maxx2=0,maxx3=0;

        sort(a+1,a+1+n,cmp1);
        for(int i=1; i<=n/2; ++i)
        {
            maxx1+=a[i].a1;
        }
       
        for(int i=n/2+1; i<=n; ++i)
        {
            maxx1+=max(a[i].a2,a[i].a3);
        }

        sort(a+1,a+1+n,cmp2);
        for(int i=1; i<=n/2; ++i)
        {
            maxx2+=a[i].a2;
        }
        
        for(int i=n/2+1; i<=n; ++i)
        {
            maxx2+=max(a[i].a1,a[i].a3);
        }

        sort(a+1,a+1+n,cmp3);
        for(int i=1; i<=n/2-1; ++i)
        {
            maxx3+=a[i].a3;
        }
        
        for(int i=n/2+1; i<=n; ++i)
        {
            maxx3+=max(a[i].a2,a[i].a1);
        }

        ans=max({maxx1,maxx2,maxx3});
        printf("%lld\n",ans);
        }
        
        
        
    }


    return 0;
}