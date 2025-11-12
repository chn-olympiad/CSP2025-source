#include<bits/stdc++.h>
#define int long long
using namespace std;
bool Beginning;

#define mp(x,y) make_pair(x,y)
#define PII pair<int,int>
#define se second
#define fi first

namespace Memory_Love{
	int read(){ int x=0; bool flag=1; char ch=getchar();
		while(ch<'0' || ch>'9'){if(ch=='-') flag=0;ch=getchar();}
		while(ch>='0' && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
		return (flag? x:-x);}
	void write(long long x,char ch=0){ if(x<0) x=-x,putchar('-');
		static short s[35],top=-1; do{s[++top]=x%10;x/=10;}while(x);
		while(~top) putchar(s[top--]+48); if(ch) putchar(ch);}
	int gcd(int a,int b){return (b==0? a:gcd(b,a%b));}
	int lcm(int a,int b){return a/gcd(a,b)*b;}
	int ksm(int a,int b,int p){int ans=1%p;while(b){if(b&1) ans=ans*a%p;a=a*a%p,b>>=1;}return ans;}
	int exgcd(int a,int b,int &x,int &y){if(!b){x=1,y=0; return a;}int d=exgcd(b,a%b,y,x);y-=a/b*x;return d;}
} using namespace Memory_Love;
const int N=1e4+100,M=1e6+100;
const long long INF=0x3f3f3f3f3f3f3f3fll;
int n,m,K,NowN,NowM; long long Answer=INF;

//namespace Graph{
//	int head[N],tot_edge; struct edge{int v,w,next;}e[N*15];
//	void G_init(int Num){for(int i=1;i<=Num;i++) head[i]=-1;tot_edge=-1;}
//	void add(int u,int v,int w){e[++tot_edge]=(edge){v,w,head[u]};head[u]=tot_edge;}
//} using namespace Graph;

struct DSU
{
	int father[N],SIZE[N];
	void init(int n)
	{
		for(int i=1;i<=n;i++) father[i]=i;
		for(int i=1;i<=n;i++) SIZE[i]=1;
	}
	int find(int x)
	{
		if(x==father[x]) return x;
		return father[x]=find(father[x]);
	}
	void Merge(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return ;
		if(SIZE[x]>SIZE[y]) swap(x,y);
		father[x]=y,SIZE[y]+=SIZE[x];
	}
	bool Same(int x,int y)
	{
		return find(x)==find(y);
	}
}Dsu;

struct SPNode
{
	int A[N],Cost;
}a[15];

struct Edge
{
	int u,v,w;
	bool friend operator <(const Edge &a,const Edge &b)
	{
		return a.w<b.w;
	}
}E[M],G[M],Have[N];

long long KruskalStart()
{
	int i,cnt=0,u,v; long long ans=0;
	sort(E+1,E+1+m); Dsu.init(n);
	for(i=1;i<=m;i++)
	{
		u=E[i].u,v=E[i].v;
		if(Dsu.Same(u,v)) continue;
		Have[++cnt]=E[i],ans+=E[i].w;
		Dsu.Merge(u,v);
	}
	return ans;
}

long long KruskalDoing(int n,int m,long long ans)
{
	int i,cnt=0,u,v;
	sort(G+1,G+1+m); Dsu.init(n);
	for(i=1;i<=m;i++)
	{
		u=G[i].u,v=G[i].v;
		if(Dsu.Same(u,v)) continue;
		cnt++,ans+=G[i].w;
		Dsu.Merge(u,v);
		if(ans>Answer) return INF;
	}
	return ans;
}

bool Ending;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road3.in","r",stdin);
	int i,j; long long NowAns; n=read(),m=read(),K=read();
	for(i=1;i<=m;i++) E[i].u=read(),E[i].v=read(),E[i].w=read();
	Answer=KruskalStart(); //cerr<<Answer<<'\n';
	for(i=1;i<=K;i++)
	{
		a[i].Cost=read();
		for(j=1;j<=n;j++) a[i].A[j]=read();
	}
	for(int S=0;S<(1<<K);S++)
	{
		for(i=1,NowM=0;i<n;i++) G[++NowM]=Have[i];
		for(i=1,NowN=n,NowAns=0;i<=K;i++)
		{
			if((S>>(i-1)&1))
			{
				NowN++,NowAns+=a[i].Cost;
				for(j=1;j<=n;j++) G[++NowM]=(Edge){NowN,j,a[i].A[j]};
			}
		}
		Answer=min(Answer,KruskalDoing(NowN,NowM,NowAns));
	}
	write(Answer,'\n');
	cerr<<"\nused "<<(abs(&Ending-&Beginning)/1048576)<<" MB\n";
	return 0;
}
