#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 5e3+10;
constexpr int maxm = 1.5e6+10;
constexpr int mod = 998244353;

int n;
int wi[maxn];
int fac[maxn];
int infac[maxn];
int _C[maxn][maxn];
int cnt[maxn];// jishu quchong

int C(int n,int m)//C^n_m
{
    return fac[m]*infac[n]%mod*infac[m-n]%mod;
}

void init()
{
    fac[0]=fac[1]=1;
    for(int i=2;i<=5e3;++i)
    {
        fac[i]=fac[i-1]*i%mod;
    }

    infac[0]=infac[1]=1;
    for(int i=2;i<=5e3;++i)
    {
        infac[i]=infac[mod%i]*(mod-mod/i)%mod;
    }

    for(int i=2;i<=5e3;++i)
    {
        infac[i]=infac[i]*infac[i-1]%mod;
    }

    for(int i=1;i<=5e3;++i)
    {
        for(int j=1;j<=i;++j)
        {
            _C[i][j]=_C[i][j-1]+C(j,i);
            if(_C[i][j]>=mod)
            {
                _C[i][j]-=mod;
            }
        }
        // printf("%lld %lld\n",i,_C[i][i]);
    }
}
void sub1()
{
    if(wi[1]+wi[2]>wi[3])
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
}

int ans3;

void dfs(int dep,int ma,int tal)
{
    if(dep>n)
    {
        if(tal>ma*2)
        {
            ++ans3;
        }
        return;
    }
    dfs(dep+1,max(ma,wi[dep]),tal+wi[dep]);
    dfs(dep+1,ma,tal);
}

void sub2()
{
    int ans=0;
    ans=_C[n][n]-_C[n][2];
    printf("%lld",ans%mod);
}

void sub3()
{
    dfs(1,0,0);
    printf("%lld",ans3);
}

void dfs2(int tal,int idn,int num)
{
    int id=lower_bound(wi+1,wi+1+n,tal)-wi;

    --id;
    if(id>idn && num>=3 && id<=n)
    {
        int k=id-cnt[id]-num-1;
        if(k>=0)
        {
            ++cnt[id];
            ans3+=_C[k][k]+1;
        }
    }
    for(int i=max(id,idn)+1;i<=n;++i)
    {
        dfs2(tal+wi[max(id,idn+1)],i,num+1);
    }
}

signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    scanf("%lld",&n);

    init();

    bool flag2=1;
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",wi+i);
        if(wi[i]>1)
        {
            flag2=0;
        }
    }
    sort(wi+1,wi+1+n);

    if(n<=3)
    {
        sub1();
        return 0;
    }
    if(flag2)
    {
        sub2();
        return 0;
    }
    if(n<=2)
    {
        sub3();
        return 0;
    }


    for(int i=1;i<n;++i)
    {
        dfs2(wi[i],i,1);
    }

    /**
    int ans=0;
    for(int i=1;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int id=lower_bound(wi+1,wi+1+n,wi[i]+wi[j])-wi;
            --id;
            if(id<=j)
            {
                continue;
            }

            int k=id-cnt[id]-3;
            //++cnt[i][id];
            ++cnt[id];
            ans+=_C[k][k]+1;
            if(ans>=mod)
            {
                ans-=mod;
            }
            // printf("%lld %lld %lld\n",i,j,id);
        }
    }
    */
    printf("%lld\n",ans3);


    return 0;
}
