#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int fa[10000001];
int got(int x)
{
	return fa[x]==x?x:fa[x]=got(fa[x]);
}
struct st
{
	int u,v,w;
};
vector<st> vt;
int vis[100001];
bool cmp(st x,st y)
{
	return x.w<y.w;
}
int b[10000001],c[11][1000001];
vector<bool> line;
int solve()
{
	memset(vis,0,sizeof vis);
	vector<st> tr=vt;
	for(int i=1;i<=2*n;i++)
	{
		fa[i]=i;
	}	
	int ans=0,count=0;
	for(int i=0;i<line.size();i++)
	{
		if(line[i])
		{
			ans+=b[i+1];
			for(int j=1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					tr.push_back({j,k,c[i+1][k]+c[i+1][j]});
					tr.push_back({k,j,c[i+1][k]+c[i+1][j]});
				}
			}
		}
	}
	sort(tr.begin(),tr.end(),cmp);
	for(auto x:tr)
	{
		if(got(x.v)!=got(x.u))
		{
			fa[x.v]=got(x.u);
			 ans+=x.w;
		//	 cout<<x.u<<" "<<x.v<<"\n";
			 if(x.v<=n&&!vis[x.v])
			 {
			 	count++;
			 	vis[x.v]=1;
			 }
			 if(x.u<=n&&!vis[x.u])
			 	count++,vis[x.u]=1;
		//	count++;
		}
		if(count==n)
		break;
	}
	return ans;
}
int ans_sum=1e18;
void dfs()
{
	if(line.size()==k)
	{
		ans_sum=min(ans_sum,solve());
		return ;
	}
	for(int i=0;i<=1;i++)
	{
		line.push_back(i);
		dfs();
		line.pop_back();
	}
}
signed main()
{
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		vt.push_back({u,v,w});
		vt.push_back({v,u,w});
	}
	for(int i=1;i<=k;i++)
	{
		int w;
		cin>>b[i];
		for(int j=1;j<=n;j++)
		{
	
			cin>>c[i][j];
		}
	}
//	for(int i=1;i<=k;i++,cout<<"\n")
//	for(int j=1;j<=n;j++)
//	cout<<c[i][j]<<" ";
	dfs();
	cout<<ans_sum;
	fclose(stdin);
	fclose(stdout);
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

