#include<bits/stdc++.h>
using namespace std;
const long long md=998244353;
int n,m;
char s[505];
int c[505];

long long ans;
int vis[505];
void dfs(int t,int num)
{
    if(num>n-m)
    {
        return;
    }
    if(t>n)
    {
        ans=(ans+1)%md;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            if((s[t]=='0')||(c[i]<=num))
            {
                dfs(t+1,num+1);
            }
            else
            {
                dfs(t+1,num);
            }
            vis[i]=false;
        }
    }
}
int main ()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d\n%s",&n,&m,s+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0')
            {
                printf("0\n");
                return 0;
            }
        }
        ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=ans*i%md;
        }
        printf("%lld\n",ans);
        return 0;
    }
    int num=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1')
        {
            num++;
        }
    }
    if(num==n)
    {
        ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=ans*i%md;
        }
        printf("%lld\n",ans);
        return 0;
    }
    dfs(1,0);
    printf("%lld\n",ans);
}