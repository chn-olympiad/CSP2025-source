#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e7+7;
const int N=1e4+7;
struct edge{
	int u,v,w;
}e[M];
int c[N],de[15][N];
int fa[N];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int findx(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=findx(fa[x]);
}
signed main()
{
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	bool f=1;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		{
			f=0;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>de[i][j];
		}
	}
	int p=m;
	if(f&&k!=0)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int w=j+1;w<=n;w++)
				{
					e[++p].u=j;
					e[p].v=w;
					e[p].w=de[i][j]+de[i][w];
					//cout<<e[p].u<<" "<<e[p].v;
				}
			}
		}
		sort(e+1,e+p+1,cmp);
	}
	
	int cnt=0,top=0;
	int sum=0;
	int oop=0;
	while(oop!=n-1)
	{
		edge tmp=e[++top];
		int op1=findx(tmp.u);
		int op2=findx(tmp.v);
		int ans=tmp.w;
		int op=-1;
		
		if(op1!=op2)
		{
//			for(int i=1;i<=k;i++)
//			{
//				if(ans<de[i][tmp.u]+de[i][tmp.v])
//				{
//					ans=de[i][tmp.u]+de[i][tmp.v];
//					op=i;
//				}
//			}
//			if(op!=-1)
//			{
//				de[op][tmp.u]=0;
//				de[op][tmp.v]=0;
//			}
			sum+=ans;
			fa[op1]=op2;
			oop++;
		}
		cnt++;
	}
	cout<<sum;
	return 0;
}

