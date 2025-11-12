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

const int N = 2e5+1;
const int Mod = 1e9+97;
const int B = 171;
int n,m;
int hsh(int pre,string s,int l,int r){
	int re=pre;
	rep(i,l,r){
		re=((LL)re*B+s[i])%Mod;
	}
	return re;
}
string s[N][2];
string t[2];
// int hs[N];
unordered_map<int,int> mp;

signed main(){
	string __name = "replace";
	if(__name!=""){
		freopen((__name+".in").c_str(),"r",stdin);
		freopen((__name+".out").c_str(),"w",stdout);
	}
	Ios();
	cin>>n>>m;
	rep(i,1,n){
		cin>>s[i][0]>>s[i][1];
		int tmp=hsh(0,s[i][0],0,sz(s[i][0])-1);
		tmp=hsh(tmp,s[i][1],0,sz(s[i][1])-1);
		mp[tmp]++;
	}
	rep(b,1,m){
		cin>>t[0]>>t[1];
		int l=-1,r=-1;
		rep(i,0,sz(t[0])-1){
			if(t[0][i]!=t[1][i]){
				l=i;
				break;
			}
		}
		for(int i=sz(t[0])-1;i>=0;--i){
			if(t[0][i]!=t[1][i]){
				r=i;
				break;
			}
		}
		int ans=0;
		Debug(b,t[0],t[1],l,r);
		rep(L,0,l){
			for(int R=sz(t[0])-1;R>=r;--R){
				int tmp=hsh(0,t[0],L,R);
				tmp=hsh(tmp,t[1],L,R);
				ans+=mp[tmp];
				// if(mp.count(tmp)){
				// 	Debug(L,R,mp[tmp]);
				// }
			}
		}
		cout<<ans<<"\n";
	}
}