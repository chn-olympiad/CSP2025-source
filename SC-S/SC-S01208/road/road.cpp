#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4,M = 1e6,K = 10;
struct Edge
{
	int u,v;ll w;
	bool operator < (const Edge &_)const
	{ 
		return w < _.w;
	}
}A[M + 5],a[11][N + 5];
struct DSU
{
	int f[N + K + 5],siz[N + K + 5];
	void init(int n)
	{
		for(int i = 1;i <= n;i++)f[i] = i,siz[i] = 1;
	}
	int fnd(int x)
	{
		while(x != f[x])x = f[x] = f[f[x]] = f[f[f[x]]];
		return x;
	}
	bool merge(int x,int y)
	{
		x = fnd(x);y = fnd(y);
		if(x == y)return 1;
		if(siz[x] < siz[y])swap(x,y);
		f[y] = x;siz[x] += siz[y];
		return 0;
	}
}dsu;
int n,m,k,now[K + 5];
ll c[K + 5],ans = 1e18;
ll calc(int s)
{
	ll res = 0,cnt = 1;
	for(int i = 0;i < k;i++)
		if(s >> i & 1)res += c[i],now[i] = 0;
	now[k] = 0;
	dsu.init(n + k);
	while(now[k] < n)
	{
		ll mn = a[k][now[k]].w;int id = k;
		for(int i = 0;i < k;i++)
			if((s >> i & 1)&&now[i] <= n&&mn > a[i][now[i]].w)
				mn = a[i][now[i]].w,id = i;
		Edge e = a[id][now[id]];now[id]++;
		if(!dsu.merge(e.u,e.v))res += e.w,cnt++;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++)
		cin>>A[i].u>>A[i].v>>A[i].w;
	for(int i = 0;i < k;i++)
	{
		cin>>c[i];
		for(int j = 1;j <= n;j++)
			cin>>a[i][j].w,
			a[i][j].u = i + 1 + n,a[i][j].v = j;
		sort(a[i] + 1,a[i] + n + 1);
	}
	dsu.init(n + k);
	sort(A + 1,A + m + 1);
	for(int i = 1,j = 0;i <= m;i++)
		if(!dsu.merge(A[i].u,A[i].v))
			a[k][++j] = A[i];
	for(int s = 0;s < (1 << k);s++)
		ans = min(ans,calc(s));
	cout<<ans<<"\n";
}
/*
cin<<
cout>>
bits\stdc++.h
#import
windows.h
inline read()
int mian()
freopen("road.in",'r',stdin)
freopen("road.in",'w',stdin)
freopen("road.in","w",stdin)
freopen("road.out","r",stdout)
freopen("road.out","r",stdin)
freopen("road.in","w",stdout)
freopen("road.in","w",stdout)
freopen("road.out","r",stdin)
while(1)
for(;;) 
deque <int> a[1000005]
*/