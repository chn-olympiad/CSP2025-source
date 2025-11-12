#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > a;
vector<int>c;
struct BFS{
	int v;
	int len;
};
bool vis[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		a[u][v] = w;
		a[v][u] = w;
	}
	bool flag = false;
	for(int i=m+1;i<=m+k+1;i++)
	{
		cin>>c[i];
		if(c[i]>0)
		{
			flag = true;
		}
		int x;
		cin>>x;
		a[i][i-m-1] = x;
		a[i-m-1][i] = x;
		if(x>0)
		{
			flag = true;	
		} 	
	}
	if(flag == false)
	{
		cout<<0;
		return 0;
	}
//	queue<BFS> q;
//	int ans = 0;
//	for(int i=1;i<=n;i++)
//	{
//		while(!q.empty())
//		{
//			BES now = q.top();
//			q.pop();
//			if(now == q)
//			{
//				ans += 
//			}
//		}
//	}

	return 0;
} 
