//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;++x)
#define per(x,z,y) for(int x=z;x>=y;--x)
#define qwq cout<<'\n'
#define exq exit(0)
using namespace std;
void IOS(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
}
void Document(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
bool sta__;
const int N=1e4+555;
const int M=1e6+55;
const int INF=1e17+55;
struct as{
	int u,v,w;
	bool operator <(const as&it) const{
		return w<it.w;
	}
}e[M];
as ed[12][N];
struct ass{
	int u,v,w;	
};
int val[12];
as b[N];
as c[M];
as dp[M];
int f[N];
int find(int x){
	return (f[x]==x?x:f[x]=find(f[x]));
}
int n,m,k;
int tot;
int cnt;
int ans;
int answer=INF;
void mer(int x){
	int l1=1;
	int l2=1;
	int len=0;
	while(l1<=tot&&l2<=n){
		if(c[l1]<ed[x][l2]){
			dp[++len]=c[l1];
			l1++;
		}
		else{
			dp[++len]=ed[x][l2];
			l2++;
		}
	}
	while(l1<=tot){
		dp[++len]=c[l1];
		l1++;
	}
	while(l2<=n){
		dp[++len]=ed[x][l2];
		l2++;
	}
	tot=len;
	rep(i,1,len) c[i]=dp[i];
}
void solve(int S){
	ans=0;
	tot=0;
	rep(i,1,n+k) f[i]=i;
	rep(i,1,cnt){
		c[++tot]=b[i];
	}
	rep(i,1,k){
		if(((S>>(i-1))&1)){
			mer(i);
			ans+=val[i];
		}
	}
	rep(i,1,tot){
		int u=c[i].u;
		int v=c[i].v;
		int fu=find(u);
		int fv=find(v);
		if(fu==fv) continue;
		f[fu]=fv;
		ans+=c[i].w;
	}
	answer=min(answer,ans);
}
bool end__;
main(){
	IOS();
//	cerr<<((&sta__-&end__)/1000/1000);
	Document();
	cin>>n>>m>>k;
	rep(i,1,m) cin>>e[i].u>>e[i].v>>e[i].w;
	rep(i,1,n) f[i]=i;
	sort(e+1,e+1+m);
	rep(i,1,m){
		int u=e[i].u;
		int v=e[i].v;
		int fu=find(u);
		int fv=find(v);	
		if(fu==fv) continue;
		f[fu]=fv;
		cnt++;
		b[cnt].u=u;
		b[cnt].v=v;
		b[cnt].w=e[i].w;
	}
	rep(i,1,k){
		cin>>val[i];
		rep(o,1,n){
			ed[i][o].u=n+i;
			ed[i][o].v=o;
			cin>>ed[i][o].w;
		}
		sort(ed[i]+1,ed[i]+1+n);
	}
	int Ms=(1<<k)-1;
	rep(i,0,Ms) solve(i);
	cout<<answer;
	return 0;
}
