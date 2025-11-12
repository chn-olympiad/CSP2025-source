#include<bits/stdc++.h>
using namespace std;
long long f[10001],c[10001],ad[11][10001];
struct linen
{
	int st,en,weight;
}l[2000007];
int n,m,k;
bool cmp(linen x,linen y)
{
	return x.weight<y.weight;
}
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
long long kruscal()
{
	long long ans=0;
	sort(l,l+m+1,cmp);
	int i=1,cnt=0;
	while(cnt!=n-1)
	{
		int x=l[i].st,y=l[i].en;
		if(find(x)==find(y))
		{
			i++;
			continue;
		}
		cnt++;
		ans+=l[i].weight;
		f[x]=y;
		i++;
	}
	return ans;
}
/*void dfs(int dep,int sum,int cost)
{
	if(dep==k+1)
	{
		minn=min(minn,kruscal(cost);
		return;
	}
	dfs(dep+1,sum,cost);
	add(sum,m+sum*n);
	dfs(dep+1,sum+1,cost+c[dep]);
	return;
}*/
int main()
{
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>l[i].st>>l[i].en>>l[i].weight;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>ad[i][j];
	}
	if(k==0)
	{
		cout<<kruscal();
		return 0;
	}
	//cout<<1;
	bool w=1;
	for(int i=1;i<=k;i++) if(c[i]) w=0;
	//cout<<1;
	if(w=1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
			    long long minn=999999999;
				for(int p=1;p<=k;p++)
				{
					minn=min(minn,ad[p][i]+ad[p][j]);
				}
				m++;
				l[m].st=i;
				l[m].en=j;
				l[m].weight=minn;
			}
		}
		cout<<kruscal();
		return 0;
	}
	/*else
	{
		dfs(1,0,0);
		cout<<minn;
	}*/
	return 0;
}
