#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
 }
const int N=2e4+5,M=2e6+5;
struct node
{
	int u,v,w;
}s[M],e[M];
//struct edge
//{
//	int nxt,to,v;
//};
int n,m,k,cnt,a[15][N],c[N],f[N],ans,t[30],op,mn[N],res,tot;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
//void add(int x,int y,int z)
//{
//	e[++tot].nxt=h[x];
//	e[tot].to=y;
//	e[tot].v=z;
//	h[x]=tot;
//}
int find(int x)
{
	if(x==f[x])return f[x];
	f[x]=find(f[x]);
	return f[x];
}
void gt(int x)
{
	if(x==k+1)
	{
		if(op==0)return;
		int yl=tot;
		int kop=res;
		for(int i=1;i<=tot;i++)s[i]=e[i];
		for(int i=1;i<=n+op;i++)f[i]=i;
		for(int i=1;i<=op;i++)
		{
			for(int j=1;j<=n;j++)
			{
				e[++tot].w=a[t[i]][j];
				e[tot].u=i+n;
				e[tot].v=j;
			}
		}
//		cout<<op<<" "<<ans<<" "<<res<<" "<<kop<<'\n';
//		for(int i=1;i<=op;i++)cout<<t[i]<<" ";cout<<'\n';
//		for(int i=1;i<=tot;i++)
//		{
//			cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<'\n';
//		}
		sort(e+1,e+tot+1,cmp);
		int sx=0;
		for(int i=1;i<=tot;i++)
		{
			int p=find(e[i].u),q=find(e[i].v);
			if(p==q)continue;
			f[q]=p;
			sx++;
			kop+=e[i].w;
			if(sx==n+op-1)break;
		}
		ans=min(kop,ans);
		tot=yl;
		for(int i=1;i<=tot;i++)e[i]=s[i];
		return;
	}
	t[++op]=x;
	res+=c[x];
	gt(x+1);
	res-=c[x];
	op--;
	gt(x+1); 
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		s[++cnt].u=x;
		s[cnt].v=y;
		s[cnt].w=z;
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	for(int i=1;i<=n;i++)f[i]=i;
//	cout<<cnt<<'\n';
	sort(s+1,s+cnt+1,cmp);
	int sx=0;
//	if(m<=1e6)
//	{
//		for(int i=1;i<=cnt;i++)
//		{
//			e[++tot].u=s[i].u;
//			e[tot].v=s[i].v;
//			e[tot].w=s[i].w;
//		}
//		ans=2e18;
//		gt(1);
//		cout<<ans<<" "<<tot<<'\n'<<'\n';
//		tot=0;
////		return 0;
//	}
	for(int i=1;i<=cnt;i++)
	{
		int x=find(s[i].u),y=find(s[i].v);
//		cout<<i<<" "<<s[i].u<<" "<<s[i].v<<" "<<s[i].w<<'\n';
		if(x==y)continue;
		f[y]=x;
		sx++;
		ans+=s[i].w;
		e[++tot].u=s[i].u;
		e[tot].v=s[i].v;
		e[tot].w=s[i].w;
//		e[++tot].u=s[i].v;
//		e[tot].v=s[i].u;
//		e[tot].w=s[i].w;
//		add(s[i].u,s[i].v,s[i].v);
//		add(s[i].v,s[i].u,s[i].v);
		if(sx==n-1)break;
	}
//	cout<<ans<<'\n';
	gt(1);
	cout<<ans;
	return 0;
}

