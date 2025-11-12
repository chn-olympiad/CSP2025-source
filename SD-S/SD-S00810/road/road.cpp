#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e4+50,K=20;
struct edge{
	ll v,w;
};
struct node{
	ll b,l;
	bool operator>(const node&a)const{
		return l>a.l;
	}
};
ll n,m,k,c[K],r[K][N],ans;
bool cheat,d[N];
vector<edge>t[N];
priority_queue<node,vector<node>,greater<node> >p;
void tree(){
	p.push({1,0});
	while(!p.empty()){
		node x=p.top();
		p.pop();
		if(d[x.b])
			continue;
		d[x.b]=true;
		ans+=x.l;
		for(auto i:t[x.b])
			if(!d[i.v])
				p.push({i.v,i.w});
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		t[u].push_back({v,w});
		t[v].push_back({u,w});
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		cheat|=c[i];
		for(ll j=1;j<=n;j++){
			scanf("%lld",&r[i][j]);
			cheat|=r[i][j];
		}
	}
	if(!cheat){
		printf("0");
		return 0;
	}
	tree();
	printf("%lld",ans);
	return 0;
}
