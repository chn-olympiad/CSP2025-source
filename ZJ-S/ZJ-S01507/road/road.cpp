#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5;
int n,m,k;
struct node{
	int u,v,w;
}edge[N*2];
int cnt = 0;
bool vis[N];
int c[15];
int fa[N];
bool f[15];
priority_queue< pair < int ,int>> q;

int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void merge()
{
	int ans = 0;
	while(!q.empty())
	{
		int id = q.top().second;
		//cout<<id<<" "<<noww<<" "<<ans<<"\n";
		q.pop();
		if(vis[id] == 1) continue;
		vis[id] = 1;
		
		int u = find(edge[id].u);
		int v = edge[id].v;
		if(fa[v] != 0) v = find(edge[id].v);
		bool ff = 0;
		for(int i = 2;i <= n;i++)
			if(fa[i] != fa[i-1]) ff = 1;
		if(ff == 0) 
		{
			cout<<ans<<"\n";
			return;
		}
		
		if(u != v)
		{
			fa[v] = u;
			ans += edge[id].w;
			if(f[edge[id].v] == 1) // duo
			{
				f[edge[id].v] = 0;
				if(c[edge[id].v-n] > 0)
				{
					for(int i = 1;i <= n;i++)
					{
						int cntt = m + n * (edge[id].v - n -1) + i;
						q.push({(edge[cntt].w - c[edge[id].v-n])*-1 , cntt});					
						edge[cntt].w = edge[cntt].w - c[edge[id].v - n];
					//	cout<<id<<" "<<cntt<<" "<<edge[cntt].w<<"\n";

					}
				}
		
			}
					
		}
	//	cout<<" "<<"yilun"<<"\n";
		
	}
	cout<<ans<<"\n";
	
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int mmaxn = 0;
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		mmaxn = max(mmaxn,w);
		edge[++cnt] = {min(u,v),max(u,v),w};
		q.push({w*-1,cnt});
	}
	
	for(int i = 1;i <= n;i++) fa[i] = i;
	bool chaojifla = 0;
	
	int cntj = 0;
	for(int jj = 1;jj <= k;jj++)
	{
		cntj++;
		int j = cntj;
		cin>>c[j];
		if(c[j] > mmaxn) 
		{
			cntj--;
			continue;
		}
		if(c[j] != 0) chaojifla = 1;
		for(int i = 1;i <= n;i++)
		{
			int w;
			cin>>w;
			if(w != 0) chaojifla = 1;
			edge[++cnt].u = i;
			edge[cnt].v = n + j;
			edge[cnt].w = w + c[j];
			f[j+n] = 1;
			q.push({-1*(w + c[j]),cnt});
		}
	}
	if(chaojifla == 0)
	{
		cout<<0<<"\n";
		return 0;
	}
//	sort(edge + 1, edge + cnt + 1, cmp);
	merge();
	return 0;
}

