#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,M=1e6+10;
ll n,m,K,a[12][N],v[12],mnd[12],ans;
struct edge{
	int u,v;ll w;
} e[M],g[N*12],ae[12][N];
inline bool cmp(edge x,edge y){return x.w<y.w;}
inline bool operator<(edge x,edge y){return x.w>y.w;}

int fah[N];
inline int find(int x){
	return x==fah[x]?x:fah[x]=find(fah[x]);
}

priority_queue<edge> pq;
signed main(){
	freopen("road3.in","r",stdin);
//	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		e[i]={x,y,z};
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;++i) fah[i]=i;
	int tt=0;
	for(int i=1;i<=m;++i){
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2){
			fah[f2]=f1;
			ans+=e[i].w;
			ae[11][++tt]=e[i];
			if(tt==n-1) break;
		}
	}
	for(int i=0;i<K;++i){
		cin>>v[i];
		a[i][0]=1e18;
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j]<a[i][mnd[i]]) mnd[i]=j;
		}
		v[i]+=a[i][mnd[i]];
		int tt=0;
		for(int j=1;j<=n;++j){
			if(j==mnd[i]) continue;
			ae[i][++tt]={mnd[i],j,a[i][j]};
		}
		sort(ae[i]+1,ae[i]+n,cmp);
	}
	for(int b=1;b<(1<<K);++b){
		for(int i=1;i<=n-1;++i) g[i]=ae[11][i];
		ll nans=0;
		int mm=n-1;
		for(int t=b;t;){
			int gg=__lg(t);
			nans+=v[gg];
			
			int lp=1,rp=1,ap=0;
			while(lp<=mm&&rp<=n-1){
				if(g[lp]<ae[gg][rp]) e[++ap]=g[lp++];
				else e[++ap]=ae[gg][rp++];
			}
			while(lp<=mm) e[++ap]=g[lp++];
			while(rp<=n-1) e[++ap]=ae[gg][rp++];
			
			mm+=n-1;
			for(int i=1;i<=mm;++i) g[i]=e[i];
			t-=(1<<gg);
		}
		if(nans>=ans) continue;
		for(int i=1;i<=n;++i) fah[i]=i;
		int tt=0;
		for(int i=1;i<=mm;++i){
			int f1=find(e[i].u),f2=find(e[i].v);
			if(f1!=f2){
				fah[f2]=f1;
				nans+=e[i].w;
				if(nans>=ans) break;
				++tt;
				if(tt==n-1) break;
			}
		}
		ans=min(ans,nans);
	}
	cout<<ans<<'\n';
	return 0;
}
