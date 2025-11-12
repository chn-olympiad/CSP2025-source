#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int u,v,w;
}a[80000005];
int fa[100005];
void init(int n)
{
	for(register int i=1;i<=n;i++)fa[i]=i;
	return ;
}
int find(int x)
{
	if(fa[x]==x)return x;
	else
	{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
void unionn(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
	{
		fa[fx]=fy;
		return ;
	}
	return ;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int n,m,k,c[15],co[15][100005],ans;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//for(register int i=1;i<=k;i++)minn=INT_MAX;
	scanf("%lld%lld%lld",&n,&m,&k);
	init(n);
	for(register int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		a[i].u=u,a[i].v=v,a[i].w=w;
	//	a[i+m].v=u,a[i+m].u=v,a[i+m].w=w;
	}
	for(register int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(register int j=1;j<=n;j++)
		{
			scanf("%lld",&co[i][j]);
		}
	}
	int cnt=m;
	//cout<<cnt<<" 1\n";
	for(register int i=1;i<=k;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			for(register int t=1;t<=n;t++)
			{
				a[++cnt].u=t;
				//cout<<"++"<<endl;
				a[cnt].v=j;
				a[cnt].w=c[i]+co[i][j]+co[i][t];
			}
		}
	}
	//cout<<cnt<<endl;
	/*system("cls");
	system("color A");
	for(int i=1;i<=cnt;i++)
	{
		cout<<a[i].w<<" ";
	}
	puts("");*/
	//cout<<cnt<<endl;
	sort(a+1,a+cnt,cmp);
	for(register int i=1;i<=cnt;i++)
	{
		int x=a[i].u,y=a[i].v,w=a[i].w;
		if(find(x)!=find(y))
		{
			ans+=a[i].w;
			unionn(x,y);
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
