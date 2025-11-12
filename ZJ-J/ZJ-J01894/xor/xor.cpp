#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e6+10;
constexpr int maxm=1e4+10;
int a[maxn];
int fa=1,fb=1,fc=1;
int maxx=-1;
int moc[300][300];
int mocMAT[300];
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%lld%lld",&n,&k);
    for(int i=1; i<=n; ++i)
    {
        scanf("%lld",&a[i]);
        maxx=max(maxx,a[i]);
        if(a[i]!=0 && a[i]!=1) fb=0;
        if(a[i]>255) fc=0;
        if(a[i]!=1) fa=0;
    }


    if(k==0 && fa)
    {
        printf("0\n");
        return 0;
    }
    if(k<=1 && fb)
    {
        int cnt0=0,cnt1=0;
        for(int i=1; i<=n; ++i)
        {
            if(a[i]==0) ++cnt0;
            if(a[i]==1) ++cnt1;
        }
        if(k==1) printf("%lld\n",cnt1);
        else if(k==0) printf("%lld\n",cnt0);
        return 0;
    }

    int mm=maxx,bitnum=0;
    while(mm)
    {
        bitnum+=1;
        mm/=2;
    }
    int kk=pow(2,bitnum);
    if(kk<=k)
    {
        printf("0\n");
        return 0;
    }
    
    int cnt=0;
    for(int i=1; i<=n; ++i)
    {
        if(a[i]==k) ++cnt;
    }
    printf("%lld\n",cnt);

    
    
    

    return 0;
}