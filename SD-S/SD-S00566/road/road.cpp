#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 1e4 + 10;
int n,m,k;
ll ans;
struct node
{
	int x,y;
	ll val;
	bool operator < (const node &a) const
	{
		return val > a.val;
	}
};
priority_queue<node> q;
int pa[MX];
int find(int x)
{
	return (pa[x] == x) ? x : pa[x] = find(pa[x]);
}
inline void ksu()
{
	for(int i = 1;i <= n;i++) pa[i] = i;
	while(!q.empty())
	{
		node now = q.top();
		q.pop();
		int x = now.x,y = now.y;
		int fx = find(x),fy = find(y);
		if(fx != fy)
		{
			pa[fx] = fy;
			ans += now.val;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		int x,y,k;
		cin >> x >> y >> k;
		q.push({x,y,k});
	}
	ksu();
	cout << ans << '\n';
	return 0;
}
