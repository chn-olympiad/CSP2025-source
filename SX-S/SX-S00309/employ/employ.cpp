#include<bits/stdc++.h>
#define ll long long
#define ls u<<1
#define rs u<<1|1
#define PII piar<int,int>
#define fi first 
#define se second 
#define _128 __int128
using namespace std;
inline int inint()
{
    int x = 0, f = 1;
    char c = getchar();
    while((c < '0') || (c > '9'))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while((c >= '0') && (c <= '9'))
    {
        x = x*10 + (c^'0');
        c = getchar();
    }
    return f*x;
}
inline ll inll()
{
    ll x = 0, f = 1;
    char c = getchar();
    while((c < '0') || (c > '9'))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while((c >= '0') && (c <= '9'))
    {
        x = x*10 + (c^'0');
        c = getchar();
    }
    return f*x;
}
inline _128 read()
{
    __int128 x = 0, f = 1;
    char c = getchar();
    while((c < '0') || (c > '9'))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while((c >= '0') && (c <= '9'))
    {
        x = x*10 + (c^'0');
        c = getchar();
    }
    return f*x;
}
void print(__int128 x)
{
    if(x < 0) 
    {
        putchar('-');
        x = -x;
    }
    if(x > 9) print(x/10);
    putchar(x%10+'0');
}
bool st[20];
int n, m;
const int mod = 998244353;
string s;
int cnt[20], pa[20];
int tem[20];
ll ans;
void dfs(int u)
{
    if(u > n)
    {
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            int w = tem[i];
            if(pa[w] <= sum) sum++;
            else if(s[i-1] == '0') sum++;
        }
        if((n-sum) >= m) ans = (ans+1)%mod;
        return;
    }
    for(int i = 1; i <= n; i ++)
    {
        if(!st[i])
        {
            st[i] = 1;
            tem[u] = i;
            dfs(u+1); 
            st[i] = 0;
        }
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    n = inint(), m =  inint();
    cin >> s;
    for(int i = 1; i <= n; i++) pa[i] = inint();
    dfs(1);
    //cout <<  ct << '\n';
    printf("%lld", ans);
    return 0;
}