#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
const int N = 505,mod = 998244353;
int a[N],c[N],n,m,ans;
bool vis[N];
void dfs(int x,int y,int z)
{
    if(x == n+1){ans += z>=m;return ;}
    for(int i = 1;i <= n;i++)if(!vis[i])
    {
        int now = y<a[i]&&c[x];
        vis[i] = 1;
        dfs(x+1,y+!now,z+now);
        vis[i] = 0;
    }
}
char buf[1<<21],*p1,*p2;
inline int rd()
{
    char c;int f = 1;
    while(!isdigit(c = getchar()))if(c=='-')f = -1;
    int x = c^48;
    while(isdigit(c = getchar()))x = x*10+(c^48);
    return x*f;
}
inline char gc()
{char c;while((c = getchar()) <= ' ');return c;}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n = rd();m = rd();
    for(int i = 1;i <= n;i++)c[i] = gc()-'0';
    for(int i = 1;i <= n;i++)a[i] = rd();
    dfs(1,0,0);
    cout << ans << endl;
    return 0;
}
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #define ll long long
// #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
// using namespace std;
// const int N = 505,mod = 998244353;
// int a[N],s[N],c[N],n,m;
// ll C[N][N],iC[N][N],f[N][N],g[N][N],ans;
// // ll fac[N],C[N][N],f[N][N],g[N],ans;
// ll inv(ll x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}
// inline void up(int i,int j,int k,ll v)
// {
//     if(k > i)return ;
//     cout << "up " << i << ' ' << j << ' ' << k << ' ' << v << endl;
//     for(int p = 0;p <= c[j];p++)
//         (f[j][k+p] += v*C[i-k][p]%mod*C[n-i][c[j]-p]%mod*iC[n-k][c[j]]) %= mod;
// }
// char buf[1<<21],*p1,*p2;
// inline int rd()
// {
//     char c;int f = 1;
//     while(!isdigit(c = getchar()))if(c=='-')f = -1;
//     int x = c^48;
//     while(isdigit(c = getchar()))x = x*10+(c^48);
//     return x*f;
// }
// inline char gc()
// {char c;while((c = getchar()) <= ' ');return c;}
// int main()
// {
//     // freopen("employ2.in","r",stdin);
//     // freopen("employ.out","w",stdout);
//     n = rd();m = rd();
//     for(int i = 0;i <= n;i++)for(int j = C[i][0] = 1;j <= i;j++)
//         C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod,iC[i][j] = inv(C[i][j]);
//     for(int i = 1;i <= n;i++)a[i] = gc()-'0';
//     puts("111");
//     for(int i = 1;i <= n;i++)c[rd()]++;
//     for(int i = 0;i <= n;i++)s[i] = (i?s[i-1]:0)+c[i];
//     for(int i = 0;i <= n;i++)cout << s[i] << " \n"[i==n];
//     f[0][0] = 1;
//     for(int i = 1;i <= n;i++)
//     {
//         memcpy(g,f,sizeof f);memset(f,0,sizeof f);
//         for(int j = 0;j <= n;j++)for(int k = 0;k <= n;k++)
//         {
//             ll x = g[j][k];
//             if(!x)continue;
//             if(a[i])(f[j][k] += x*(s[n]-s[j]-(i-1-k))) %= mod;
//             else up(i,j+1,k,x*(s[n]-s[j]-(i-1-k))%mod);
//             up(i,j+1,k+1,x*(s[j]-k));
//         }
//         for(int j = 0;j <= n;j++)for(int k = 0;k <= n;k++)
//             if(f[j][k])cout << i << ' ' << j << ' ' << k << ' ' << f[j][k] << endl;
//     }
//     for(int j = 0;j <= n-m;j++)for(int k = 0;k <= n;k++)
//         (ans += f[j][k]) %= mod;
//     // for(int i = 0;i <= n;i++)
//     //     cout << g[i] << " \n"[i==n];
//     // for(int i = m;i <= n;i++)
//     //     (ans += (i-m&1?-1:1)*f[1][i]*fac[n-i]%mod*C[i][m]) %= mod;
//     cout << (ans+mod)%mod << endl;
//     return 0;
// }