#include <bits/stdc++.h>

using namespace std;

namespace my_std{
	#define fi first
	#define se second
	#define sz(a) ((int)((a).size()))
	#define pb emplace_back
	#define rep(i,a,b) for(int i=(a);i<=(b);++i)
	using LL = long long;
	const int Mod = 1e9+7;
	template<class T> void Abs(T &x){
		x=x>0?x:-x;
	}
	template<class T> void qmod(T &x){
		x=x<0?x+Mod:(x>=Mod?x-Mod:x);
	}
	template<class T> T Qmod(T x){
		return x<0?x+Mod:(x>=Mod?x-Mod:x);
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

const int N = 1e5+1;
int n;
int a[N][3];
priority_queue<pii> q[3];

signed main(){
	string __name = "club";
	if(__name!=""){
		freopen((__name+".in").c_str(),"r",stdin);
		freopen((__name+".out").c_str(),"w",stdout);
	}
	Ios();
	int TT; cin>>TT;
	while(TT--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		rep(i,1,n){
			int c1=0;
			rep(j,0,2){
				if(j!=c1){
					if(a[i][j]>a[i][c1]){
						c1=j;
					}
				}
			}
			int c2=0;
			if(!c1){
				c2=1;
			}
			rep(j,0,2){
				if(j!=c1 and j!=c2){
					if(a[i][j]>a[i][c2]){
						c2=j;
					}
				}
			}
			Debug(c1,c2,a[i][c1],a[i][c2]);
			q[c1].push(cp(a[i][c2]-a[i][c1],i));
		}
		int ans=0;
		rep(j,0,2){
			while(sz(q[j])>n/2){
				auto [w,i] = q[j].top();
				q[j].pop();
				ans+=w;
				ans+=a[i][j];
			}
		}
		rep(j,0,2){
			while(!q[j].empty()){
				auto [w,i] = q[j].top();
				q[j].pop();
				ans+=a[i][j];
			}
		}
		cout<<ans<<"\n";
	}
}