#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,fa[100105],b[15][100005],val[15],pp;
struct node
{
	int u,v,w;
}a[10000005],c[10000005];
long long ans=INT_MAX,ssm;
void init(int x)
{
//	cout<<x<<endl;
	pp=0;
	for(int i=0;i<k;i++)
	{
		if(x&(1<<i))
		{
			pp++;
			ssm+=val[i+1];
			for(int j=1;j<=n;j++)
			{
				a[++cnt]={n+pp,j,b[i+1][j]};
			}
		}
	}
	return;
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void ku()
{
	sort(a+1,a+1+cnt,cmp);
//	cout<<cnt<<endl;
//	for(int i=1;i<=cnt;i++)cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
//	cout<<endl;
	long long num=0,sum=0;
	for(int i=1;i<=n+pp;i++)fa[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		if(num+ssm>ans)return ;
		if(sum==n+pp-1)break;
		int x=find(a[i].u),y=find(a[i].v);
		if(x==y)continue;
		num+=a[i].w;
		fa[x]=y;
		sum++;
	}
//	cout<<cnt<<endl;
	ans=min(ans,num+ssm);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[++cnt]={u,v,w};
		c[cnt]=a[i];
	}
	bool f=1;
	for(int i=1;i<=k;i++)
	{
		cin>>val[i];
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=0;i<(1<<k);i++)
	{
		int last=cnt;
		ssm=0;
		init(i);
		ku();
		for(int j=1;j<=last;j++)a[i]=c[i];
		cnt=last;
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/