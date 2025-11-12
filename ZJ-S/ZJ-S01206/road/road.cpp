#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fi first
#define se second
#define endl '\n'
#define start_multitest\
	int tests;\
	cin>>tests;\
	for(int test_case=1;test_case<=tests;test_case++)[&]()->int\
	{
#define end_multitest\
		return 0;\
	}();
template<typename val_t>
struct discretizer
{
	int ptr;
	val_t Val[200010];
	void insert(val_t v)
	{
		Val[++ptr]=v;
	}
	size_t size()
	{
		return ptr;
	}
	void discretize()
	{
		sort(Val+1,Val+ptr+1);
		ptr=unique(Val+1,Val+ptr+1)-Val-1;
	}
	int get(val_t v)
	{
		return lower_bound(Val+1,Val+ptr,v)-Val;
	}
	val_t val(int x)
	{
		return Val[x];
	}
};
constexpr int bufsize=1000000;
char Buf[bufsize<<1];
int p1,p2;
inline char gc()
{
	if(p1==p2)p2=fread(Buf,1,bufsize,stdin),p1=0;
	return Buf[p1++];
}
template<typename _Tp>
inline void read(_Tp &x)
{
	x=0;
	char ch;
	for(ch=gc();!isdigit(ch);ch=gc());
	for(;isdigit(ch);ch=gc())x=x*10+ch-48;
}
constexpr int N=10010,K=12,V=110010;
int n,m,k,v;
ll sum,ans;
discretizer<int>D;
int C[N],A[K][N];
struct edge_t
{
	int x,y,w;
	friend bool operator<(const edge_t &x,const edge_t &y)
	{
		return x.w<y.w;
	};
};
vector<edge_t>Edges,Used;
int Fa[N];
inline int find(int x)
{
	return Fa[x]==x?x:Fa[x]=find(Fa[x]);
}
vector<pair<int,int>>Vec[V];
void linear_sort()
{
	for(int i=1;i<=v;i++)Vec[i].clear();
	for(edge_t e:Edges)Vec[e.w].push_back({e.x,e.y});
	Edges.clear();
	for(int i=1;i<=v;i++)
		for(auto j:Vec[i])
			Edges.push_back({j.fi,j.se,i});
}
void find_used()
{
	sort(Edges.begin(),Edges.end());
	iota(Fa+1,Fa+n+1,1);
	for(edge_t e:Edges)
	{
		int fx=find(e.x),fy=find(e.y);
		if(fx==fy)continue;
		Used.push_back(e);
		sum+=e.w;
		Fa[fy]=fx;
	}
}
void Kruskal(int n)
{
	linear_sort();
	iota(Fa+1,Fa+n+1,1);
	for(edge_t e:Edges)
	{
		int fx=find(e.x),fy=find(e.y);
		if(fx==fy)continue;
		sum+=D.val(e.w);
		Fa[fy]=fx;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		read(x);read(y);read(w);
		Edges.push_back({x,y,w});
	}
	for(int i=1;i<=k;i++)
	{
		read(C[i]);
		for(int j=1;j<=n;j++)read(A[i][j]),D.insert(A[i][j]);
	}
	Used.reserve(n-1);
	find_used();
	for(edge_t e:Used)D.insert(e.w);
	D.discretize();
	v=D.size();
	for(edge_t &e:Used)e.w=D.get(e.w);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			A[i][j]=D.get(A[i][j]);
	ans=sum;
	for(int i=0;i<1<<k;i++)
	{
		Edges=Used;
		Edges.reserve(n-1+k*n);
		sum=0;
		for(int j=1;j<=k;j++)
			if(i>>(j-1)&1)
			{
				sum+=C[j];
				for(int k=1;k<=n;k++)
					Edges.push_back({k,n+j,A[j][k]});
			}
		Kruskal(n+k);
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}