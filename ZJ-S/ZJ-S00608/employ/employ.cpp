#define plus_cat "employ"
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
constexpr int N(500+10);

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

namespace Modular {
#define Mod 998'244'353
	int add(int a,int b) { return a+b>=Mod?a+b-Mod:a+b; }
	int sub(int a,int b) { return a-b<0?a-b+Mod:a-b; }
	int mul(int a,int b) { return (ll)a*b%Mod; }
	int &toadd(int &a,int b) { return a=add(a,b); }
	int &tosub(int &a,int b) { return a=sub(a,b); }
	int &tomul(int &a,int b) { return a=mul(a,b); }
} using namespace Modular;

char s[N];
int n,m,tot,ans;
int c[N],p[N];

namespace Sub2 {
	constexpr int N(18+10),St(1<<18|10);
	int U;
	int cnt[St];
	int f[St][N];

	bool Check() { return n<=18; }

	int Main() {
		/*DE("Init");*/
		U=(1<<n)-1;
		FOR(S,1,U)cnt[S]=cnt[S>>1]+(S&1);
		/*DE("DP");*/
		f[0][0]=1;
		FOR(S,0,U)FOR(i,0,n)if(f[S][i])FOR(j,1,n)if(!(S&1<<(j-1))) {
			bool val(cnt[S]-i<c[j]&&s[cnt[S]+1]!='0');
			toadd(f[S|1<<(j-1)][i+val],f[S][i]);
		}
		/*DE("Count");*/
		FOR(i,m,n)toadd(ans,f[U][i]);
		/*DE("Output");*/
		printf("%d\n",ans);
		return 0;
	}
}

int main() {
#ifdef plus_cat
	freopen(plus_cat ".in","r",stdin);
	freopen(plus_cat ".out","w",stdout);
#endif // plus_cat
	/*DE("Input");*/
	scanf("%d%d%s",&n,&m,s+1);
	FOR(i,1,n)scanf("%d",&c[i]);
	/*DE("Subs");*/
	if(Sub2::Check())return Sub2::Main();
	return 0;
}