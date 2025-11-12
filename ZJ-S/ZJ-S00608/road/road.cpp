#define plus_cat "road"
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define RCL(a,b,c,d) memset(a,b,sizeof(c)*(d))
#define tomin(a,...) ((a)=min({(a),__VA_ARGS__}))
#define tomax(a,...) ((a)=max({(a),__VA_ARGS__}))
#define FOR(i,a,b) for(int i(a); i<=(int)(b); ++i)
#define DOR(i,a,b) for(int i(a); i>=(int)(b); --i)
#define EDGE(g,i,x,y) for(int i(g.h[x]),y(g[i].v); ~i; y=g[(i=g[i].nxt)].v)
using namespace std;
constexpr int N(1e4+20),M(1e6+10),K(10+3);

namespace IOEcat {
#define gc() getchar()
#define pc(c) putchar(c)
#define DE(...) E(#__VA_ARGS__,__VA_ARGS__)
#define isD(c) ('0'<=(c)&&(c)<='9')
	struct Icat {
		template<class T>void operator ()(T &a) {
			static bool sign(false);
			static char ch(0);
			a=0,sign=0;
			while(ch=gc(),!isD(ch))if(ch=='-')sign=true;
			do a=(a<<1)+(a<<3)+(ch^48);
			while(ch=gc(),isD(ch));
			if(sign)a=-a;
		}

		template<class T,class...Types>void operator ()(T &a,Types &...args) {
			return (*this)(a),(*this)(args...);
		}
	} I;
	struct Ocat {
		template<class T>void operator ()(T a,const char lst) {
			static short top(0);
			static char st[50];
			if(a<0)pc('-'),a=-a;
			do st[++top]=a%10^48,a/=10;
			while(a);
			while(top)pc(st[top--]);
			pc(lst);
		}

		template<class T,class...Types>void operator ()(T a,const char lst,Types ...args) {
			return (*this)(a,lst),(*this)(args...);
		}
	} O;
	struct Ecat {
		template<class T>void operator ()(const char *fmt,T a) { cerr<<fmt<<':'<<a<<".\n"; }

		template<class T,class...Types>void operator ()(const char *fmt,T a,Types...args) {
			while(*fmt^',')cerr<<*fmt++;
			return cerr<<':'<<a<<", ",(*this)(++fmt,args...);
		}
	} E;
} using namespace IOEcat;

int n,m,k;
int c[K];
int a[K][N];
struct edge {
	int u,v,w;

	void Input() { scanf("%d%d%d",&u,&v,&w); }

	friend bool operator <(edge a,edge b) { return a.w<b.w; }
} e[M];
struct DSU {
	int fa[N];

	void Init(int n) { FOR(i,1,n)fa[i]=i; }

	int get(int x) { return fa[x]^x?fa[x]=get(fa[x]):x; }

	void merge(int u,int v) { fa[get(u)]=get(v); }
} dsu;

namespace Sub1 {
	ll ans;

	bool Check() { return !k; }

	int Main() {
		/*DE("Solve");*/
		FOR(i,1,m)ans+=e[i].w;
		/*DE("Output");*/
		O(ans,'\n');
		return 0;
	}
}

namespace Sub9 {
	bool cho[K];
	ll ans;

	bool Check() { return true||n<=1000||k<=5; }

	ll Solve(ll sum) {
		dsu.Init(n+k);
		FOR(i,1,m)if(e[i].u<=n||cho[e[i].u-n])
			if(dsu.get(e[i].u)!=dsu.get(e[i].v)) {
				sum+=e[i].w,dsu.merge(e[i].u,e[i].v);
				if(sum>ans)return sum;
			}
		return sum;
	}

	void dfs(int u,ll sum) {
		if(sum>ans)return;
		if(u>k)return tomin(ans,Solve(sum)),void();
		cho[u]=false,dfs(u+1,sum);
		cho[u]=true,dfs(u+1,sum+c[u]);
		cho[u]=false;
	}

	int Main() {
		/*DE("Init");*/
		FOR(i,1,k)FOR(j,1,n)e[++m]= {n+i,j,a[i][j]};
		sort(e+1,e+m+1);
		/*DE("DFS");*/
		ans=LINF,dfs(1,0);
		/*DE("Output");*/
		O(ans,'\n');
		return 0;
	}
}

int main() {
#ifdef plus_cat
	freopen(plus_cat ".in","r",stdin);
	freopen(plus_cat ".out","w",stdout);
#endif // plus_cat
	/*DE("Input");*/
	I(n,m,k);
	FOR(i,1,m)e[i].Input();
	FOR(i,1,k) {
		I(c[i]);
		FOR(j,1,n)I(a[i][j]);
	}
	sort(e+1,e+m+1);
	/*DE("Init");*/
	dsu.Init(n);
	int tmp(0);
	FOR(i,1,m)if(dsu.get(e[i].u)!=dsu.get(e[i].v))
		e[++tmp]=e[i],dsu.merge(e[i].u,e[i].v);
	m=tmp;
	/*DE("Subs");*/
	if(Sub1::Check())return Sub1::Main();
	if(Sub9::Check())return Sub9::Main();
	return 0;
}