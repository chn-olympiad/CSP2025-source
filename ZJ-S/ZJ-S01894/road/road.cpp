#include<bits/stdc++.h>
using namespace std;
long long x,ans,mn=1e16,v,c[20001],V;
int P,n,m,M,k,D,l,r,id,L,R,f[20001],Siz[20001];
set<int> s[20001];
struct pig
{
	int l,r,v;
}e[3000001];
bool cmp(pig l,pig r)
{
	return l.v<r.v;
}
int cnt(int x)
{
	int ss=0;
	while(x)
	{
		++ss;
		x^=(x&-x);
	}
	return ss;
}
int F(int id)
{
	if(f[id]==id)
	  return id;
	return f[id]=F(f[id]);
}
long long in()
{
	char ch=getchar();
	long long sum=0;
	while(ch<'0'||ch>'9')
	  ch=getchar();
	while(ch<='9'&&ch>='0')
	  sum=sum*10+ch-48,ch=getchar();
	return sum;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in(),m=in(),k=in();
	for(register int i=1;i<=m;++i)
	  e[i].l=in(),e[i].r=in(),e[i].v=in();
	for(register int i=1;i<=k;++i)
	{
		c[i]=in();
		for(register int j=1;j<=n;++j)
		{
		    x=in();
		    e[++m].l=n+i,e[m].r=j,e[m].v=x;
		}
	}
	sort(e+1,e+1+m,cmp);
	for(register int K=0;K<(1<<k);++K)
	{
		P=n+cnt(K);
		ans=0;
		for(register int i=1;i<=k;++i)
		  if((K>>i-1)&1)
		    ans+=c[i];
		for(register int i=1;i<=n;++i)
		  f[i]=i,Siz[i]=1;
		for(register int i=n+1;i<=n+k;++i)
		  f[i]=i;
		id=0;
		while(id<m)
		{
			++id;
			L=e[id].l;
			R=e[id].r;
			V=e[id].v;
			if(max(L,R)>n&&((K>>max(L,R)-1-n)&1^1))
			  continue;
			if(F(L)==F(R))
			  continue;
			ans+=V;
			if(ans>=mn)
			  break;
			Siz[F(R)]+=Siz[F(L)];
			f[F(L)]=F(R);
			if(Siz[F(R)]==P)
			  break;
		}
		mn=min(mn,ans);
	}
	cout<<mn;
	return 0;
}
