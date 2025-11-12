#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+50;
int n,m,k;
struct node
{
	int u,v,w;
}edge[1000010];
int f[N];
int find(int x)
{
	if(x == f[x]) return f[x];
	return f[x] = find(f[x]);
}
int vi[15][N];
int lo[15];
int pian[1010][1010];
bool cmp(node aa,node bb)
{
	return aa.w < bb.w;
}
bool op = 1;
long long ans = 0,cnt = 0;
//set<int> q;
priority_queue<int> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(pian,0x3f,sizeof(pian));
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
	{
		f[i] = i;
	}
	for(int i = 1;i <= m;i++)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
		if(k>0)pian[edge[i].u][edge[i].v] = min(pian[edge[i].u][edge[i].v],edge[i].w);
		if(k>0)pian[edge[i].v][edge[i].u] = min(pian[edge[i].v][edge[i].u],edge[i].w);
	}
	sort(edge+1,edge+1+m,cmp);
	for(int i = 1;i <= k;i++)
	{
		cin >> lo[i];
		for(int j = 1;j <= n;j++)
		{
			cin >> vi[i][j];
		}
	}
	for(int i = 1;i <= m;i++)
	{
		if(find(edge[i].u) == find(edge[i].v)) continue;
		ans += edge[i].w;
		f[edge[i].u] = find(edge[i].v);
		cnt++;
		//if(k>0)q.insert(-edge[i].w);
		if(cnt >= n-1)
		{
			break;
		}
	}
	if(k <= 0)
	{
		cout << ans << '\n';
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			for(int d = 1;d <= k;d++)
			{
				if(vi[d][i]+vi[d][j] < pian[i][j])
				{
					pian[i][j] = vi[d][i]+vi[d][j];
				}
			}
			//cout << pian[i][j] << ' ';
		}
		//cout << '\n';
	}
	ans = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			if((int)q.size() < n-1) 
			{
				ans += pian[i][j];
				q.push(pian[i][j]);
			}
			else
			{
				if(pian[i][j] < q.top())
				{
					ans -= q.top();
					q.pop();
					q.push(pian[i][j]);
					ans += pian[i][j];
				}
			}
		}
	}
	cout << ans << '\n';
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

