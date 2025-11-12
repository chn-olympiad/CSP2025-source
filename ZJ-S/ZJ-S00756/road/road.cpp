#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct edge{
	ll v,w;
	bool operator<(edge other){
		return w<other.w;
	} 
};
ll n,m,k,w[maxn],sum;
vector<edge>g[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		ll u,v;
		scanf("%lld%lld%lld",&u,&v,&w[i]);
	}
	sort(w+1,w+n+1);
	for(int i=1;i<=n-1;i++) sum+=w[i];
	printf("%lld",sum);
	return 0;
}
