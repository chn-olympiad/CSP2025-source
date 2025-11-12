//何昊雨铮 SN-S00025 西安铁一中国际合作学校
#include<bits/stdc++.h>
using namespace std;
int read()
{
	char cc;
	while(1){cc=getchar();if(('0'<=cc&&cc<='9')||cc=='-')break;}
	int sum=0,flag=1;
	cc=='-'?flag=-1:sum=(cc^48);
	while(1){cc=getchar();if(!('0'<=cc&&cc<='9'))break;sum=(sum<<1)+(sum<<3)+(cc^48);}
	return sum*flag;
}
void print(long long x)
{
	if(!x)putchar('0');
	if(x<0){x=-x;putchar('-');}
	int cntt=0,numm[25];
	while(x){numm[++cntt]=x%10;x/=10;}
	for(int i=cntt;i>=1;i--)putchar('0'+numm[i]);
	putchar('\n');
}
const int N=1e4+5,M=1e6+5;
int n,m,k,fa[N+20],xx,yy,c[15],b[15][N];
long long ans,now,noww;
struct node
{
	int x,y;
	long long z;
}a[M];
struct cmpp
{
	bool operator()(node a,node b)
	{
		if(a.z==b.z)
		{
			if(a.x==b.x)return a.y<b.y;
			return a.x<b.x;
		}
		return a.z<b.z;
	}
};
set<node,cmpp>s;
bool cmp(node a,node b)
{
	return a.z<b.z;
}
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dfs(int x)
{
	if(x==k+1)
	{
		for(int i=1;i<=n+k;i++)
			fa[i]=i;
		noww=now;
		for(auto i:s)
		{
			xx=find(i.x),yy=find(i.y);
			if(xx==yy)continue;
			fa[xx]=yy;
			noww+=i.z;
			if(ans<=noww)return;
		}
		ans=noww;
		return;
	}
	dfs(x+1);
	now+=c[x];
	for(int i=1;i<=n;i++)
		s.insert({i,n+x,b[x][i]});
	dfs(x+1);
	now-=c[x];
	for(int i=1;i<=n;i++)
		s.erase({i,n+x,b[x][i]});
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		a[i]={read(),read(),read()};
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		xx=find(a[i].x),yy=find(a[i].y);
		if(xx==yy)continue;
		fa[xx]=yy;
		ans+=a[i].z;
		s.insert(a[i]);
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
			b[i][j]=read();
	}
	dfs(1);
	print(ans);

	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4

