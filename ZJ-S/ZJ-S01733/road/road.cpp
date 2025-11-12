#include<bits/stdc++.h>
using namespace std;
struct road
{
	int y,z;
};
struct edge
{
	int x,y,z;
}s[2000003];
bool cmp(edge a,edge b){return a.z<b.z;}
set<int> se[10003];
map<int,int> v[10003],mp[10003];
int n,m,k,cost[10003],f[10003],x,y,z;
long long sum,MAX,ans=0;
int getf(int x)
{
	if(f[x]!=x)
		f[x]=getf(f[x]);
	return f[x];
}
void kruskal()
{
	int w=0;
//	MAX=sum;
	for(int i=1;i<=n;i++)
	{
		set<int>::iterator it=se[i].begin();
		while(it!=se[i].end())
		{
			s[++w].x=i;
			s[w].y=*it;
			s[w].z=v[i][*it];
			it++;
		}
	}
	sort(s+1,s+1+w,cmp);
	int ts=0;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=w&&ts<n;i++)
	{
		x=getf(s[i].x);
		y=getf(s[i].y);
		if(x!=y)
		{
			f[y]=x;
			ans+=s[i].z;
			ts++;
		}
	}
//	cout<<MAX<<'\n';
//	cout<<'\n';
//	ans=min(ans,MAX);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		se[x].insert(y);
		se[y].insert(x);
		v[x][y]=z;
		v[y][x]=z;
	}
	if(k==0)
	{
		kruskal();
		cout<<ans;
		return 0;
	}
	bool f=1;
	for(int i=1;i<=k;i++)
	{
		cin>>cost[i];
		ans+=cost[i];
		if(cost[i]!=0)
			f=0;
		for(int j=1;j<=n;j++)
		{
			cin>>mp[i][j];
			if(mp[i][j]!=0)
				f=0;
		}
	}
//	cout<<ans<<'\n';
//	if(f)
//	{
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(v[i][j]||v[j][i])
			{
				v[i][j]=min(v[i][j],mp[i][j]);
				v[j][i]=min(v[j][i],mp[i][j]);
			}
			else
			{
				v[i][j]=mp[i][j];
				v[j][i]=mp[i][j];
				se[j].insert(i);
				se[i].insert(j);
			}
		}
	}
	kruskal();
	cout<<ans;	
	return 0;
//	}
//	dfs(1);
//	cout<<ans;
//	return 0;
//	return 0;
}//chzxlfw AK IOI!
