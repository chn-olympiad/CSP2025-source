#include <bits/stdc++.h>
#define ll long long
#define Int __int128
#define rep(i , a , b) for (int i = (a); i <= (b); i++)
#define drep(i , a , b) for (int i = (a); i >= (b); i--)
#define pb push_back
#define int long long
using namespace std;
typedef pair<int , int> pii;
const int maxn = 2e4+5 , maxm = 1e6+5;
int n , m , k , cnt , c[maxn] , c2[maxn] , a[20][maxn] , b[maxn] , fa[maxn] , dis[maxn] , head[maxn];
ll ans;
struct edge
{
	int u , v , w , next;
	bool operator<(const edge &a) const {return w < a.w;}
}e[maxm<<1];
void Insert(int u , int v , int w){e[++cnt]={u,v,w,head[u]},head[u]=cnt;}
int Find(int x){return fa[x] = x == fa[x] ? x : Find(fa[x]);}
bool Merge(int x , int y)
{
	x=Find(x),y=Find(y);
	if (x == y)return 0;
	fa[x]=y;
	return 1;
}
ll Kruskal()
{
	sort(e + 1 , e + cnt + 1);
	rep(i , 1 , n+1)fa[i]=i;
	ll res=0;
	rep(i , 1 , cnt)
	{
		int x = e[i].u , y = e[i].v;
//		cout << x << " " << y << endl;
		if (Merge(x , y))res+=e[i].w;
	}
//	cout << res << endl;
	return res;
}
void Solve()
{
	rep(i , 1 , n)Insert(n + 1 , i , 1e9+5);
	rep(mask , 1 , (1<<k)-1)
	{
		ll w = 0;
		memset(b , 0x3f , sizeof(b));
		rep(i , 1 , k)
		{
			if (mask & (1<<i-1))
			{
				w+=c[i];
				rep(j , 1 , n)b[j]=min(b[j] , a[i][j]);
			}
		}
		rep(i , 1 , cnt)
		{
			if (e[i].u == n + 1)e[i].w=b[e[i].v];
		}
		Kruskal();
//		break;
		ans=min(ans , Kruskal()+w);
	}
	return;
}
void Solve2()
{
	memset(b , 0x3f , sizeof(b));
	rep(i , 1 , k) rep(j , 1 , n)b[j]=min(b[j] , a[i][j]);
	rep(i , 1 , n)Insert(n + 1 , i , b[i]);
//	rep(i , 1 , k)cout << c[i] << endl;
	ans=min(ans , Kruskal());
	cout << ans << "\n";
}
signed main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	bool flag = 0;
	cin >> n >> m >> k;
	for (int i = 1 , u , v , w; i <= m; i++)cin >> u >> v >> w,Insert(u , v , w);
	rep(i , 1 , k)
	{
		cin >> c[i];
		if (c[i])flag=1;
		rep(j , 1 , n)cin >> a[i][j];
	}
	ans = 1e18;
	ans=min(ans , Kruskal());
	if (!flag)Solve2();
	else Solve();
	cout << ans << "\n";
	return 0;
}

/*
4 3 1
1 2 1000
2 3 1
3 4 1
0 1 1000 1000 1000
*/