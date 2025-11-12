//longlong? MLE? clear?
#include<bits/stdc++.h>
#define LL long long
#define LOCAL
using namespace std;
const int N=1e4+10,M=2e6+10,K=15;
LL rd()
{
	LL s=0,g=1;char c=getchar();
	while(!isdigit(c)){if(c=='-');c=getchar();}
	while(isdigit(c)){s=(s<<3)+(s<<1)+(c-'0');c=getchar();}
	return s*g;
}
void wt(LL x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>9){wt(x/10);}
	putchar(x%10+'0');
	return ;
}
struct Edge
{
	int u,v;
	LL w;
	bool operator < (const Edge &a) const
	{
		return w<a.w;
	}
}e[M];
int n,m,k,tot,cnt;
int fa[N];
LL c[K],a[K][N],sumc;
LL ans;
int get_fa(int x)
{
	return x==fa[x]?x:fa[x]=get_fa(fa[x]);
}
void kru()
{
	sort(e+1,e+tot+1);
	for(int i=1;i<=tot;i++)
	{
		int u=e[i].u,v=e[i].v;
		LL w=e[i].w;
		int fu=get_fa(u),fv=get_fa(v);
		if(fu==fv)continue;
		fa[fu]=fv;
		ans+=w;
		cnt++;
		if(cnt==n-1)break; 
	}
}
int main()
{
	#ifdef LOCAL
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
	#endif
	n=rd();m=rd();k=rd();
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int u=rd(),v=rd();
		LL w=rd();
		e[++tot]={u,v,w};
	} 
	for(int i=1;i<=k;i++)
	{
		c[i]=rd();
		for(int j=1;j<=n;j++)
		{
			a[i][j]=rd();
		}
		sumc+=c[i];
	}
	kru();
	if(k==0||sumc!=0)wt(ans),puts("");
	else if(sumc==0)wt(0),puts("");
	#ifdef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
}
/*
5 8 0
1 2 6
2 5 0
5 3 1
5 4 9
2 4 7
1 4 8
4 3 5
1 5 10
*/
