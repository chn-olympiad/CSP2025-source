#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair <int , int>
#define pb pushback
#define ll long long
#define ull unsigned long long
#define fastio ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
using namespace std;
const int MAXK = 11 , MAXN = 1e4 + 10 , MAXM = 1e6 + 10;
struct node
{
	int u , v;
	double w;
};
int n , m , k , cnt , sta;
int fa[MAXN] , h[MAXK];
double val[MAXK][MAXN] , lst[MAXK];
node a[MAXM << 2];
int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x , int y)
{
	int fx = find(x) , fy = find(y);
	if(fx == fy) return;
	fa[fx] = fy;
	return;
}
bool cmp(node &x , node &y) {return x.w < y.w;}
ll solve()
{
	double ans = 0;
	for(int i = 1 ; i <= n + k ; i++) fa[i] = i;
	sort(a + 1 , a + 1 + cnt , cmp);
	for(int i = 1 ; i <= cnt ; i++)
	{
		node tmp = a[i];
		if(find(tmp.u) == find(tmp.v)) continue;
		ans += tmp.w;
		merge(tmp.u , tmp.v);
		if(tmp.u > n)
		{
			h[tmp.u - n]++;
			lst[tmp.u - n] = tmp.w;
		}
		if(tmp.v > n)
		{
			h[tmp.v - n]++;
			lst[tmp.v - n] = tmp.w;
		}
	}
	for(int i = 1 ; i <= k ; i++)
	{
		if(h[i] == 1) ans -= lst[i];
		else ans -= val[i][n + 1] / 2 * (h[i] - 2);
	}
	return round(ans);
}
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	fastio;
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++)
	{
		int u , v , w;
		cin >> u >> v >> w;
		a[++cnt] = {u , v , (double)w};
	}
	for(int i = 1 ; i <= k ; i++)
	{
		double tmpval;
		cin >> tmpval;
		val[i][n + 1] = tmpval;
		for(int j = 1 ; j <= n ; j++)
		{
			cin >> val[i][j];
			val[i][j] += tmpval / 2;
			a[++cnt] = {n + i , j , val[i][j]};
		}
	}
	cout << solve();
	cout.flush();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/