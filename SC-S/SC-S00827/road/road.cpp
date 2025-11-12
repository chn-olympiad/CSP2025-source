#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,MM=1e6+5+1e5+5;
int n,m,k;
struct node{
	int ui,vi,wi;
}ro[MM];
int c[N];
int a[10][N];
int fa[N],sz[N];
void init(int n){
	for(int i=1;i<=n;i++)
		fa[i]=i,sz[i]=1;
}
int getfa(int x){
	if(fa[x]==x)	return x;
	return fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
	int fx=getfa(x),fy=getfa(y);
	fa[fx]=fy;
	sz[fy]+=sz[fx];
}
bool cmp(node x,node y){
	return x.wi<y.wi;
}
int ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init(n);
	ans=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&ro[i].ui,&ro[i].vi,&ro[i].wi);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		n++;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			ro[++m].ui=n;
			ro[m].vi=j;
			ro[m].wi=a[i][j];
		}
	}
	if(k==0)
	{
		sort(ro+1,ro+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			merge(ro[i].ui,ro[i].vi);
			ans+=ro[i].wi;
			if(sz[getfa(ro[i].vi)]==n)
			{
				break;
			}
		}
		printf("%d",ans);
	}
	
	return 0;
}