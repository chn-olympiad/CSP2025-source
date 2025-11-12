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

const int N = 1e4+10+1;
const int K = 10+1;
const LL inf = 1e18+7;
int n,m,k;
int c[K]; vector<tpl> a[K];
vector<tpl> E;
vector<tpl> f[(1<<K)];
int fa[N],sz[N];
LL ans=inf;

int find(int x){
	if(!(x^fa[x])) return x;
	return fa[x]=find(fa[x]);
}

void tb_sort(vector<tpl> &e1,vector<tpl> &e2){
	E.clear();
	int m1=sz(e1);
	int m2=sz(e2);
	int i=0,j=0;
	while(i<m1 and j<m2){
		if(get<2>(e1[i])<get<2>(e2[j])){
			E.pb(e1[i]);
			++i;
		}else{
			E.pb(e2[j]);
			++j;
		}
	}
	while(i<m1){
		E.pb(e1[i]);
		++i;
	}
	while(j<m2){
		E.pb(e2[j]);
		++j;
	}
}

void mst(int t){
	LL re=0;
	rep(i,1,k){
		if((t>>i-1)&1){
			re+=c[i];
		}
	}
	Debug(re);
	rep(i,1,n+k){
		fa[i]=i;
		sz[i]=1;
	}
	for(auto [u,v,w] : E){
		int fx=find(u);
		int fy=find(v);
		if(fx^fy){
			f[t].pb(u,v,w);
			re+=w;
			if(sz[fx]<sz[fy]){
				swap(fx,fy);
			}
			fa[fy]=fx;
			sz[fx]+=sz[fy];
		}
	}	
	bool is_find = 0;
	int cf = find(1);
	rep(i,1,n){
		if(find(i)!=cf){
			is_find=1;
			break;
		}
	}
	rep(i,1,k){
		if((t>>i-1)&1){
			if(find(n+i)!=cf){
				is_find=1;
				break;
			}
		}
	}
	if(!is_find){
		Debug(re);
		chkmn(ans,re);	
	}
}

signed main(){
	string __name = "road";
	if(__name!=""){
		freopen((__name+".in").c_str(),"r",stdin);
		freopen((__name+".out").c_str(),"w",stdout);
	}
	Ios();
	cin>>n>>m>>k;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		E.pb(u,v,w);
	}
	sort(E.begin(),E.end(),[&](tpl x,tpl y){
		return get<2>(x)<get<2>(y);
	});		
	Debug(sz(E));
	Debug(E);
	mst(0);
	Debug(sz(f[0]));
	Debug(f[0]);
	rep(i,1,k){
		cin>>c[i];
		rep(j,1,n){
			int in;
			cin>>in;
			a[i].pb(n+i,j,in);
		}
		sort(a[i].begin(),a[i].end(),[&](tpl x,tpl y){
			return get<2>(x)<get<2>(y);
		});
	}
	rep(t,1,(1<<k)-1){
		int p=0;
		rep(i,1,n){
			if((t>>i-1)&1){
				p=i;
				break;
			}
		}
		int s=t^(1<<p-1);
		tb_sort(f[s],a[p]);
		Debug(s,t);
		Debug(sz(E));
		Debug(E);
		mst(t);
		Debug(sz(f[t]));
		Debug(f[t]);
	}
	cout<<ans<<"\n";
}