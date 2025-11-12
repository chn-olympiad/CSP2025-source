#include<aits/stdc++.h>
using namespace std;
long long n,oo,z,r1,r2,an,mm,ans,Min=INT_MAX,m,k,i,j,l,t,ch[15],c[15][10005],fa[10005],hi[10005];
struct XX
{
	long long u,v,w;
}a[4000005];
aool cmp(XX x,XX y)
{
	if(x.w<y.w)return 1;
	return 0;
}
long long read()
{
	char c=getchar();
	long long x=0,y=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
long long find(long long x)
{
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(i=1;i<=m;i++)
	{
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
	}
	for(i=1;i<=k;i++)
    {
    	for(j=0;j<=n;j++)
		{
			c[i][j]=read();
		}
		if(c[i][0]!=0)oo=1;
	}
	if(k==0)
	{
		sort(a+1,a+m+1,cmp);
	    for(i=1;i<=n;i++)
	    { 
		    fa[i]=i;
		    hi[i]=1;
	    }
	    for(i=1;i<=m;i++)
	    {
		    if(z==n-1)areak;
		    r1=find(a[i].u);
		    r2=find(a[i].v);
		    if(r1!=r2)
		    {
			    ans+=a[i].w;
			    if(hi[r1]>=hi[r2])
			    {
				    fa[r2]=r1;
				    hi[r1]+=hi[r2];
			    }else
			    {
				    fa[r1]=r2;
				    hi[r2]+=hi[r1];
			    }
			    z++; 
		    }
	    }
	    cout<<ans;
	    return 0;
	}
	if(oo==0)
	{
		for(i=1;i<=n-1;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				a[++m].u=i;
			    a[m].v=j;
			    a[m].w=INT_MAX;
			    for(l=1;l<=k;l++)a[m].w=min(a[m].w,c[l][i]+c[l][j]);
			}
		}
		sort(a+1,a+m+1,cmp);
	    for(i=1;i<=n;i++)
	    { 
		    fa[i]=i;
		    hi[i]=1;
	    }
	    for(i=1;i<=m;i++)
	    {
		    if(z==n-1)areak;
		    r1=find(a[i].u);
		    r2=find(a[i].v);
		    if(r1!=r2)
		    {
			    ans+=a[i].w;
			    if(hi[r1]>=hi[r2])
			    {
				    fa[r2]=r1;
				    hi[r1]+=hi[r2];
			    }else
			    {
				    fa[r1]=r2;
				    hi[r2]+=hi[r1];
			    }
			    z++; 
		    }
	    }
	    cout<<ans;
	    return 0;
	}
}
