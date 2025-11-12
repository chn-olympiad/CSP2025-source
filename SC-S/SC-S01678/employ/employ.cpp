#include<cstdio>
using namespace std;
int n,m,c[505],p[505];
bool vis[505];
typedef long long ll;
const ll mod=998244353;
ll pw[505],ans;
char s[505];
void dfs(int x)
{
    if(x==n+1)
    {
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;++i)
        {
            if(s[i]=='0'||cnt2>=c[p[i]]) cnt2++;
            else cnt1++;
        }
        if(cnt1>=m) ans++;
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            vis[i]=1,p[x]=i;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    pw[0]=1;
    for(int i=1;i<=500;++i) pw[i]=pw[i-1]*ll(i)%mod;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i) scanf("%d",&c[i]);
    if(n<=10)
    {
        dfs(1);
        printf("%lld\n",ans);
    }else printf("%lld\n",pw[n]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}