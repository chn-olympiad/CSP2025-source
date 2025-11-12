#include<bits/stdc++.h>
using namespace std;
struct rd{
	int u,v,w;
	bool operator <(const rd &x){
		return (w==x.w?u<x.u:w<x.w);
	}
};
const int nn=1e4+15;
vector<int> f(nn);
int fi(int x){
	return (x==f[x]?x:f[x]=fi(f[x]));
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k; cin>>n>>m>>k;
	long long ans=0;
	vector<rd> a;
	for(int i=0;i<m;i++){
		int u,v,w; cin>>u>>v>>w;
		a.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		int c; cin>>c;
		for(int j=1;j<=n;j++){
			int x; cin>>x;
			a.push_back({n+i,j,x});
		}
	}
	sort(a.begin(),a.end());
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=0,cnt=0;cnt<n-1;i++){
		auto x=fi(a[i].u),y=fi(a[i].v);
		if(x!=y){
			cnt++,ans+=a[i].w,f[x]=y;
		}
	}
	cout<<ans<<"\n";
	return 0;
}