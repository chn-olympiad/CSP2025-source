#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;
const int N = 10105,M = 1000005,inf = 1000000001;
int n,m,k,fa[N],sz,c[N],pot[N];
ll ans;
struct node
{
	int u,v,w,p;
}b[M],a[N];
bool operator<(node &a,node &b)
{
	return a.w < b.w;
}
bool operator>(const node &a,const node &b)
{
	return a.w > b.w;
}
priority_queue<node,vector<node>,greater<node>>q;
struct node1
{
	int v,w;
}mp[15][N];
bool cmp1(node1 a,node1 b)
{
	return a.w < b.w;
}
void init()
{
	for (int i = 1; i <= n+k; i++)
		fa[i] = i;
	while (!q.empty()) q.pop();
}
int find(int a)
{
	if (fa[a] != a) fa[a] = find(fa[a]);
	return fa[a];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> b[i].u >> b[i].v >> b[i].w,b[i].p = k;
	for (int i = 0; i < k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			mp[i][j] = {j,x};
		}
		sort(mp[i]+1,mp[i]+n+1,cmp1);
		mp[i][n+1] = {i,inf};
	}
	sort(b+1,b+m+1);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	int cnt = n;
	for (int i = 1; i <= m; i++)
	{
		int x = find(b[i].u),y = find(b[i].v);
		if (fa[x] != fa[y])
		{
			a[++sz] = b[i];
			ans += b[i].w;
			fa[y] = x;
			cnt--;
			if (cnt == 1) break;
		}
	}
	a[++sz] = {1,1,inf,k};
//	cout << ans << '\n';
	for (int i = 1; i < 1<<k; i++)
	{
		init();
		ll tot = 0,ppc = 0;
		for (int j = 0; j < k; j++)
		{
			if (i>>j&1)
			{
				ppc++;
				tot += c[j];
				q.push({n+j+1,mp[j][1].v,mp[j][1].w,j});
			}
			pot[j] = 1;
		}
		q.push(a[1]);
		pot[k] = 1;
		int yy = n+ppc;
	//	cout << yy << '\n';
		while (yy > 1)
		{
			node now = q.top();
			q.pop();
	//	cout << i << ' ' << now.u << ' ' << now.v << ' ' << now.w << '\n';
			int x = find(now.u),y = find(now.v);
			if (x != y)
			{
				tot += now.w;
				yy--;
				fa[y] = x;
			}
			if (now.p == k) q.push(a[++pot[k]]);
			else
			{
				q.push({n+now.p+1,mp[now.p][++pot[now.p]].v,mp[now.p][pot[now.p]].w,now.p});
			}	
		//	if (y <= 1) break;
		}
	//	cout << tot << '\n';
		ans = min(ans,tot);
	}
	cout << ans << '\n';
	return 0;
}
