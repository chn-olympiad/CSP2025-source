#define plus_cat "club"
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define RCL(a,b,c,d) memset(a,b,sizeof(c)*(d))
#define tomin(a,...) ((a)=min({(a),__VA_ARGS__}))
#define tomax(a,...) ((a)=max({(a),__VA_ARGS__}))
#define FOR(i,a,b) for(int i(a); i<=(int)(b); ++i)
#define DOR(i,a,b) for(int i(a); i>=(int)(b); --i)
#define EDGE(g,i,x,y) for(int i(g.h[x]),y(g[i].v); ~i; y=g[(i=g[i].nxt)].v)
using namespace std;
constexpr int N(1e5+10);

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

int Cas,n,lim;
int cnt[3];
int a[N][3];
ll ans;

namespace Sub1 {
	constexpr int N(10+10);

	bool Check() { return n<=10; }

	void dfs(int u,ll sum) {
		if(u>n) {
			tomax(ans,sum);
			return;
		}
		if(cnt[0]<(n>>1))++cnt[0],dfs(u+1,sum+a[u][0]),--cnt[0];
		if(cnt[1]<(n>>1))++cnt[1],dfs(u+1,sum+a[u][1]),--cnt[1];
		if(cnt[2]<(n>>1))++cnt[2],dfs(u+1,sum+a[u][2]),--cnt[2];
	}

	int Main() {
		/*DE("DFS");*/
		dfs(1,0);
		/*DE("Output");*/
		O(ans,'\n');
		return 0;
	}
}

namespace Sub {
	int id;
	int d[N],del[N];

	int Main() {
		/*DE("Choose");*/
		FOR(i,1,n) {
			int mx(max({a[i][0],a[i][1],a[i][2]}));
			ans+=mx;
			if(a[i][0]==mx)d[i]=0;
			else if(a[i][1]==mx)d[i]=1;
			else d[i]=2;
			++cnt[d[i]];
		}
		/*DE("Check");*/
		id=-1;
		if(cnt[0]>lim)id=0;
		if(cnt[1]>lim)id=1;
		if(cnt[2]>lim)id=2;
		if(~id) {
			int tot(0);
			FOR(i,1,n)if(d[i]==id) {
				int mx(0);
				FOR(j,0,2)if(j!=id)tomax(mx,a[i][j]);
				del[++tot]=a[i][d[i]]-mx;
			}
			sort(del+1,del+tot+1);
			FOR(i,1,cnt[id]-lim)ans-=del[i];
		}
		/*DE("Output");*/
		O(ans,'\n');
		return 0;
	}
}

int Main() {
	/*DE("Input");*/
	I(n),lim=(n>>1);
	FOR(i,1,n)FOR(j,0,2)I(a[i][j]);
	/*DE("Subs");*/
	if(Sub1::Check())return Sub1::Main();
	return Sub::Main();
}

int main() {
#ifdef plus_cat
	freopen(plus_cat ".in","r",stdin);
	freopen(plus_cat ".out","w",stdout);
#endif // plus_cat
	for(I(Cas); Cas; --Cas) {
		Main();
		/*DE("Clear");*/
		ans=0;
		FOR(j,0,2)cnt[j]=0;
	}
	return 0;
}