#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct node
{
	long long w1,w2,v;
}a[1000020],t[1000020],tt[2000020];
long long cnt=0;
bool cmp (node a,node b)
{
	return a.v<b.v;
}
long long f[20020];
long long find (long long w)
{
	if (f[w]==w) return f[w];
	return f[w]=find(f[w]);
}
void merge (long long w1,long long w2)
{
	long long fw1=find(w1),fw2=find(w2);
	if (fw1!=fw2)
	{
		f[fw1]=fw2;
	}
	return;
}
long long v[12][10020];
bool f_new_town[12];
long long ans=1e18;
void dfs (long long w)
{
	if (w<=k)
	{
		f_new_town[w]=false;
		dfs(w+1);
		f_new_town[w]=true;
		dfs(w+1);
		return;
	}
	else
	{
		long long i,j;
		for (i=1;i<=n+k;i++)
		{
			f[i]=i;
		}
		long long sum=0;
		for (i=1;i<=k;i++)
		{
			if (f_new_town[i])
			{
				sum+=v[i][0];
			}
		}
		long long cntt=0;
		for (i=1;i<=cnt;i++)
		{
			cntt++;tt[cntt].w1=t[i].w1;tt[cntt].w2=t[i].w2;tt[cntt].v=t[i].v;
		}
		for (i=1;i<=k;i++)
		{
			if (f_new_town[i])
			{
				for (j=1;j<=n;j++)
				{
					cntt++;tt[cntt].w1=n+i;tt[cntt].w2=j;tt[cntt].v=v[i][j];
				}
			}
			
		}
		sort(tt+1,tt+cntt+1,cmp);
		for (i=1;i<=cntt;i++)
		{
			if (find(tt[i].w1)!=find(tt[i].w2))
			{
				sum+=tt[i].v;
				merge(tt[i].w1,tt[i].w2);
			}
		}
		ans=min(ans,sum);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long i,j;
	cin>>n>>m>>k;
	for (i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for (i=1;i<=m;i++)
	{
		cin>>a[i].w1>>a[i].w2>>a[i].v;
	}
	sort(a+1,a+m+1,cmp);
	long long sum=0;
	for (i=1;i<=m;i++)
	{
		if (find(a[i].w1)!=find(a[i].w2))
		{
			sum+=a[i].v;
			merge(a[i].w1,a[i].w2);
			cnt++;t[cnt].w1=a[i].w1;t[cnt].w2=a[i].w2;t[cnt].v=a[i].v;
		}
	}
	ans=sum;
	for (i=1;i<=k;i++)
	{
		cin>>v[i][0];
		for (j=1;j<=n;j++)
		{
			cin>>v[i][j];
		}
	}
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}
