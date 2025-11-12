#define plus_cat "replace"
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define VH vector<Hash>
#define ull unsigned long long
#define RCL(a,b,c,d) memset(a,b,sizeof(c)*(d))
#define tomin(a,...) ((a)=min({(a),__VA_ARGS__}))
#define tomax(a,...) ((a)=max({(a),__VA_ARGS__}))
#define FOR(i,a,b) for(int i(a); i<=(int)(b); ++i)
#define DOR(i,a,b) for(int i(a); i>=(int)(b); --i)
#define EDGE(g,i,x,y) for(int i(g.h[x]),y(g[i].v); ~i; y=g[(i=g[i].nxt)].v)
using namespace std;
constexpr int N(2e5+10),L(5e6+10);

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

namespace Hashs {
	constexpr int P(1e9+9);
	struct Hash {
		ull a;
		int b;
		Hash(ull a=0,int b=0):a(a),b(b) {}

		friend Hash operator +(Hash A,Hash B) {
			return Hash(A.a+B.a,A.b+B.b>=P?A.b+B.b-P:A.b+B.b);
		}

		friend Hash operator -(Hash A,Hash B) {
			return Hash(A.a-B.a,A.b-B.b<0?A.b-B.b+P:A.b-B.b);
		}

		friend Hash operator *(Hash A,Hash B) {
			return Hash(A.a*B.a,(ll)A.b*B.b%P);
		}

		friend bool operator ==(Hash A,Hash B) {
			return A.a==B.a&&A.b==B.b;
		}

		friend bool operator !=(Hash A,Hash B) {
			return A.a!=B.a||A.b!=B.b;
		}

		friend bool operator <(Hash A,Hash B) {
			return A.a^B.a?A.a<B.a:A.b<B.b;
		}
	} pw[L];
	const Hash B(13331,131);

	void Init(const int n=L-5) {
		pw[0]=Hash(1,1);
		FOR(i,1,n)pw[i]=pw[i-1]*B;
	}

	void Constr(string &s,VH &h) {
		int len(s.size()-1);
		h=vector<Hash>(s.size(),Hash(0,0));
		FOR(i,1,len)h[i]=h[i-1]*B+Hash(s[i],s[i]);
	}

	Hash Query(VH &h,int l,int r) {
		if(l>r)return Hash(0,0);
		return h[r]-h[l-1]*pw[r-l+1];
	}

	Hash Replace(VH &h,VH &g,int l) {
		int len(h.size()-1),_len(g.size()-1);
		Hash tmp(0,0);
		tmp=tmp+Query(h,1,l-1)*pw[len-(l-1)];
		tmp=tmp+g.back()*pw[len-(l+_len-1)];
		tmp=tmp+Query(h,l+_len,len);
//		DE(l,len,_len,tmp.a,tmp.b);
		return tmp;
	}
} using namespace Hashs;

char c[L];
int n,Q,L1,L2;
int len[N];
string s[N][2],t[N][2];
VH S[N][2],T[N][2];

void Input_S(int &len,string &s) {
	scanf("%s",c+1),len=strlen(c+1),s+=' ';
	FOR(i,1,len)s+=c[i];
}

namespace Sub2 {
	bool Check() { return n<=1000&&L1<=2000&&L2<=2000; }

	ll _Query(string t[2],VH T[2]) {
		if(t[0].size()!=t[1].size())return 0;
		int Len(t[0].size()-1);
		ll ans(0);
		FOR(i,1,n)FOR(j,1,Len-len[i]+1) {
			if(Query(T[0],j,j+len[i]-1)!=S[i][0].back())
				continue;
//			DE(i,j);
			if(Replace(T[0],S[i][1],j)!=T[1].back())
				continue;
//			DE(i,j);
			++ans;
		}
		return ans;
	}

	int Main() {
		/*DE("Query");*/
		FOR(i,1,Q)printf("%lld\n",_Query(t[i],T[i]));
		return 0;
	}
}

namespace Sub {
	int idx[N],fa[N],dep[N];
	unordered_map<ull,int> pos;

	ull que(VH T[2],int l,int r) {
		ull L(Query(T[0],l,r).a),R(Query(T[1],l,r).a);
		return L*13331+R;
	}

	ll _Query(string t[2],VH T[2]) {
		if(t[0].size()!=t[1].size())return 0;
		int Len(t[0].size()-1),L(INF),R(-INF);
		ll ans(0);
		FOR(i,1,Len)if(t[0][i]!=t[1][i])tomin(L,i),tomax(R,i);
		FOR(i,R,Len) {
			if(!pos.count(que(T,L,i)))continue;
			int res(L);
			for(int l(1),r(L),mid((l+r)>>1); l<=r; mid=(l+r)>>1)
				pos.count(que(T,mid,i))?res=mid,r=mid-1:l=mid+1;
			int u(pos[que(T,res,i)]);
			if(que(T,res,i)!=que(S[u],1,len[u]))u=fa[u];
			int v(pos[que(T,L,i)]);
			v=fa[v];
			ans+=dep[u]-dep[v];
		}
		return ans;
	}

	int Main() {
		/*DE("Build");*/
		FOR(i,1,n)idx[i]=i;
		sort(idx+1,idx+n+1,[](int a,int b) {
			return len[a]>len[b];
		});
		FOR(i,1,n) {
			int u(idx[i]);
			FOR(j,1,len[u]) {
				int v(0);
				ull w(que(S[u],j,len[u]));
				if(pos.count(w))v=pos[w],fa[v]=u;
				pos[w]=u;
			}
		}
		DOR(i,n,1) {
			int u(idx[i]);
			dep[u]=dep[fa[u]]+1;
		}
		pos.clear();
		FOR(i,1,n) {
			int u(idx[i]);
			FOR(j,1,len[u]) {
				int v(0);
				ull w(que(S[u],j,len[u]));
				if(pos.count(w))v=pos[w],fa[v]=u;
				if(len[u]!=len[v])pos[w]=u;
			}
		}
		/*DE("Query");*/
		FOR(i,1,Q)printf("%lld\n",_Query(t[i],T[i]));
		return 0;
	}
}

int main() {
#ifdef plus_cat
	freopen(plus_cat ".in","r",stdin);
	freopen(plus_cat ".out","w",stdout);
#endif // plus_cat
	/*DE("Input");*/
	scanf("%d%d",&n,&Q),Init();
	FOR(i,1,n)FOR(j,0,1)
		Input_S(len[i],s[i][j]),Constr(s[i][j],S[i][j]);
	FOR(i,1,Q)FOR(j,0,1) {
		int len(0);
		Input_S(len,t[i][j]),Constr(t[i][j],T[i][j]);
	}
	/*DE("Subs");*/
	FOR(i,1,n)FOR(j,0,1)L1+=len[i];
	FOR(i,1,Q)FOR(j,0,1)L2+=t[i][j].size()-1;
	if(Sub2::Check())return Sub2::Main();
	return Sub::Main();
}