#include<bits/stdc++.h>
using namespace std;
const int N=1e4+500;
const int M=1e6+500;
int n,m,k,f[N],in[N];
long long c[15],a[15][N],sumin[N];
struct node
{
	int u,v,w;
}b[M];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void zxscs(int h)
{
	sort(b+1,b+1+m,cmp);
	int cnt=0;long long ans=0;
	for(int i=1;i<=m;i++)
	{//cout<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<endl;
		int fx=find(f[b[i].u]),fy=find(f[b[i].v]);
		if(fx!=fy)
		{
			ans+=b[i].w,cnt++,f[fx]=fy;
			if(h==2)
			{
				in[b[i].v]++,in[b[i].u]++;
				sumin[b[i].u]+=b[i].w;
				sumin[b[i].v]+=b[i].w;
			}
		}
		if(cnt==n-1)break;
	}
	if(h==1)
	{
		cout<<ans;
		return ;
	}
	for(int i=n-k+1;i<=n;i++)
	{//cout<<in[i]<<" "<<i<<endl;
		if(in[i]==1)ans-=sumin[i];
		else ans-=c[i-n+k]*(in[i]-1);
	}
	cout<<ans;
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+20;i++)f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);
	if(k==0)
	{
		zxscs(1);
		return 0;
	}
	int ha=0;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]!=0)ha=1;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	//if(ha==0)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				m++;
				b[m].u=i+n,b[m].v=j,b[m].w=a[i][j]+c[i];
			}
		}
		n+=k;
		zxscs(2);
		return 0;
	}
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
¡£
*/