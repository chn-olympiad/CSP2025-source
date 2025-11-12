#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read()
{
	ll f = 1, sum = 0; char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') sum = (sum << 1) + (sum << 3) + (c ^ 48), c = getchar();
	return sum * f;
}
const ll N = 2e6 + 10;
ll n, m, k, ct[N], cnt, ans, f[N]; 
struct edge
{
	ll u, v, w;
}b[N];
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
ll find(ll u)
{
	if(f[u] == u) return u;
	else return f[u] = find(f[u]);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	cnt = 0;
	for(int i = 1; i <= m; i++)
	{
		b[i].u = read(), b[i].v = read(), b[i].w = read(); cnt++;
	}  
	for(int i = 1; i <= k; i++)
	{
		ct[i + n] = read();
		for(int j = 1; j <= n; j++)
		{
			cnt++;
			b[cnt].u = n + i, b[cnt].v = j, b[cnt].w = read();
		}	
	}
	sort(b + 1, b + cnt + 1, cmp);
//	for(int i = 1; i <= cnt; i++)
//	{
//		cout<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<"\n"; 
//	}
//	cout<<"----"<<"\n";
	for(int i = 1; i <= n + k; i++) f[i] = i;
	for(int i = 1; i <= cnt; i++)
	{
		if(find(b[i].u) == find(b[i].v)) continue;
		ans += b[i].w; f[find(b[i].u)] = find(b[i].v); 
	}
	cout<<ans; 
	return 0;
}
/*
6 7 0
1 2 2
2 3 1
2 4 2
3 4 1
2 5 2
1 5 3
5 6 2
0
--------------------------------
Process exited after 82.5 seconds with return value 0
请按任意键继续. . .
*/
