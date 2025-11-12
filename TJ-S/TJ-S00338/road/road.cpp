#include<bits/stdc++.h>
using namespace std;
#define ll 			long long
#define MOD			1000000007
#define inf  			0x3f3f3f3f
#define INF 			0x3f3f3f3f3f3f3f3f
#define ff(i, l, r) 		for(int i = (l), END##i = (r); i <  END##i; ++i)
#define ffe(i, l, r) 		for(int i = (l), END##i = (r); i <= END##i; ++i)
#define fb(i, l, r) 		for(int i = (l), END##i = (r); i >  END##i; --i)
#define fbe(i, l, r) 		for(int i = (l), END##i = (r); i >= END##i; --i)
#define iter(it, v)		for(auto it : v)
#define fopn(fn)		freopen(#fn".in", "r", stdin);freopen(#fn".out", "w", stdout)
#define fcls			fclose(stdin);fclose(stdout)
int n, m, k, u, v, w, a[10012][10012], cnt; ll ans;
int b[10012];
struct node
{
    int u;
    int w;
    node(int a, int b) { u = a, w = b; }
    bool operator < (const node &ano) const { return w > ano.w; }
};
struct edge
{
    int v, w;
    edge(int a, int b) { v = a, w = b; }
};
vector<edge> ve[10012];
priority_queue<node> Q;
int main()
{
	fopn(road);

    cin >> n >> m >> k;
    ffe(i, 1, m) cin >> u >> v >> w, ve[u].push_back(edge(v, w)), ve[v].push_back(edge(u, w));
    ffe(j, 1, k)
    {
        cin >> w, ve[1].push_back(edge(j + n, w));
        ffe(i, 1, n) cin >> w, ve[j + n].push_back(edge(i, w));
    }
    Q.push(node(1, 0));
    while(!Q.empty() && cnt < n)
    {
        node cu = Q.top(); Q.pop();
        if(b[cu.u] > 0) continue;
        ++b[cu.u], ans += cu.w;
        if(1 <= cu.u && cu.u <= n) ++cnt;
        iter(v, ve[cu.u]) Q.push(node(v.v, v.w));
    }
    cout << ans;
	fcls; return 0;
}
