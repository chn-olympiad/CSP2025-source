#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#define ll long long
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
const int N = 1e5+5;
int cb[N],cc[N],n;
struct node{int a,b,c;}a[N];
ll f[N],g[N],ans,sum;
multiset<int> q1,q2;
priority_queue<int> q;
inline void sol()
{
    if(q1.size() > n/2)
    {
        int x = *q1.begin();
        sum -= x;q2.insert(x);q1.erase(q1.begin());
    }
    if(q2.size() > n/2)
    {
        int x = *q2.rbegin();
        sum += x;q1.insert(x);q2.erase(prev(q2.end()));
    }
}
inline void add(int x)
{
    if(q1.size()&&x >= *q1.begin())q1.insert(x),sum += x;
    else q2.insert(x);
    sol();
}
inline void del(int x)
{
    auto it = q1.find(x);
    if(it != q1.end())q1.erase(it),sum -= x;
    else q2.erase(q2.find(x));
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
     freopen("club.in","r",stdin);
     freopen("club.out","w",stdout);
    for(int t = rd();t--;)
    {
        n = rd();sum = 0;g[n+1] = cc[n+1] = 0;
        for(int i = 1;i <= n;i++)
            a[i] = {rd(),rd(),rd()},a[i].b -= a[i].a,a[i].c -= a[i].a;
        sort(a+1,a+n+1,[](node x,node y){return x.b-x.c > y.b-y.c;});
        q1.clear();q2.clear();
        while(q.size())q.pop();
        for(int i = 1;i <= n;i++)
        {
            f[i] = f[i-1];
            if(a[i].b >= 0)q.push(-a[i].b),f[i] += a[i].b;
            if(q.size() > n/2)f[i] -= -q.top(),q.pop();
            cb[i] = q.size();
        }
        while(q.size())q.pop();
        for(int i = n;i;i--)
        {
            g[i] = g[i+1];
            if(a[i].c >= 0)q.push(-a[i].c),g[i] += a[i].c;
            if(q.size() > n/2)g[i] -= -q.top(),q.pop();
            cc[i] = q.size();
            add(a[i].c);
        }
        ans = sum;
        // cout << sum << endl;
        for(int i = 1;i <= n;i++)
        {
            del(a[i].c);add(a[i].b);
            // cout << i << ' ' << sum << ' ' << f[i] << ' ' << g[i] << ' ' << cb[i] << ' ' << cc[i] << endl;
            ans = max(ans,cb[i]+cc[i+1]>=n/2?f[i]+g[i+1]:sum);
        }
        for(int i = 1;i <= n;i++)ans += a[i].a;
        printf("%lld\n",ans);
    }
    return 0;
}