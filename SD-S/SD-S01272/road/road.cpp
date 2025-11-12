#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n,m,k,p[1010],l[1010][1010],fa[1010],ans;
struct Node{
	int u,v,w;
}ed[N];
bool cmp(Node x,Node y)
{
	return x.w<y.w;
}
int fnd(int x)
{
	return fa[x]==fa[fa[x]]?fa[x]:fnd(fa[x]=fa[fa[x]]);
}
void uni(int x,int y)
{
	int a=fnd(x),b=fnd(y);
	fa[b]=a;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
	}
	memset(l,0x3f3f3f,sizeof(l));
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>p[j];
			for(int b=j-1;b>0;b--)
			{
				l[b][j]=min(l[b][j],p[j]+p[b]+c);
			}
		}
	}
	int cnt=m;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cnt++;
			ed[cnt].u=i;
			ed[cnt].v=j;
			ed[cnt].w=l[i][j];
		}
	}
	sort(ed+1,ed+cnt+1,cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=cnt;i++)
	{
		int a=fnd(ed[i].u),b=fnd(ed[i].v);
		if(a==b)
		{
			continue;
		}
		uni(ed[i].u,ed[i].v);
		ans+=ed[i].w;
	}
	cout<<ans;
	return 0;
} 
