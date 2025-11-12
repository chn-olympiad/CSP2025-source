#include <bits/extc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,int>

constexpr int MAXN = 1e4 + 50,MAXM = 11e5 + 5,INBUF = 1 << 21;
char ibuf[INBUF],*ip1 = ibuf,*ip2 = ibuf;
#define getchar() ((ip1 == ip2) && ((ip2 = (ip1 = ibuf) + fread(ibuf,1,INBUF,stdin)),(ip1 == ip2)) ? EOF : *ip1++)
template<typename T>
inline T read()
{
	T res = 0;
	char ch = getchar();
	while(!isdigit(ch))
		ch = getchar();
	while(isdigit(ch))
	{
		res = res * 10 + (ch ^ 48);
		ch = getchar();
	}
	return res;
}

int T = 1,n,m,k,num,N,u[MAXM],v[MAXM],w[MAXM],ord[MAXM],c[15],a[15][MAXN],fa[MAXN],top;
inline int find(int x)
{return ((fa[x] == x) ? x : (fa[x] = find(fa[x])));}
inline void merge(int x,int y)
{
	x = find(x),y = find(y);
	if(x == y)
		return ;
	fa[x] = y;
}
inline bool query(int x,int y)
{return find(x) == find(y);}
inline ll Kruskal(int n)
{
	for(int i = 1;i <= n;i++)
		fa[i] = i;
	for(int i = 1;i <= top;i++)
		ord[i] = i;
	stable_sort(ord + 1,ord + top + 1,[&](int A,int B){return w[A] < w[B];});
	int cnt = 0;
	ll mst = 0;
	for(int i = 1;i <= top;i++)
	{
		if(cnt >= n - 1)
			break;
		if(query(u[ord[i]],v[ord[i]]))
			continue;
		merge(u[ord[i]],v[ord[i]]);
		mst += w[ord[i]],++cnt;
	}
	return mst;
}
inline void Solve()
{
	n = read<int>(),m = read<int>(),k = read<int>();
	for(int i = 1;i <= m;i++)
		u[i] = read<int>(),v[i] = read<int>(),w[i] = read<int>();
	bool flg = 1;
	for(int i = 0;i < k;i++)
	{
		c[i] = read<int>();
		flg &= (c[i] == 0);
		for(int j = 1;j <= n;j++)
		{
			a[i][j] = read<int>();
			flg &= (a[i][j] == 0);
		}
	}
	if(flg)
	{
		cout << '0';
		return ;
	}
	int U = (1 << k) - 1;
	ll ans = 0x3f3f3f3f3f3f3f3f;
	for(int S = 0,num;S <= U;S++)
	{
		ll sum = 0;
		top = m,num = n;
		for(int i = 0;i < k;i++)
		{
			if((S >> i) & 1)
			{
				++num;
				sum += c[i];
				for(int j = 1;j <= n;j++)
				{
					++top;
					u[top] = j,v[top] = n + i + 1,w[top] = a[i][j];
				}
			}
		}
		ans = min(ans,sum + Kruskal(num));
	}
	cout << ans;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef LOCAL
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	while(T--)
		Solve();
}