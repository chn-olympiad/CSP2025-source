#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{ll u, v, w;
} a[1000010];
int f[1000010];
int query(int x)
{
	if(f[x] == x) return x;
	return f[x] = query(f[x]);
}
void merge(int x, int y)
{
	int fx = query(x),
		fy = query(y);
	if(fx != fy) f[fx] = fy;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	cin >> n >> m >> k;// k == 0: zui xiao sheng cheng shu
	for(int i = 1; i <= m; i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	if(k == 0){
		for(int i = 1; i <= n; i++) f[i] = i;
		sort(a+1,a+m+1,[](Node x, Node y){
			return x.w < y.w;
		});
		ll ans = 0;
		for(int i = 1; i <= m; i++)
		{
			if(query(a[i].u) != query(a[i].v))
			{
				ans += a[i].w;
				merge(a[i].u, a[i].v);
			}
		}
		cout << ans << endl;
		return 0;
	}
	else
	{
		cout << 0;
		return 0;
	}
}
