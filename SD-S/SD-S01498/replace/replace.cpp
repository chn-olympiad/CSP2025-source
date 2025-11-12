//by OldDriverTree
#include<bits/stdc++.h>
#define range(vec) vec.begin(),vec.end()
#define tup array<int,3>
#define P pair<int,int>
#define mid (l+r>>1)
using namespace std;
const int N=2.5e6+2,M=2e5;
int n,m,k,a[M],b[M];
vector<tup> Q[N];
long long ans[M];

int read() {
	int x=0; bool f=true; char c=0;
	while (!isdigit(c) ) f&=(c!='-'),c=getchar();
	while (isdigit(c) ) x=x*10+(c&15),c=getchar();
	return f?x:-x;
}
struct ACAM
{
	int dep[N],L[N],R[N];
	int tot,fa[N][22];
	vector<int> g[N];
	int T[N][26];
	int insert(string s)
	{
		int rt=0;
		for (char c:s) {
			int &p=T[rt][c-'a'];
			if (!p) dep[p=++tot]=dep[rt]+1;
			rt=p;
		}
		return rt;
	}
	void dfs(int u) {
		for (int i=1;i<=k;i++) fa[u][i]=fa[fa[u][i-1] ][i-1];
		L[u]=++tot; for (int v:g[u]) dfs(v); R[u]=tot;
	}
	int get(int x,int y) {
		for (int i=k;~i;i--)
		if (~fa[x][i]&&dep[fa[x][i] ]>=y)
		x=fa[x][i]; return fa[x][0];
	}
	void build()
	{
		queue<int> q; for (int i=0;i<26;i++)
		if (T[0][i]) q.push(T[0][i]);
		while (!q.empty() ) {
			int u=q.front(); q.pop(); for (int i=0;i<26;i++)
			if (T[u][i]) fa[T[u][i] ][0]=T[fa[u][0] ][i],
			q.push(T[u][i]); else T[u][i]=T[fa[u][0] ][i];
		}
		for (int i=1;i<=tot;i++) g[fa[i][0] ].push_back(i);
		for (int i=0;i<=k;i++) fa[0][i]=-1; tot=0,dfs(0);
	}
}A,B;

namespace DS
{
	const int B=40;
	int a[N],b[N],c[N],d[N];
	void add(int x,int y) {
		for (int i=0;i<x/B/B/B;i++) a[i]+=y;
		for (int i=x/B/B/B*B;i<x/B/B;i++) b[i]+=y;
		for (int i=x/B/B*B;i<x/B;i++) c[i]+=y;
		for (int i=x/B*B;i<=x;i++) d[i]+=y;
	}
	int query(int x) {
		return a[x/B/B/B]+b[x/B/B]+c[x/B]+d[x];
	}
}
main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0),cin>>n>>m;
	for (int i=0;i<n;i++) {
		string s,t; cin>>s>>t;
		k=max(k,(int)s.size() );
		a[i]=A.insert(s),b[i]=B.insert(t);
	}
	k=__lg(k),A.build(),B.build();
	for (int i=0;i<n;i++) {
		int l=A.L[a[i] ],r=A.R[a[i] ];
		int s=B.L[b[i] ],t=B.R[b[i] ];
		Q[l].push_back({s-1,-1,-1});
		Q[l].push_back({t,-1,1});
		Q[r+1].push_back({s-1,-1,1});
		Q[r+1].push_back({t,-1,-1});
	}
	for (int _=0;_<m;_++)
	{
		string s,t; cin>>s>>t,n=s.size();
		int l=0,r=n-1,p=0,q=0; if (n!=t.size() ) continue;
		while (l<n&&s[l]==t[l]) l++; while (~r&&s[r]==t[r]) r--;
		for (int i=0;i<r;i++) p=A.T[p][s[i]-'a'],q=B.T[q][t[i]-'a'];
		for (int i=r;i<n;i++) {
			p=A.T[p][s[i]-'a'],q=B.T[q][t[i]-'a'];
			if (A.dep[p]<i-l+1||B.dep[q]<i-l+1) continue;
			int fp=A.get(p,i-l+1),fq=B.get(q,i-l+1);
			Q[A.L[p] ].push_back({B.L[q],_,1});
			if (~fq) Q[A.L[p] ].push_back({B.L[fq],_,-1});
			if (~fp) Q[A.L[fp] ].push_back({B.L[q],_,-1});
			if (~fp&&~fq) Q[A.L[fp] ].push_back({B.L[fq],_,1});
		}
	}
	for (int i=1;i<=A.tot;i++) for (tup o:Q[i])
	if (~o[1]) ans[o[1] ]+=o[2]*DS::query(o[0]);
	else DS::add(o[0],o[2]);
	for (int i=0;i<m;i++)
	printf("%lld\n",ans[i]);
	return 0;
}
/*
有可能是题，但是题不太可能 
枚举替换的右端点 
考虑对 s1 和 s2 分别建 AC 自动机，不难转成二维数点
每次查询在 A 树上一条路径，B 树上一条路径的个数
需要跑 4n 次单点加，2L2 次查询 
8e5,1e7，值域分块 
但这是提高组 
事已至此，先开 T4 吧  
17:25 左右写完了 
18:00 过了所有大样例，但是样例 4 跑了 1.4s
事已至此，先写 T4 吧  
*/
