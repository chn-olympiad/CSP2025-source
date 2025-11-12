#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, fa[10005], sz[10005], a[15][10005], c[15], ans[10005], gzf[10005], lg[10005];
vector<int> cnt1[15], pre[10005];
struct Edge
{
	int u, v, w;
} eg[1000005], ex[100005];
vector<Edge> dp[1105];
bool cmp(Edge A, Edge B)
{
	return A.w < B.w; 
}
int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(ans, 0x3f, sizeof(ans));
	cin >> n >> m >> k;
	for(int i = 1; i <= n+k; i++) 
	{
		fa[i] = i;
		sz[i] = 1;
	}
	for(int i = 1; i <= m; i++)
		cin >> eg[i].u >> eg[i].v >> eg[i].w;
	sort(eg+1, eg+m+1, cmp);
	int cntE = 0, C = 0;
	for(int i = 1; i <= m; i++)
	{
		if(cntE == n-1) break;
		int u = eg[i].u, v = eg[i].v, w = eg[i].w;
		int fu = find(u), fv = find(v); 
		if(fu == fv) continue;
		dp[0].push_back(eg[i]);
		C += w;
		cntE++;
		if(sz[fu] > sz[fv])
		{
			sz[fu] += sz[fv];
			fa[fv] = fu;
		}
		else
		{
			sz[fv] += sz[fu];
			fa[fu] = fv;
		}
	}
	ans[0] = C;
	lg[1] = 0;
	for(int i = 1; i <= k; i++)
	{
		lg[1<<i] = i;
		cin >> c[i];
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			ex[(i-1)*n+j] = {n+i, j, a[i][j]};
		}
	}
	for(int i = 0; i < (1<<k); i++)
	{
		cnt1[__builtin_popcount(i)].push_back(i);
		for(int j = 0; j < k; j++)
			if(i & (1<<j))
			{
				gzf[i] += c[j+1]; 
				pre[i].push_back(i^(1<<j));
			}
	}
//	while(1)
//	{
//		int S1, S2;
//		cin >> S1 >> S2;
//		cout << lg[S1^S2] << "!\n";
//	}
	for(int C1 = 1; C1 <= k; C1++) // O(k)
		for(auto S:cnt1[C1]) // O(2^k)
		{
			for(auto S2:pre[S]) // O(k)
			{
				vector<Edge> Enow = dp[S2], tmp; //O(n)
				int nt = lg[S^S2]+1, cE = 0, sum = 0; 
				for(int i = (nt-1)*n+1; i <= nt*n; i++)
					Enow.push_back(ex[i]);
				for(int i = 1; i <= n+k; i++)
				{
					sz[i] = 1;
					fa[i] = i;
				}
				sort(Enow.begin(), Enow.end(), cmp);
				for(auto i:Enow)
				{
					if(cE == n+C1-1) break;
					int u = i.u, v = i.v, w = i.w;
					int fu = find(u), fv = find(v);
					if(fu == fv) continue;
					tmp.push_back(i);
					sum += w;
					cE++;
					if(sz[fu] > sz[fv])
					{
						sz[fu] += sz[fv];
						fa[fv] = fu;
					}
					else
					{
						sz[fv] += sz[fu];
						fa[fu] = fv;
					}
				}
				if(ans[S] > sum) dp[S] = tmp;
				ans[S] = min(ans[S], sum);
			}
		}
	int Ans = 998244353998244353, id;
	for(int i = 0; i < (1<<k); i++)
	{
		if(Ans > ans[i]+gzf[i]) id = i;
		Ans = min(Ans, ans[i]+gzf[i]);
	}
	cout << Ans;
//	for(auto i:dp[id]) cout << i.u << ' ' << i.v << ' ' << i.w << '\n';
	return 0;
}














/*
先做一遍最小生成树 代价 m log m
再状压 k*2^k 
每加一个点时增加 n 条边，在原树基础上重做最小生成树时间复杂度 n log n
dp[S] 表示城市改造状态S时用了那些边
时间复杂度 m log m + k*(2^k)*n log n = 1e8 可接受
空间复杂度 k*(2^k)*n = 1e7 也可接受 
*/ 
