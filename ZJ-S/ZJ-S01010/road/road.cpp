#include<bits/stdc++.h>
#define ll long long
#define exp __builtin_expect
using namespace std;
const int N=1e4+10,M=1e6+10;
ll n,m,K,a[11][N],v[11],ans;int mnd[11];
struct edge{
	int u,v;ll w;
	inline bool operator<(const edge &y)const{return w<y.w;}
} e[M],g[N*11],ae[11][N];
//inline bool operator<(edge x,edge y){return x.w>y.w;}

int fah[N];
inline int find(int x){
	return x==fah[x]?x:fah[x]=find(fah[x]);
//	if(exp(x==fah[x],0)) return x;
//	return fah[x]=find(fah[x]);
}


ll nans[2000];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		e[i]={x,y,z};
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=n;++i) fah[i]=i;
	int tt=0;
	for(int i=1;i<=m;++i){
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2){
			fah[f2]=f1;
			ans+=e[i].w;
			ae[10][++tt]=e[i];
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
		sort(ae[i]+1,ae[i]+n);
	}
	nans[0]=ans;
	for(int b=1;b<(1<<K);++b){
		for(int i=1;i<=n-1;++i) g[i]=ae[10][i];
		int mm=n-1;
		for(int t=b;t;){
			int gg=__lg(t);
			nans[b]+=v[gg];
			if(nans[b]>=ans) break;
			
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
		for(int i=1;i<=n;++i) fah[i]=i;
		int tt=0;
		for(int i=1;i<=mm;++i){
			int f1=find(e[i].u),f2=find(e[i].v);
			if(f1!=f2){
				fah[f2]=f1;
				nans[b]+=e[i].w;
				if(exp(nans[b]>=ans,0)) break;
				++tt;
				if(exp(tt==n-1,0)) break;
			}
		}
		ans=min(ans,nans[b]);
	}
	cout<<ans<<'\n';
	return 0;
}
