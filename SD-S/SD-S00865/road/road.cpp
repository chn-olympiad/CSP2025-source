#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long cnt=0;
long long ans=0;
int v[100010];
struct node
{
	int x,y;
	long long z;
}a[10000010];
int fnd(int x)
{
	if(v[x]==x)
		return x;
	return v[x]=fnd(v[x]);
}
bool cmp(node x,node y)
{
	return x.z<y.z;
}
bool pd()
{
	for(int i=2;i<=n;i++)
		if(v[i]!=v[i-1])
			return 1;
	return 0;
}/*
void print()
{
	for(int i=1;i<=n;i++)
		cout<<v[i]<<' ';
	cout<<'\n';
}*/
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		long long x,y,z;
		cin>>x>>y>>z;
		a[++cnt].x=x;
		a[cnt].y=y;
		a[cnt].z=z;
	}
	for(int i=1;i<=k;i++)
	{
		long long c;
		long long t[10010];
		cin>>c;
		for(int i=1;i<=n;i++)
			cin>>t[i];
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				a[++cnt].x=i;
				a[cnt].y=j;
				a[cnt].z=c+t[i]+t[j];
		//printf("2*%d<->%d:%d*\n",a[cnt].x,a[cnt].y,a[cnt].z);
			}
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=n;i++)
		v[i]=i;
	for(int i=1;i<=cnt&&pd();i++)
	{
		if(fnd(a[i].x)==fnd(a[i].y))
			continue;
		//printf("2*fx=%d,fy=%d\n",fnd(a[i].x),fnd(a[i].y));
		v[fnd(a[i].x)]=fnd(a[i].y);
		fnd(a[i].x);
		//print();
		//printf("3*fx=%d,fy=%d\n",fnd(a[i].x),fnd(a[i].y));
		ans+=a[i].z;
		//printf("1*%d<->%d:%lld\n",a[i].x,a[i].y,a[i].z);
	}
	cout<<ans<<'\n';
	
	return 0;
}

