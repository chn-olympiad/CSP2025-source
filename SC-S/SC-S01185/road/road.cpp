#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,w;
};
struct node2
{
	int u,v,w,flag;
	bool friend operator < (node2 a,node2 b)
	{
		return a.w>b.w;
	}
};
int n,m,k;
int a[15][1000010];
int c[20];
vector<node> mp[1000010];
priority_queue<node2> q;
vector<node2> h;
int p[1000010];
int vis[20];
int vis2[1000010][15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,t;
		cin>>u>>v>>t;
		mp[u].push_back({v,t});
		mp[v].push_back({u,t});
		q.push({u,v,t,0});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(k!=i)
				{
					h.push_back({i,k,0,j});
				}
			}
		}
	}
//	while(q.size())
//	{
//		node2 s=q.top();
//		q.pop();
//		cout<<s.u<<" "<<s.v<<" "<<s.w<<"\n";
//	}
	int ans=0;
	while(1)
	{
		int minn=1e9;
		int flag2=0;
		for(int i=0;i<h.size();i++)
		{
			int num=0;
			if(p[h[i].u]==0||p[h[i].v]==0)
			{
				if(vis2[h[i].u][h[i].flag]==0)
				{
					num+=a[h[i].flag][h[i].u];
				}
				if(vis2[h[i].v][h[i].flag]==0)
				{
					num+=a[h[i].flag][h[i].v];
				}
				if(vis[h[i].flag]==0)
				{
					num+=c[h[i].flag];
				}
				if(num<minn)
				{
					minn=num;
					flag2=i;
				}
//				cout<<h[i].u<<" "<<h[i].flag<<" "<<h[i].v<<" "<<num<<"----------\n";
			}
		}
		node2 s=q.top();
//		cout<<"99999999999999999999999\n";
//		cout<<s.w<<" "<<minn<<"---------\n";
		q.pop();
		if(minn<s.w)
		{
			q.push(s);
			ans+=minn;
			p[h[flag2].u]=p[h[flag2].v]=1;
			vis2[h[flag2].v][h[flag2].flag]=vis2[h[flag2].u][h[flag2].flag]=vis[h[flag2].flag]=1;
		}
		else
		{
			if(p[s.u]==0||p[s.v]==0)
			{
				ans+=s.w;
				p[s.u]=p[s.v]=1;		
			}
		}
		int flag=0; 
		for(int i=1;i<=n;i++)
		{
			if(p[i]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}