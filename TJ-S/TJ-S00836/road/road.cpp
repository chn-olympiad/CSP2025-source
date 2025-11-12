#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[15],a[15][10005];
long long maxx=-1,ans,fa[10005];
bool pd[10005][10005];
struct node
{
	long long fro,to,w;
}b[1000105];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
long long find(long long x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&b[i].fro,&b[i].to,&b[i].w);
		pd[b[i].fro][b[i].to]=1;
		pd[b[i].to][b[i].fro]=1;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		maxx=max(maxx,c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	if(k==0)
	{
		int sum=0;
		sort(b+1,b+1+m,cmp);
		for(int i=1;sum<n-1;i++)
		{
			if(find(b[i].fro)!=find(b[i].to))
			{
				sum++;//cout<<b[i].fro<<' '<<b[i].to<<'&'<<find(b[i].fro)<<' '<<find(b[i].to)<<endl;///////////
				fa[find(b[i].fro)]=fa[b[i].to];
				ans+=b[i].w;
				//cout<<b[i].fro<<'*'<<b[i].to<<'*'<<b[i].w<<endl;////////////////
			}
		}
		cout<<ans;
	}
	else// if(maxx==0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(!pd[i][j]&&m<1000100)
				{
					m++;
					b[m].fro=i;
					b[m].to=j;
					b[m].w=2000000000;
//					cout<<b[m].w<<'*';////////////////////////////////
					pd[i][j]=pd[j][i]=1;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=k;j++)
			{
				b[i].w=min(b[i].w,a[j][b[i].fro]+a[j][b[i].to]+c[j]);
			}//cout<<b[i].w<<'&'<<endl;//<<a[j][b[i].fro]<<' '<<a[j][b[i].to],,cout<<' '<<b[i].w<<endl;//////////////////
		}
		sort(b+1,b+1+m,cmp);
		int sum=0;
		for(int i=1;sum<n-1;i++)
		{
			if(find(b[i].fro)!=find(b[i].to))
			{
				sum++;
				fa[find(b[i].fro)]=fa[b[i].to];
				ans+=b[i].w;
				//cout<<b[i].w<<'&'<<endl;//cout<<b[i].fro<<'*'<<b[i].to<<'*'<<b[i].w<<endl;////////////////
			}
		}
		cout<<ans;
		//for(int i=1;i<=n;i++) cout<<find(fa[i])<<' ';////////////////////////
	}
	return 0;
}
