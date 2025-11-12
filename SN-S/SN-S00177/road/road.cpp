#include <bits/stdc++.h>
#define ss second
#define ff first
using namespace std;
//#define int long long
#define ll long long
int read() {
	char c;int t=1;
	while(1) {
		c=getchar();
		if(c>='0'&&c<='9') break ; 
	}
	int s=c-'0';
	while(1) {
		c=getchar() ;
		if(c<'0'||c>'9') break ;
		s=s*10+c-'0';
	}
	return s ;
}
int a[100005][3] ;
int TT ;
int sum[3] ;
int n ;
int m ;
int k;
struct E {
	int x,y,z ;
} p[1000005] ;
bool operator <(const E &a,const E &b) {
	return a.z<b.z ;
}
int fa[1000005] ;
int fnd(int x) {
	if(fa[x]==x) return x;
	return fa[x]=fnd(fa[x]) ;
}
vector<E> g[15] ;
ll val[15] ;
void work() {
	ll ans=0 ;
	cin>>n>>m>>k ;
//	int nd=0 ;
	for(int i=1;i<=m;i++) {
		int x=read(),y=read(),z=read() ;
		p[i]={x,y,z} ;
//		cout<<"?\n"<<x<<' '<<y<<' '<<z<<endl;
	}
	sort(p+1,p+m+1) ;
	for(int i=1;i<=n;i++) fa[i]=i ;
	for(int i=1;i<=m;i++) {
//		cout<<i<<endl;
//		cout<<p[i].x<<' '<<p[i].y<<' '<<p[i].z<<endl;
		int x=fnd(p[i].x),y=fnd(p[i].y) ;
		if(x==y) continue ;
		fa[x]=y ;
		ans+=p[i].z ;
		g[0].push_back(p[i]) ;
	}
//	return ;
	for(int i=1;i<=k;i++) {
		cin>>val[i];
		for(int j=1;j<=n;j++) {
			int vl=read() ;
			g[i].push_back({i+n,j,vl}) ;
		}
		sort(g[i].begin(),g[i].end()) ;
	}
//	cout<<ans<<endl;
	for(int i=1;i<1<<k;i++) {
		ll sum=0 ;
		int num=0;
		for(int j=0;j<k;j++) if(i&(1<<j)) {
			sum+=val[j+1] ;
			num++ ;
		}
		for(int i=1;i<=n+m;i++) fa[i]=i ;
		set<pair<int,pair<int,int> > > s ;
		s.insert({g[0][0].z,{0,0}}) ;
		for(int j=0;j<k;j++) {
			if(i&(1<<j)) {
				s.insert({g[j+1][0].z,{j+1,0}}) ;
			}
		}
//		cout<<i<<' '<<num<<endl;
		int cnt=0 ;
		while(1) {
			pair<int,pair<int,int> > id=*s.begin() ;
			s.erase(id) ;
			if(id.ss.ss+1<g[id.ss.ff].size()) s.insert({g[id.ss.ff][id.ss.ss+1].z,{id.ss.ff,id.ss.ss+1}});
			E now=g[id.ss.ff][id.ss.ss] ;
//			cout<<id.ss.ff<<' '<<id.ss.ss<<' '<<now.x<<' '<<now.y<<' '<<now.z<<endl;
			int x=fnd(now.x),y=fnd(now.y) ;
			if(x==y) continue ;
			fa[x]=y ;
			sum+=now.z;
			cnt++ ;
			if(cnt==n+num-1) break ;
		}
//		cout<<i<<' '<<sum<<endl;
		ans=min(ans,sum) ;
	}
	cout<<ans ;
}
signed main() {
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ;
//cin>>TT ;
TT=1 ;
while(TT--) {work() ;}
	
	
	return 0 ;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
