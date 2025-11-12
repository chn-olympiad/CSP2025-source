#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N=2e6+10;
struct node{
	int u,v,w;
}e[11][N],E[N<<1];
int n,m,k,fa[N],c[N],cnt;
long long ans=1000000000000000000;
inline bool cmp(node x,node y)
{
	return x.w<y.w;
}
inline int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
inline void solve(int S)
{
	cnt=0;
	for(int i=1;i<=n+100;i++) fa[i]=i;
	long long res=0;
	int num=0,tot=0;
	while(S)
	{
		num++;
//		cerr<<S%2;//
		if(S%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				cnt++;
				E[cnt]=e[num][i];
			}
			res+=c[num];
		}
		S/=2;
	}
//	cerr<<endl;//
//	for(int i=1;i<=m;i++)
//	{
//		cnt++;
//		E[cnt]=e[0][i];
//	}
	sort(E+1,E+cnt+1,cmp);
//	for(int i=1;i<=cnt;i++) cerr<<E[i].u<<" " <<E[i].v<<" "<<E[i].w<<endl;//
	int i=0,j=0,now=-1,u,v,w;
	while(i<=cnt&&j<=m)
	{
		if(tot==n+num-1) break;
		if(i==cnt) now=2;
		else if(j==m) now=1;
		else if(E[i].w<E[j].w) now=1;
		else now=2;
		if(now==1) u=E[i].u,v=E[i].v,w=E[i].w,i++;
		if(now==2) u=e[0][j].u,v=e[0][j].v,w=e[0][j].w,j++;
		int p1=find(u),p2=find(v);
		if(p1==p2) continue;
		fa[p1]=p2;
		res+=w;
		tot++;
	}
//	cerr<<tot<<"****114514\n";
	ans=min(ans,res);
	return ;
}
void solve114514()
{
	cnt=0;
	for(int i=1;i<=n+100;i++) fa[i]=i;
	long long res=0;
	int num=k,tot=0;
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=n;i++)
		{
			cnt++;
			E[cnt]=e[j][i];
		}
		res+=c[j];
	}
	for(int i=1;i<=m;i++)
	{
		cnt++;
		E[cnt]=e[0][i];
	}
	sort(E+1,E+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(tot==n+num-1) break;
		int p1=find(E[i].u),p2=find(E[i].v);
		if(p1==p2) continue;
		fa[p1]=p2;
		res+=E[i].w;
		tot++;
	}
	ans=min(ans,res);
	return ;	
}
signed main() 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[0][i].u>>e[0][i].v>>e[0][i].w;
	int flag=1; 
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]) flag=0;
		bool fff=0;
		for(int j=1;j<=n;j++)
		{
			cin>>e[i][j].w;
			e[i][j].u=i+n;
			e[i][j].v=j;
			if(e[i][j].w==0) fff=1;
		}
		if(!fff) flag=0;
	}
	if(flag)
	{
		solve114514();
		cout<<ans<<endl;
		return 0;
	}
	sort(e[0]+1,e[0]+m+1,cmp);
	for(int s=0;s<=(1<<k)-1;s++)
	{
		solve(s);
	}
	cout<<ans<<endl;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
