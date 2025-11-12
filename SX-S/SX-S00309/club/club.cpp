#include<bits/stdc++.h>
#define reg register
#define ll long long
#define ls u<<1
#define rs u<<1|1
#define PII pair<int,int>
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
struct stu
{
    int id;
    int val1, val2, val3;
}a[100010];
int n;
priority_queue<PII> q1, q2, q3;
void solve()
{
    ll ans = 0;
    while(q1.size() || q2.size() || q3.size())
    {
        if(q1.size()) q1.pop();
        if(q2.size()) q2.pop();
        if(q3.size()) q3.pop();
    }
    // sz1 = sz2 = sz3 = 0;
    for(int i = 1; i <= n; i++)
    {
        if((a[i].val1 >= a[i].val2) && (a[i].val1 >= a[i].val3)) q1.push({max(a[i].val2, a[i].val3)-a[i].val1, a[i].id}), ans += a[i].val1;//cout << max(a[i].val2, a[i].val3)-a[i].val1 << '\n';
        else if((a[i].val2 >= a[i].val1) && (a[i].val2 >= a[i].val3)) q2.push({max(a[i].val1, a[i].val3)-a[i].val2, a[i].id}), ans += a[i].val2; ///cout << max(a[i].val1, a[i].val3)-a[i].val2 << '\n';
        else if((a[i].val3 >= a[i].val2) && (a[i].val3 >= a[i].val1)) q3.push({max(a[i].val1, a[i].val2)-a[i].val3, a[i].id}), ans += a[i].val3; //cout << max(a[i].val1, a[i].val2)-a[i].val3 << '\n';
    }
    int mid = n/2;
    // cout << sz1 << '\n';
    // cout << ans << '\n';
    // cout << '\n';
    while(q1.size() > mid)
    {
        
        int z = q1.top().fi;//cout << z << '\n';
        int u = q1.top().se;
        q1.pop();
        ans += z;
    }
    // cout << '\n';
    while(q2.size() > mid)
    {
        // cout << sz2 << '\n';
        int z = q2.top().fi;//cout << z << '\n';
        int u = q2.top().se;
        q2.pop();
        ans += z;
    }
    while(q3.size() > mid)
    {
        int z = q3.top().fi;
        int u = q3.top().se;
        q3.pop();
        ans += z;
    }
    printf("%lld\n", ans);
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int ttt;
    ttt = inint();
    while(ttt--)
    {
        n = inint();
        for(reg int i = 1; i <= n; i++) 
        {
            a[i].val1 = inint(), a[i].val2 = inint(), a[i].val3 = inint();
            a[i].id = i;
        }
        // cout << 1 << '\n';
        solve();
    }
    return 0;
}