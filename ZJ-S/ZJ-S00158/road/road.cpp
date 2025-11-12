#include<bits/stdc++.h>
using namespace std;
int n,m,k,en;
long long c[15],a[15][10009];
int bel[10911];
struct edge{
	int u,v;
	long long w;
	int ad,bc;
}tl[1400009];
int tf[15];
long long tmp[15];
bool cmp1(edge x,edge y)
{
	if(x.ad!=y.ad)return x.ad>y.ad;
	return x.w<y.w;
}
bool us[15];
int find(int x)
{
	if(x==bel[x])return x;
	return find(bel[x]);
}
void mer(int u,int v)
{
	int u1=find(u),v1=find(v);
	bel[v]=bel[u1];
	bel[v1]=bel[u1];
	return;
}
long long mst(int cn,int sz)
{
	int cnt=cn;
	long long res=0;
	for(int i=1;i<=sz;i++)
	{
		if(find(tl[i].u)!=find(tl[i].v)&&us[tl[i].bc]==1)
		{
			cnt--,res+=tl[i].w;
			mer(tl[i].u,tl[i].v);
			if((tl[i].u>en||tl[i].v>en)&&(tl[i].u<=en||tl[i].v<=en))tf[tl[i].bc]++,tmp[tl[i].bc]=tl[i].w;
		}
		if(cnt==1)return res;
	}
	return res;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(tl,0,sizeof(tl));
	cin>>n>>m>>k;
	en=n;
	for(int i=1;i<=n;i++)bel[i]=i;
	for(int i=1;i<=m;i++)cin>>tl[i].u>>tl[i].v>>tl[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	us[0]=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=en;j++)
		{
			tl[++m].u=n+1;
			tl[m].v=j,tl[m].w=a[i][j],tl[m].bc=i;
			tl[++m].u=n+2;
			tl[m].v=j,tl[m].w=a[i][j],tl[m].bc=i;
		}
		m++;
		tl[m].u=n+1,tl[m].v=n+2,tl[m].w=c[i],tl[m].ad=1,tl[m].bc=i;
		n+=2;
	}
	sort(tl+1,tl+m+1,cmp1);
	n=en;
	long long ans=mst(n,m);
	for(int i=1;i<=k;i++)
	{
		memset(tf,0,sizeof(tf));
		memset(tmp,0,sizeof(tmp));
		for(int j=1;j<=n+2*k;j++)bel[j]=j;
		us[i]=1;
		bool fgg=0;
		long long res=mst(n+2,m);
		for(int j=1;j<=i;j++)
			if(tf[j]==1)fgg=1;
		if(res<=ans&&fgg==0)ans=res,n+=2;
		else us[i]=0;
//		cout<<us[i];
	}
	cout<<ans;
	return 0;
}
