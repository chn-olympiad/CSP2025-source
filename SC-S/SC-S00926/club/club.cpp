#include<bits/stdc++.h> 
using namespace std ;

#define int ll
typedef long long ll; 
typedef unsigned long long ull ;

using pii=pair<int,int> ;
#define fi first
#define se second
#define mk make_pair

#define sz(x) (int)(x.size()) 
#define eb emplace_back 
#define btpc(x) __builtin_popcount(x) 
#define btpcll(x) __builtin_popcountll(x)

#define ReadIn(s) freopen(s,"r",stdin)
#define OutPut(s) freopen(s,"w",stdout)

bool Mst ;

const int M=3e5+10;

inline void read (int& x) {
	int sgn=0;char ch=getchar() ;x=0;
	while(!isdigit(ch)) sgn|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	sgn?x=-x:1;
}

int n;
int id[M] ;
vector<pii>vec[M] ;

priority_queue<pii,vector<pii>,greater<pii> >q[3] ;

void solve() {
	
	for(int i=0;i<3;i++) while(sz(q[i])) q[i].pop() ;
	
	read(n) ;
	for(int i=1;i<=n;i++) {
		vec[i].clear() ;
		for(int j=0;j<3;j++) {
			int x;read(x) ;
			vec[i].eb(mk(x,j)) ;
		}
		sort(vec[i].begin(),vec[i].end()) ;
		id[i]=i;
	}
	
	int Ans =0;
	int c[3]={} ;
	
	sort(id+1,id+n+1,[] (int x,int y) {
		return vec[x].back()>vec[y].back() ;
	});
	
	for(int j=1;j<=n;j++) {
		
//		cout<<id[j]<<" " ;
		
		int i=id[j] ;
		int x=vec[i].back().fi,y=vec[i].back().se ;
		if(c[y]<n/2) Ans+=x ,q[y].push(mk(x-vec[i][1].fi,i)),c[y]++; 
		else {
			int z=vec[i][1].fi,w=vec[i][1].se;
			int k=q[y].top().se ;
			if(vec[k].end()[-2].fi+x>z+vec[k].end()[-1].fi) {
				Ans-=vec[k].end()[-1].fi;Ans+=vec[k].end()[-2].fi+x;
				q[y].pop();q[y].push (mk(x-vec[i][1].fi,i)) ;
				vec[k].pop_back() ;q[vec[k].back().se].push(mk(vec[k].back().fi,k));c[vec[k].back().se]++;
			}
			else {
				vec[i].pop_back() ;Ans+=z;
				q[w].push(mk(z,i)) ;c[w]++;
			}
		}
		
//		cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<"\n" ;
	}
	
//	cout<<"\n" ;
	
	cout<<Ans<<"\n" ;
	
}

bool Med ;

signed main() {
	ReadIn("club.in");
	OutPut("club.out");
	
	int t;read(t) ;
	while(t--) solve() ;
	
	cerr<<"\n" ;
	cerr<<1.0*clock () /CLOCKS_PER_SEC*1000<<" ms\n" ;
	cerr<<(&Med-&Mst) /1024.0/1024.0<<" mb\n" ;
	
	return 0;
}