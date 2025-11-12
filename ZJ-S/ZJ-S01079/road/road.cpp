#include <bits/stdc++.h>
using namespace std;
const int M=1e6+100,N=1e4+100;
typedef long long ll;
struct edge{int x,y,z;}e[M],z[12][N],temp;
int cost[12];
int fa[N],id[M];
int afind(int x){return fa[x]==x?x:fa[x]=afind(fa[x]);}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,newm=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	cin>>e[i].x>>e[i].y>>e[i].z;
	for(int i=1;i<=k;i++)
	{
		cin>>cost[i];
		for(int j=1;j<=n;j++)
		{
			int zz;
			cin>>zz;
			z[i][j]=(edge){n+i,j,zz};
		}
		sort(z[i]+1,z[i]+n+1,[](const edge &a,const edge &b){return a.z<b.z;});
	}
	ll minn=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++)id[i]=i;
	sort(id+1,id+m+1,[](const int &a,const int &b){return e[a].z<e[b].z;});
	for(int i=1;i<=m;i++)
	{
		int xx=afind(e[id[i]].x),yy=afind(e[id[i]].y);
		if(xx!=yy)
		{
			minn+=e[id[i]].z;
			z[0][++newm]=e[id[i]];
			fa[xx]=yy;
		}
	}
	int kk=1<<k;
	for(int S=1;S<kk;S++)
	{
		ll ans=0;
		vector<int>v;
		v.emplace_back(0);
		for(int j=1;j<=k;j++)
		if((S>>(j-1))&1)
		{
			ans+=cost[j];
			v.emplace_back(j);
		}
		int dcnt=v.size();
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int ecnt[12];
		for(int i=0;i<=k;i++)ecnt[i]=1;
		while(dcnt)
		{
			temp.z=1e9+10;int id=-1;
			for(auto y:v)
			{
				if(z[y][ecnt[y]].z<temp.z)
				{
					temp=z[y][ecnt[y]];
					id=y;
				}
			}
			ecnt[id]++;
			if(z[id][ecnt[id]].x==0)dcnt--;
			int xx=afind(temp.x),yy=afind(temp.y);
			if(xx!=yy)
			{
				fa[xx]=yy;
				ans+=temp.z;
			}
		}
		minn=min(minn,ans);
	}
	cout<<minn<<'\n';
}
/*
#include <bits/stdc++.h>
using namespace std;
const int M=1e6+100,N=1e4+100,NN=1.2e5+100;
typedef long long ll;
struct edge{int x,y,z;}e[M],used[NN];
int cost[12],z[12][N];
int fa[N],id[M];
int afind(int x){return fa[x]==x?x:fa[x]=afind(fa[x]);}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("road_ex.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,newm=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	cin>>e[i].x>>e[i].y>>e[i].z;
	for(int i=1;i<=k;i++)
	{
		cin>>cost[i];
		for(int j=1;j<=n;j++)cin>>z[i][j];
	}
	ll ans=0,minn=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++)id[i]=i;
	sort(id+1,id+m+1,[](const int &a,const int &b){return e[a].z<e[b].z;});
	for(int i=1;i<=m;i++)
	{
		int xx=afind(e[id[i]].x),yy=afind(e[id[i]].y);
		if(xx!=yy)
		{
			minn+=e[id[i]].z;
			used[++newm]=e[id[i]];
			fa[xx]=yy;
		}
	}
	int kk=1<<k;
	for(int S=1;S<kk;S++)
	{
		ll ans=0;
		int cnt=newm;
		for(int j=1;j<=k;j++)
		if((S>>(j-1))&1)
		{
			ans+=cost[j];
			for(int i=1;i<=n;i++)
			used[++cnt]=(edge){n+j,i,z[j][i]};
		}
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=cnt;i++)id[i]=i;
		sort(id+1,id+cnt+1,[](const int &a,const int &b){return used[a].z<used[b].z;});
		for(int i=1;i<=cnt;i++)
		{
			int xx=afind(used[id[i]].x),yy=afind(used[id[i]].y);
			if(xx!=yy)
			{
				fa[xx]=yy;
				ans+=used[id[i]].z;
			}
		}
		minn=min(minn,ans);
	}
	cout<<minn<<'\n';
}

#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int random(int l,int r){return rnd()%(r-l+1)+l;}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("road_ex.in","w",stdout);
	int n=1e4,m=1e6,k=10;
	cout<<n<<' '<<m<<' '<<k<<'\n';
	for(int i=1;i<n;i++)cout<<i<<' '<<i+1<<' '<<random(0,1e9)<<'\n';
	for(int i=1;i<=m-n+1;i++)cout<<random(1,n)<<' '<<random(1,n)<<' '<<random(0,1e9)<<'\n';
	for(int i=1;i<=k;i++)
	{
		cout<<random(0,1e9)<<' ';
		for(int j=1;j<=n;j++)cout<<random(0,1e9)<<" \n"[j==n];
	}
}
*/
