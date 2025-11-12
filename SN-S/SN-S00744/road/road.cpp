#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10010,M=1000010;
int n,m,k,cnt,fa[N];
ll ans,a[20][N],ct[20];
bool flag=true;
struct sd
{
	int lt,rt;
	ll ww;
}b[M<<1];
bool cmp(sd x,sd y)
{
	return x.ww<y.ww;
}
int find(int p)
{
	if (p==fa[p])
		return p;
	return fa[p]=find(fa[p]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,x;
		cin>>u>>v>>x;
		b[i].lt=u;
		b[i].rt=v;
		b[i].ww=x;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>ct[i];
		if (ct[i]!=0)
			flag=false;
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	cnt=0;
	if (k==0)
	{
		for(int i=1;i<=n;i++)
			fa[i]=i;
		sort(b+1,b+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			int c=find(b[i].lt),d=find(b[i].rt);
			if (c!=d)
			{
				cnt++;
				ans+=b[i].ww;
				fa[c]=d;
			}
			if (cnt==m-1)
				break;
		}
		cout<<ans<<"\n";
		return 0;
	}
}
