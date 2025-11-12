#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20,M=2e6+10;
struct edge
{
	int a,b,w,is;
}e[M];
int n,m,k;
int p[N],c[15],fc[15];
long long ans=LONG_LONG_MAX;
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
inline int find(int x)
{
	if(x==p[x])return x;
	return p[x]=find(p[x]);
}
inline void kruscal(int dn,long long dans)
{
	for(register int i=1;i<=n+k;++i)
		p[i]=i;
	register int cd=0;
	long long res=0;
	for(register int i=1;i<=m;++i)
	{
//		printf("x=%d c[x]=%d\n",e[i].is,c[e[i].is]);
		if(!c[e[i].is])continue;
		register int a=e[i].a,b=e[i].b,w=e[i].w;
		a=find(a),b=find(b);
		if(a!=b)
		{
			res+=w;
			p[b]=a;
			cd++;
			if(cd==n+dn-1)break;
		}
	}
	if(cd==n+dn-1)ans=min(ans,res+dans);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	register int a,b,k1;
	for(register int i=1;i<=m;++i)
	{
		scanf("%d %d %d",&a,&b,&k1);
		e[i]={a,b,k1,0};
	}
	for(register int i=1;i<=k;++i)
	{
		scanf("%d",&fc[i]);
		register int fy;
		for(register int j=1;j<=n;++j)
		{
			scanf("%d",&fy);
			e[++m]={j,n+i,fy,i};
		}
	}
	sort(e+1,e+m+1,cmp);
	for(register int i=0;i<(1<<k);++i)
	{
		register int l=0;
		memset(c,0,sizeof c);
		c[0]=1;
		register int x=i;
		while(x)
		{
			c[++l]=x&1;
			x>>=1;
		}
//		printf("k=%d\n",i);
//		for(register int j=1;j<=c[0];++j)
//			cout<<c[j]<<' ';
//		cout<<"\n";
		register int dn=0;
		long long dans=0;
		for(register int j=1;j<=l;++j)
			if(c[j])dn++,dans+=fc[j];
		kruscal(dn,dans);
	}
	cout<<ans;
	return 0;
}
