#include <bits/stdc++.h>

using namespace std;

namespace my_std{
	#define fi first
	#define se second
	#define sz(a) ((int)((a).size()))
	#define pb emplace_back
	#define rep(i,a,b) for(int i=(a);i<=(b);++i)
	using LL = long long;
	template<class T> void Abs(T &x){
		x=x>0?x:-x;
	}
	template<class T1,class T2> void chkmx(T1 &x,T2 y){
		x=x>y?x:y;
	}
	template<class T1,class T2> void chkmn(T1 &x,T2 y){
		x=x<y?x:y;
	}
	using lf = double;
	using pii = pair<int,int>;
	template<class T1,class T2> pair<int,int> cp(T1 x,T2 y){
		return make_pair(x,y);
	}
	template<class T1,class T2> istream& operator >>(istream& in,pair<T1,T2> &A){
		return in>>A.fi>>A.se;
	}
	template<class T1,class T2> ostream& operator <<(ostream& ot,pair<T1,T2> A){
		return ot<<'('<<A.fi<<','<<A.se<<')';
	}
	using tpl = tuple<int,int,int>;
	template<class T1,class T2,class T3> ostream& operator <<(ostream& ot,tuple<T1,T2,T3> A){
		return ot<<'('<<get<0>(A)<<','<<get<1>(A)<<','<<get<2>(A)<<')';
	}	
	using vi = vector<int>;
	using vl = vector<LL>;
	template<class T> ostream& operator <<(ostream& ot,vector<T> A){
		size_t Size=sz(A);
		ot<<'[';
		rep(i,0,Size-1){
			if(i) ot<<',';
			ot<<A[i];
		}
		ot<<']';
		return ot;
	}
	void Ios(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
	}
	template<class... Args>
	void Print(Args... args){
		int count=0;
		((cerr << (count++ ? "," : "") << args), ...);
	}
	#ifdef DEBUG
		#define Debug(...) \
				cerr << "@: " << __func__ << " #:" << __LINE__ << " ["; \
				Print(#__VA_ARGS__); \
				cerr << "] = {"; \
				Print(__VA_ARGS__); \
				cerr << "}\n";
	#else
		#define Debug(...) void(0)
	#endif						
}
using namespace my_std;

const int N = 10+1;

int n,m;
char s[N];
int c[N];

int cala(vi p){
	int js=0;
	int i=1;
	for(int j : p){
		if(s[i]=='0' or js>=c[j]){
			++js;
		}
		++i;
	}
	Debug(p,n-js);
	return n-js;
}

signed main(){
	string __name = "employ";
	if(__name!=""){
		freopen((__name+".in").c_str(),"r",stdin);
		freopen((__name+".out").c_str(),"w",stdout);
	}
	Ios();
	cin>>n>>m;
	rep(i,1,n){
		cin>>s[i];
	}
	rep(i,1,n){
		cin>>c[i];
	}
	vi p;
	rep(i,1,n){
		p.pb(i);
	}
	int ans=0;
	do{
		ans+=(cala(p)>=m);
	}while(next_permutation(p.begin(),p.end()));
	cout<<ans<<"\n";
}