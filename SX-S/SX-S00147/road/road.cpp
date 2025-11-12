#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e4+35,M=2e6+5;
struct no{
	int u,v,w;
}a[M];
no num[M];
int tot=0,kkk=0;
long long ans=0;
bool cmp(no x,no y)
{
	return x.w<y.w;
}
int fa[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int n,m,k;
long long clac(int nn,long long ress)
{
	long long res=ress;
	if(ress>ans) return ans;
	sort(num+1,num+tot+1,cmp);
	int ct=1;
	for(int i=1;i<=nn;i++) 
	{
		fa[i]=i;
	}
	for(int i=1;i<=tot;i++)
	{
		int fu=find(num[i].u);
		int fv=find(num[i].v);
		if(fu==fv) continue;
		ct++;
		res+=num[i].w;
		fa[fu]=fv;
		if(res>=ans) return ans;
		if(ct==nn) return res;
	}
	return res;
}
int c[25],d[25][N];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>num[i].u>>num[i].v>>num[i].w;
	}
	tot=m;
	int mx=0;
    sort(num+1,num+tot+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=tot;i++)
	{
		int fu=find(num[i].u);
		int fv=find(num[i].v);
		if(fu==fv) continue;
		ans+=num[i].w;
	    a[++kkk]=num[i];
	    mx=num[i].w;
		fa[fu]=fv;
	}
	for(int i=1;i<=k;i++) 
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>d[i][j];
		 } 
	}
    for(int s=1;s<(1<<k);s++)
    {
    	tot=n-1;
    	int cur=0;
		long long res=0;
		for(int i=1;i<=tot;i++) num[i]=a[i];
    	for(int i=1;i<=k;i++)
    	{
    		if(s&(1<<(i-1))) 
    		{
    			cur++;
				res+=c[i];
    			for(int j=1;j<=n;j++)
    			{
    				if(d[i][j]<=mx) num[++tot]=(no){cur+n,j,d[i][j]};
				}
			}
		}
		ans=clac(n+cur,res);
	}
	cout<<ans<<endl;
	return 0;
}
