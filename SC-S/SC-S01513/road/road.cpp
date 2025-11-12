#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline LL read()
{
	LL w=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
} 
struct edge{
	LL u,v,w;
} e[1000005],r[1010005];
struct village{
	LL v,a[1000005];
} c[11];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
LL n,m,k,f[10005],ans,l;
LL find(LL x)
{
	if(f[x]!=x)
	{
	    f[x]=find(f[x]);
	}
	return f[x];
}
bool merge(LL x,LL y)
{
    LL find_x=find(x);
	LL find_y=find(y);
	if(find_x==find_y)
	{
		return 0; 
	}	
	else
	{
	    f[find_x]=find_y; 
	} 
	return 1; 
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(LL i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(LL i=1;i<=m;i++)
	{
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	for(LL i=1;i<=k;i++)
	{
		c[i].v=read();
		for(LL j=1;j<=n;j++)
		{
		    c[i].a[j]=read();	
		}
	}
	sort(e+1,e+m+1,cmp);
	for(LL i=1;i<=m;i++)
	{
		if(merge(e[i].u,e[i].v)==1)
		{
			ans+=e[i].w;
			l++;
		}
	}
	for(LL i=1;i<=k;i++)
	{
		LL ans1=c[i].v,l=m; 
		for(LL j=1;j<=n;j++)
		{
			f[j]=j;
		}
		for(LL j=1;j<=m;j++)
		{
			r[j]=e[j];
		}
		for(LL j=1;j<=n;j++)
		{
			for(LL q=j+1;q<=n;q++)
			{
				l++;
				r[l].u=j;
				r[l].v=q;
				r[l].w=c[i].a[j]+c[i].a[q];
			}
		}
		sort(r+1,r+m+n+1,cmp);
		for(LL j=1;j<=n+m;j++)
		{
			if(merge(r[j].u,r[j].v))
			{
				ans1+=r[j].w; 
			}
		}
		ans=min(ans,ans1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}