#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e4,M=2e6,K=10;
using namespace std;
int n,m,k,t[N+5],c[K+5];
bool f[K+5],g[K+5];
pair<pii,pii> e[M+5];
int gett(int x){
	return t[x]==x?x:t[x]=gett(t[x]);
}
int getit(int x=0){
	int ans=0;
	f[0]=1;
	for(int i=1;i<=k;i++){
		f[i]=(x&(1<<(i-1)));
		ans+=c[i]*f[i];
	}
	for(int i=1;i<=n+k;i++) t[i]=i;
	for(int i=1;i<=m;i++){
		if(f[e[i].fi.se]){
			if(gett(e[i].se.se)!=gett(e[i].se.fi)){
				ans+=e[i].fi.fi;
				t[t[e[i].se.se]]=t[e[i].se.fi];
			}
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].se.fi>>e[i].se.se>>e[i].fi.fi;
		if(e[i].se.fi>e[i].se.se){
			swap(e[i].se.fi,e[i].se.se);
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			if(x==0&&c[i]==0){
				g[i]=1;
			}
			e[++m]={{x,i},{j,n+i}};
		}
	}
	sort(e+1,e+m+1);
	int ans=getit();
	for(int i=0;i<(1<<k);i++){
		bool _=1;
		for(int j=1;j<=k;j++){
			if(g[j]&&!(i&(1<<(j-1)))){
				_=0;
				break;
			}
		}
		if(_) ans=min(ans,getit(i));
	}
	cout<<ans;
	return 0;
}
