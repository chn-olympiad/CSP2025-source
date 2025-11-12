#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10005,M=1000005,K=12;
int n,m,k,can[K],tot,C[K],res=0x3f3f3f3f3f3f,fa[N+K],siz[N+K];
struct node
{
	int u,v,z,fr;
	bool operator<(const node&b)const
	{return z<b.z;}
}A[N*K+M];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int merge(int x,int y)
{
	int a=find(x),b=find(y);
	if(siz[a]<siz[b]) fa[a]=b;
	else fa[b]=a;
}
int solve(int b)
{
	int ans=0,cnt=0;
	for(int i=1;i<=n+k;i++)
		fa[i]=i,siz[i]=0;
	for(int i=1;cnt!=n+b-1;i++)
		if(can[A[i].fr]&&find(A[i].u)!=find(A[i].v))
		{
			merge(A[i].u,A[i].v);
			++cnt,ans+=A[i].z;
		}
	return ans;
}
void DFS(int p,int now,int l)
{
	if(p==k+1)
	{
		//printf("%d%d\n",can[1],can[2]);
		res=min(res,solve(l)+now);
		return ;
	}
	DFS(p+1,now,l),can[p]=1,
	DFS(p+1,now+C[p],l+1),can[p]=0;
}
int read()
{
	int x=0;char c=getchar();
	while(c<'0'&&c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read(),
	//scanf("%lld%lld%lld",&n,&m,&k);
	can[0]=1;
	for(int i=1;i<=m;i++)
	{
		++tot;
		A[tot].u=read(),A[tot].v=read(),A[tot].z=read();
	}
	int maxx=0;
	for(int i=1;i<=k;i++)
	{
		C[i]=read(),
		maxx=max(maxx,C[i]);
		for(int j=1;j<=n;j++)
		{
			++tot,A[tot].v=j,
			A[tot].z=read(),
			A[tot].u=n+i,A[tot].fr=i;
		}
	}
	sort(A+1,A+1+tot);
	if(maxx==0)
	{
		for(int i=1;i<=k;i++)
			can[i]=1;
		res=solve(k);
		printf("%lld\n",res);
		return 0;
	}
	DFS(1,0,0);
	printf("%lld\n",res);
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
*/
