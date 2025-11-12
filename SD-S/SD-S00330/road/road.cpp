#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e4+15;
const int M=1e6+5;
struct node
{
	int id,v;
	friend bool operator < (node x,node y)
	{
		return x.v<y.v;
	}
}a[15];
struct edge
{
	int x,y,z;
	friend bool operator < (edge x,edge y)
	{
		return x.z<y.z;
	}
}e[M],rl[N];
int n,m,p,val[15][N],vec[N],fa[N],bst[N][(1<<10)+5];
int read()
{
	int res,f=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9')
	if(ch=='-')
	f=-1;
	res=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
	res=(res<<1)+(res<<3)+(ch^48);
	return res*f;
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,k,x,y,cnt=0,tot;
	ll cst,ans=0;
	n=read();m=read();p=read();
	for(i=1;i<=m;i++)
	{
		e[i].x=read();e[i].y=read();e[i].z=read();
	}
	sort(e+1,e+m+1);
	for(i=1;i<=n;i++)
	fa[i]=i;
	for(i=1;cnt<n-1;i++)
	{
		x=find(e[i].x);y=find(e[i].y);
		if(x==y)
		continue;
		ans+=e[i].z;fa[x]=y;
		rl[++cnt]=e[i];
	}
	for(i=1;i<=p;i++)
		for(j=0;j<=n;j++)
		val[i][j]=read();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=p;j++)
		a[j]=(node){j,val[j][i]};
		sort(a+1,a+p+1);
		for(k=1;k<=p;k++)
		{
			x=a[k].id;
			for(j=1;j<=(1<<p)-1;j++)
			if(!bst[i][j]&&(j&(1<<(x-1))))
			bst[i][j]=x;
		}
	}
	for(i=1;i<=(1<<p)-1;i++)
	{
		cst=tot=0;
		for(j=1;j<=p;j++)
		if(i&(1<<(j-1)))
		{
			cst+=val[j][0];
			vec[++tot]=j;
		}
		for(j=1;j<=n-1;j++)
		e[j]=rl[j];
		for(j=1;j<=n;j++)
		e[n+j-1]=(edge){n+bst[j][i],j,val[bst[j][i]][j]};
		for(j=1;j<=n+p;j++)
		fa[j]=j;
		sort(e+1,e+n*2);
		for(j=1,cnt=0;j<=2*n-1&&cnt<n+tot-1;j++)
		{
			x=find(e[j].x);y=find(e[j].y);
			if(x==y)
			continue;
			cst+=e[j].z;
			fa[x]=y;cnt++;
		}
		ans=min(ans,cst);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
