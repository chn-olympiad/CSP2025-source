#include<bits/stdc++.h>
//考虑只保留 MST 上的边枚举k子集跑 MST
//但是和 k 可以不连通
//那就相当于没加这个，一定不优秀
//如果和 k中某点 有两条边，说明这是有用的
//否则 一定不如不加这个点。这个我们已经枚举过了 
//所以做法是duide 
//15:40 卡常结束 969ms 
using namespace std;
#define ll long long
namespace fr{
	int read()
	{
		int x=0,flag=1;
		char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')flag=-1;
		for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
		return x*flag;
	}
}
using namespace fr;
const int N = 1e5+5;
const int M = 1e6+6;
struct node{
	int u,v,w;
}all[M],a[N]; 
int c[20];
int tot;
bool cmp(node a,node b){
	return a.w<b.w;
}
int f[N];
int n,m,k;
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]); 
}
int sz[N];
int val[12][N];
void fresh(int n)
{
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
}
void merge(int x,int y)
{
//	x=find(x),y=find(y);
//	if(x==y)return;
	if(sz[x]>sz[y])swap(x,y);
	f[x]=y;sz[y]+=sz[x];	
}
ll ans;
void pre()
{
	fresh(n);
	sort(all+1,all+1+m,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int u=all[i].u,v=all[i].v,w=all[i].w;
		u=find(u),v=find(v);
		if(u==v)continue;
		merge(u,v);
		ans+=w;cnt++;
		a[++tot]=all[i];
		if(cnt==n-1)break;
	}
}
node Now[N*2];
int ntot=0;
void solve(int S)
{
	ntot=0;
//	cerr<<S<<":"<<endl;
	ll res=0;
	int idx=1;
	int nown=n;
	fresh(n+10);
	for(int i=1;i<=tot;i++)Now[++ntot]=a[i];
	while(S)
	{
		if(S&1)
		{
			res+=c[idx];
			++nown;
			for(int i=1;i<=n;i++)
			{
				Now[++ntot]={n+idx,i,val[idx][i]};
			}	
		}
		S>>=1;
		++idx;
	}
//	cerr<<res<<endl;
	sort(Now+1,Now+1+ntot,cmp);
	for(int i=1;i<=ntot;i++)
	{
		int u=Now[i].u,v=Now[i].v,w=Now[i].w;
	//	cerr<<u<<" "<<v<<" "<<w<<endl;
	}
//	cerr<<"nown"<<nown<<endl;
	int cnt=0;
	for(int i=1;i<=ntot;i++)
	{
		int u=Now[i].u,v=Now[i].v,w=Now[i].w;
	//	cerr<<"choi"<<u<<" "<<v<<" "<<w<<endl;
		u=find(u),v=find(v);
	//	cerr<<u<<" "<<v<<endl;
		if(u==v)continue;
		++cnt;
		res+=w;
		merge(u,v);
		if(cnt==nown-1)break;
	}
	ans=min(ans,res);tot=n-1;
//	cerr<<res<<endl;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	int st=clock();
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		all[i].u=read();all[i].v=read();all[i].w=read();
	}
	
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)val[i][j]=read();
	}
	pre();//cerr<<"!"<<ans<<endl;
//	cerr<<"is"<<endl;
	for(int i=1;i<=(1<<k)-1;i++)solve(i);
	cout<<ans<<endl; 
//	int ed=clock();
//	cerr<<"\ntime:"<<ed-st<<"ms"<<endl;
	return 0;
}

