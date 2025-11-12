#include<bits/stdc++.h>
using namespace std;
const int maxm=1e6+1e5+5,maxn=1e4+1e1+5,maxk=1e1+5;
struct node{
	int u,v,w;
}x[maxm];
int n,m,k,c[maxk],a[maxk][maxn],f[maxn],cnt;
long long ans;
bool t=1;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int d)
{
	if(f[d]==d)
	  return d;
	return f[d]=find(f[d]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	  {
	  	scanf("%d%d%d",&x[i].u,&x[i].v,&x[i].w);
	  }
	for(int i=1;i<=k;i++)
	  {
	  	scanf("%d",&c[i]);
		if(c[i]!=0)
		  t=0;
	  	for(int j=1;j<=n;j++)
	  	  scanf("%d",&a[i][j]);
	  }
	if(t)
	  {
	  	for(int i=1;i<=k;i++)
	  	  for(int j=1;j<=n;j++)
	  	    x[m+(i-1)*n+j].u=n+i,x[m+(i-1)*n+j].v=j,x[m+(i-1)*n+j].w=a[i][j];
	  	for(int i=1;i<=n+k;i++)
	  	  f[i]=i;
	  	sort(x+1,x+m+n*k+1,cmp);
	  	for(int i=1;i<=m;i++)
	  	  if(find(x[i].u)!=find(x[i].v))
	  	    {
	  	    	ans=ans+x[i].w;
	  	    	f[find(x[i].u)]=find(x[i].v);
	  	    	cnt++;
	  	    	if(cnt==n-1+k)
	  	    	  break;
			}
		printf("%lld",ans);
		return 0;
	  }
	if(k<=5&&m<=1e5)
	  {
	  	ans=1e18;
	  	for(int b=0;b<(1<<k);b++)
	  	  {
	  	  	cnt=0;
	  	  	int ws=0;
	  	  	long long minn=0;
	  		for(int i=1;i<=k;i++)
	  		  if(((1<<(i-1))&b)>0)
	  		    {
	  		    	minn=minn+c[i];
	  		    	ws++;
	  		  		for(int j=1;j<=n;j++)
	  	    		  x[m+(ws-1)*n+j].u=n+i,x[m+(ws-1)*n+j].v=j,x[m+(ws-1)*n+j].w=a[i][j];
			    }
	  		for(int i=1;i<=n+ws;i++)
	  	  	  f[i]=i;
	  		sort(x+1,x+m+n*ws+1,cmp);
	  		for(int i=1;i<=m;i++)
	  	  	  if(find(x[i].u)!=find(x[i].v))
	  	    	{
	  	    		minn=minn+x[i].w;
	  	    		f[find(x[i].u)]=find(x[i].v);
	  	    		cnt++;
	  	    		if(cnt==n-1+ws)
	  	    	  	  break;
				}
			ans=min(ans,minn);
		  }
		printf("%lld",ans);
		return 0;
	  }
	for(int i=1;i<=k;i++)
	  for(int j=1;j<=n;j++)
	  	x[m+(i-1)*n+j].u=n+i,x[m+(i-1)*n+j].v=j,x[m+(i-1)*n+j].w=a[i][j];
	for(int i=1;i<=n+k;i++)
	  f[i]=i;
	sort(x+1,x+m+n*k+1,cmp);
	for(int i=1;i<=m;i++)
	  if(find(x[i].u)!=find(x[i].v))
	  	{
	  	   	ans=ans+x[i].w;
	  	    f[find(x[i].u)]=find(x[i].v);
	  	    cnt++;
	  	    if(cnt==n-1+k)
	  	    break;
		}
	printf("%lld",ans);
	return 0;
}/*1
2
10 9 8
4 0 0*/