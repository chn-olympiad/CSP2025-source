#include <bits/stdc++.h>
#define MAXN 10050
#define MAXM 2500000

using namespace std;

int n,m,k,cnt,c[MAXN],head[MAXN],to[MAXM],nx[MAXM],val[MAXM];
bool fl[MAXN],vis[MAXN];
long long ans=100000000000000;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >que;

void add_edge(int x,int y,int z)
{
	val[++cnt]=z;
	to[cnt]=y;
	nx[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int ind,int sum)
{
	if(ind==k+1)
	{
		fill(vis,vis+MAXN,0);
		que.push(make_pair(0,1));
		long long cost=0;
		while(!que.empty())
		{
			int u=que.top().second,tp=que.top().first;
			que.pop();
			if(vis[u])	continue;
			vis[u]=1;					
			cost+=1ll*tp;
			/*
			cout<<"   "<<u<<' '<<tp<<endl;
			for(int i=1;i<=n;i++)
				cout<<vis[i]<<' ';
			cout<<endl;
			*/
			
			for(int i=head[u];i;i=nx[i])
			{
				int v=to[i];
				//cout<<v<<' '<<vis[v]<<endl;
				if(vis[v]||(!fl[v]))	continue;
				que.push(make_pair(val[i],v));
			}
		}
		ans=min(ans,cost+sum);
		
		//cout<<"-----  "<<cost<<' '<<sum<<endl;
		
		return;
	}
	fl[ind+n]=0;
	dfs(ind+1,sum);
	fl[ind+n]=1;
	dfs(ind+1,sum+c[ind]);
	fl[ind+n]=0;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	fill(fl,fl+MAXN,1);
	cin>>n>>m>>k;
	
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int z;
			cin>>z;
			add_edge(i+n,j,z);
			add_edge(j,i+n,z);
		}
	}
	
	dfs(1,0);
	
	cout<<ans<<endl;
	
	return 0;
}
