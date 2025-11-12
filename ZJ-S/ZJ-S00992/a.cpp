#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
char s[1000010];
int c[1000010];
int p[1000010];
int now[1000010];
int ans;
long long mul[1000010];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    mul[0]=1;
    for(int i=1;i<=n;i++) mul[i]=mul[i-1]*i%mod;
    if(n==m)
    {
        bool f=1;
        for(int i=1;i<=n;i++) if(s[i]=='0') f=0;
        for(int i=1;i<=n;i++) if(c[i]==0) f=0;
        
        if(f) printf("%lld\n",mul[n]);
        else printf("0\n");
        return 0;
    }
    if(m==1)
    {
        int num1=0;
        long long ans=1;
        for(int i=1;i<=n;i++) if(s[i]=='1')
        {
            int num=0;
            for(int j=1;j<=n;j++) num+=(c[j]<i);
            if(num<=num1) ans=0;
            (ans*=(num-num1))%=mod,num1++;
        }
        printf("%lld\n",(mul[n]-ans*mul[n-num1]%mod+mod)%mod);
        return 0;
    }
    for(int i=1;i<=n;i++) p[i]=i;
    do
    {
        for(int i=1;i<=n;i++) now[i]=c[p[i]];
        int num=0,num0=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0') num0++;
            else if(now[i]<=num0) num0++;
            else num++;
        }
        ans+=(num>=m);
    }while(next_permutation(p+1,p+n+1));
    printf("%d\n",ans);
    return 0;
}
/*
2 1
11
1 1
*/