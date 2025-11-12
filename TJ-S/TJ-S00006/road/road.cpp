#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int fa[100050];
struct edge
{
	int u,v,w;
}a[1000020];
int get_root(int x)
{
	if(fa[x]==x)return x;
	return get_root(fa[x]);
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int m,n,k;
int e[100010];
int vis[15];
int ek[11][100010];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	int cnt=0;
	int ans=0;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int fu=get_root(a[i].u);
		int fv=get_root(a[i].v);
		if(fv!=fu)
		{
			cnt++;
			e[cnt]=i;
			fa[fu]=fa[fv];
			ans+=a[i].w;
		}
		if(cnt==n-1)break;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			scanf("%d",&ek[i][j]);
		}
	}
	if(k>0)
	{
		for(int i=cnt;i>=1;i--)
		{
			int minn=a[e[i]].w;
			for(int j=1;j<=k;j++)
			{
				int f=0;
				if(vis[j]==0)f=ek[j][0];
				f+=ek[j][a[e[i]].u];
				f+=ek[j][a[e[i]].v];
				if(f<=minn)
				{
					vis[j]=1;
					ans=ans-minn+f;
					minn=f;
					cout<<a[e[i]].u<<" "<<a[e[i]].v<<" "<<j<<endl;
				}
			}
		}
	}
	cout<<ans;
	return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
// 	if(k==0){
//		int cnt=0;
//		int ans=0;
//		sort(a+1,a+m+1,cmp);
//		for(int i=1;i<=n;i++)
//		{
//			int fu=get_root(a[i].u);
//			int fv=get_root(a[i].v);
//			if(fv!=fu)
//			{
//				cnt++;
//				fa[fu]=fa[fv];
//				ans+=a[i].w;
//			}
//			if(cnt==n-1)
//			{
//				cout<<ans;
//				return 0;
//			}
//		}
//	}
