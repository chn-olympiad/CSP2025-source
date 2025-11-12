#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,sum=0;
vector<int>g;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		g.push_back(w);
	}
	for(int i=1,x;i<=k;i++)
		for(int i=1;i<=n+1;i++)scanf("%lld",&x),g.push_back(x);
	sort(g.begin(),g.end());
	for(int i=0;i<n+k+1;i++)sum+=g[i];
	printf("%lld",sum-g[0]);
	return 0;
}