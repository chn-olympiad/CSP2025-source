#include<bits/stdc++.h>
#include<chrono>
#define int long long
#define pb push_back
#define mp make_pair
#define ms microseconds
#define N 15005
#define M 1200005 
using namespace std;
using namespace chrono;
auto Star=system_clock::now();
auto GetTime(){return (double)(duration_cast<ms>(system_clock::now()-Star).count())*ms::period::num/ms::period::den;}
void PrintTime(){cout<<"Cost="<<GetTime()<<"s."<<endl;}
int read()
{
	int t=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) t=t*10+ch-48,ch=getchar();
	return t*f;
}
const int inf=0x3f3f3f3f3f3f3f3f;
int n,m,K,ans=inf,maxn;
bool book[1015],vis[1015];
int dis[1015],w[1015][1015];
int father[N];
int a[12],c[12][N];
struct Edge{int x,y,z;}e[M];
int findx(int x){if(father[x]==x) return x;return father[x]=findx(father[x]);}
void addedge(int x,int y,int z){w[x][y]=w[y][x]=z;}
int kruskal(int n,int m)
{
	sort(e+1,e+1+m,[](Edge x,Edge y){return x.z<y.z;});
	int i,j,ans=0,tot=0;
	for(i=1;i<=n;i++) father[i]=i;
	
	for(i=1;i<=m;i++)
	{
		int x=e[i].x,y=e[i].y,z=e[i].z;
		
		int fax=findx(x),fay=findx(y);
		if(fax==fay) continue;
		father[fax]=fay;tot++;ans+=z;//千万不要建成fax
		if(tot==n-1) break;//足够是一颗树了  
	}
	return ans;
}
int prim(int n)
{
	memset(dis,0x3f3f,sizeof(dis));	
	memset(vis,0,sizeof(vis));
	dis[1]=0;vis[1]=1;//从1开始
	int i,j,ans=0,x=1;
	for(i=1;i<n;i++) //直接跑n-1次即可 
	{
		int mins=inf,dian;
		for(int y=1;y<=maxn;y++)
		{
			if(!vis[y]&&book[y])  
			{
				dis[y]=min(dis[y],w[x][y]);
				if(dis[y]<mins) mins=dis[y],dian=y;//
			}
		}
		vis[dian]=1;//dian也进入 
		ans+=mins;x=dian;//下一个进行更新的点。
		
	}
	return ans;
}
void dfs(int cnt,int dian)
{
	int i,j;
	if(cnt==K+1) 
	{
		ans=min(ans,prim(dian));
		return ;
	}
	dfs(cnt+1,dian);
	
	book[cnt+n]=book[cnt+n+K]=1;
	addedge(cnt+n,cnt+n+K,a[cnt]); for(i=1;i<=n;i++) addedge(cnt+n,i,c[cnt][i]);
	dfs(cnt+1,dian+2);//增加了2个点。本体和边权
	addedge(cnt+n,cnt+n+K,inf);    for(i=1;i<=n;i++) addedge(cnt+n,i,inf);
	book[cnt+n]=book[cnt+n+K]=0;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),K=read();
//	printf("n=%d\n",n);
	maxn=n+2*K;//最大点数 
	int i,j,flag1=1;
	
	for(i=1;i<=m;i++) e[i].x=read(),e[i].y=read(),e[i].z=read();
	for(i=1;i<=K;i++)
	{
		int flag2=0;
		a[i]=read(); if(a[i]) flag1=0;
 		for(j=1;j<=n;j++) 
 		{
 			c[i][j]=read(); 
 			if(!c[i][j]) flag2=1;
		}
		if(!flag2) flag1=0;//如果不存在c[i][j]==0的 
	}
	if(!K) //m==1e6,n==1e4，mlogm 
	{
		printf("%lld",kruskal(n,m));//正常的传入即可 
		return 0; 
	}
	else if(flag1)//满足性质A ，O(mlogm) ，直接全部加入 
	{
		
		int t=m;
		for(i=1;i<=K;i++)
			for(j=1;j<=n;j++) e[++t]=(Edge){i+n,j,c[i][j]};
		printf("%lld",kruskal(K+n,t));
		return 0;
	}
	else //n==1e3,k==5,O(2^k*n*n)
	{
		for(i=1;i<=n;i++) book[i]=1;
		memset(w,0x3f3f,sizeof(w));
		for(i=1;i<=m;i++) 
		{
			int x=e[i].x,y=e[i].y,z=e[i].z;
 			w[x][y]=w[y][x]=min(w[x][y],z);//加边到最小值 
		 } 
		dfs(1,n);
		printf("%lld",ans);
	}

	return 0;
	fclose(stdin);
	fclose(stdout);
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

