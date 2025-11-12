#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define lc (u<<1)
#define rc (u<<1|1)
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define sed second
#define Min(a,b) ((a)>(b)?(a)=(b):1)
#define Max(a,b) ((a)<(b)?(a)=(b):1)
using namespace std;
const int N=2e4+10,M=1e6+10,K=11,inf=1e18;
bool MS;int uesd,id;
int u[M],v[M],w[M];
int f[N];
pii val[K][N];
int c[K];
int n,m,k;
void init()
{
	rep(i,1,n+k)f[i]=i;
}
int fa(int x){return f[x]==x?x:f[x]=fa(f[x]);}
void merge(int u,int v){f[fa(u)]=fa(v);}
struct vl
{
	int u,v,w;
	bool operator<(const vl&b)const
	{
		return w<b.w;
	}
};
vector<vl>E[1<<10];//关键边 
inline void update(int now,vl s,int&res)
{
	int u=s.u;
	int v=s.v;
	int w=s.w;
	if(fa(u)!=fa(v))
	{
		merge(u,v);
		res+=w;
		E[now].pb(vl{u,v,w});
	}
}
int sol(int now,int lst,int imp)
{
	int res=0;
	init();
//	cout<<"_________\n";
	int pos=1;
	for(auto s:E[lst])
	{
		while(pos<=n&&val[imp][pos].fst<=s.w)
		{
//		cerr<<val[imp][pos].sed<<" "<<imp+n<<" "<<val[imp][pos].fst<<'\n';
			update(now,vl{val[imp][pos].sed,imp+n,val[imp][pos].fst},res);
			pos++;
		}
//		cerr<<s.u<<"|"<<s.v<<" "<<s.w<<'\n';
		update(now,s,res);
//		cerr<<res<<'\n';
	}
	return res;
}
int initial()
{
	int res=0;
	vector<vl>edge;
	rep(i,1,m)
	edge.pb(vl{u[i],v[i],w[i]});
	sort(edge.begin(),edge.end());
	init();
	for(auto s:edge)
	{
		int u=s.u;
		int v=s.v;
		int w=s.w;
		if(fa(u)==fa(v))continue;
		else
		{
			merge(u,v);
			res+=w;
			E[0].pb(vl{u,v,w});
		}
	}
	return res;
}
bool MT;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	rep(i,1,m)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	rep(i,0,(1<<k)-1)
	E[i].reserve(n+k+10);
	rep(i,1,k)
	{
		cin>>c[i];
		rep(j,1,n)
		cin>>val[i][j].fst,val[i][j].sed=j;
		sort(val[i]+1,val[i]+n+1);
	}
	int ans=initial(); 
	rep(i,1,(1<<k)-1)
	{
		int res=0;
		vector<int>vec;
		int lst=(i-(i&(-i)));
		rep(j,1,k)
		if((1<<j-1)&i)res+=c[j];
		int imp=0;
		rep(j,1,k)
		if((1<<j-1)&i)
		{imp=j;break;}
//		cout<<lst<<" "<<imp<<" "<<res<<'\n';
		Min(ans,sol(i,lst,imp)+res);
	}
	cout<<ans<<'\n';
	cerr<<"Memory:"<<(&MS-&MT)/1048576.0<<"MB Time"<<clock()<<"ms\n";
}
/*
一个类似生成树的问题

不过有辅助点，

一个朴素的想法是首先枚举那些点要用，然后做一遍MST

这是显然的，因为你都枚举哪些点了，所以一定会的。

显然不能通过，复杂度是 $O(2^km\log m)$ 的。

欸真的吗

感觉，诈骗啊，就我们首先把这些边都丢到一起排序，然后每次枚举的时候无非就是多考虑一下这条边能不能选。

哦哦，感谢lyj赛前的指导

这里考虑将k的空集领出来建MST，考虑此时不在MST上的边，此后在加入其他边之后都不会是新的边。

并且可以拓展到全局上，复杂度可以做到 $O(n2^ka(n))$，完全可以通过。

结论大概是真的，决策是先看后边的题

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4



*/