#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
char s[1000010];
int c[1000010];
long long dp[510][510],nxt[510][510];// lim/num
void pd(long long &x)
{
    if(x>=mod) x-=mod;
    return ;
}
long long ans[510];
long long C[510][510];
long long mul[510];
int main()
{
    // freopen("s.out","r",stdin);
    // freopen("a.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    sort(c+1,c+n+1);
    dp[n][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int lim=0;lim<=n;lim++)
            for(int num=0;num<i;num++)
            {
                if(s[n-i+1]=='1')
                {
                    int nownum=n-i+1;
                    for(int now=1;now<=n&&c[now]<=lim;now++) pd(nxt[c[now]-1][num+1]+=dp[lim][num]),nownum--;
                    (nxt[lim][num+1]+=dp[lim][num]*nownum)%=mod;
                    if(lim) pd(nxt[lim-1][num]+=dp[lim][num]);
                }
                else
                {
                    
                }
            }
        for(int lim=0;lim<=n;lim++)
            for(int num=0;num<=i;num++) dp[lim][num]=nxt[lim][num],nxt[lim][num]=0;
    }
    for(int lim=0;lim<=n;lim++) for(int num=0;num<=n;num++) pd(ans[num]+=dp[lim][num]);
    mul[0]=1;
    for(int i=1;i<=n;i++) mul[i]=mul[i-1]*i%mod;
    for(int i=0;i<=n;i++) C[i][0]=1,(ans[i]*=mul[n-i])%=mod;
    for(int i=0;i<=n;i++) printf("%lld ",ans[i]);
    printf("\n");
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) pd(C[i][j]=C[i-1][j-1]+C[i-1][j]);
    for(int i=n;i>=0;i--)
    {
        for(int j=i+1;j<=n;j++) (ans[i]-=ans[j]*C[j][i])%=mod;
        ans[i]+=mod,ans[i]%=mod;
    }
    long long answer=0;
    for(int i=m;i<=n;i++) pd(answer+=ans[i]);
    printf("%lld\n",answer);
    return 0;
}
/*
2 1
11
1 1
*/