#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct node
{
	int x,y,z;
}e[2000005];
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int a[11][10005];
int fa[10020];
int c[15];
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
signed main()
{
//	system("fc road3.ans road.out");
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].x>>e[i].y>>e[i].z;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			cin>>a[i][j];
	bool f1=1;
	for(int i=1;i<=k;i++)
		if(a[i][0]!=0)
			f1=0;
	if(k==0)
	{
		int cnt=0,ans=0;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			int xx=find(e[i].x);
			int yy=find(e[i].y);
			if(xx!=yy) fa[xx]=yy,cnt++,ans+=e[i].z;
			if(cnt==n-1) break;
		}
		cout<<ans;
	}
	if(f1==1)
	{
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				if(a[i][j]==0)
					for(int w=1;w<=n;w++)
						if(w!=j)
							e[++m]={j,w,a[i][w]};
		int cnt=0,ans=0;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			int xx=find(e[i].x);
			int yy=find(e[i].y);
			if(xx!=yy)
			{
				fa[xx]=yy;
				cnt++;
				ans+=e[i].z;
			}
			if(cnt==n-1) break;
		}
		cout<<ans;
		return 0;
	}
	int cnt=0,ans=0,asd=0;
	for(int i=1;i<=k;i++)
	{
		int maxx=0;
		for(int j=1;j<=n;j++) maxx=max(maxx,a[i][j]);
		if(a[i][0]<2*maxx)
		{
			asd++;
			ans+=a[i][0];
			for(int j=1;j<=n;j++)
				for(int w=1;w<=n;w++)
					if(j!=w)
						e[++m]={j+n,w,a[i][w]};
		}
	}
	n+=asd;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int xx=find(e[i].x);
		int yy=find(e[i].y);
		if(xx!=yy) fa[xx]=yy,cnt++,ans+=e[i].z;
		if(cnt==n-1) break;
	}
	cout<<ans;
	return 0;
}

