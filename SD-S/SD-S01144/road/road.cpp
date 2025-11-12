#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const ll N=2e6+10;
struct node{
	ll x,y,w;
	bool operator<(const node &other){
		return w<other.w;
	}
};
int n,m,k;
ll x,y,z,ans=5e18;
int p[N];
ll t[20][N],cost[N];
bool st[N];
vector<node> q; 
ll find(ll x){
	if(p[x]!=x) return p[x]=find(p[x]);
	return x;
}
void check(ll tot){
//	cout<<"±¾´ÎÑ¡Ôñ£º\n";
//	for(int i=1;i<=k;i++){
//		if(st[i]) cout<<i<<" ";
//	}
//	cout<<"\n\n";
	for(int i=1;i<=n;i++) p[i]=i;
	int l=q.size();
	int cnt=0;
	for(int i=0;i<l;i++){
		int tx=find(q[i].x),ty=find(q[i].y);
		if(tx!=ty){
			p[tx]=ty;
			ll ne=5e18;
			for(int j=1;j<=k;j++){
				if(!st[j]) continue;
				ne=min(ne,t[j][q[i].x]+t[j][q[i].y]);
			}
//			cout<<q[i].x<<" "<<q[i].y<<" "<<ne<<"\n";
			tot+=min(q[i].w,ne);
			cnt++;
			if(cnt==n-1) break;
		}
	}
//	cout<<"\n";
	ans=min(ans,tot);
}
void dfs(int now,ll tot){
	if(now>k){
		check(tot);
		return;
	}
	if(tot>ans) return;
	st[now]=true;
	dfs(now+1,tot+cost[now]);
	st[now]=false;
	dfs(now+1,tot);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		q.push_back({x,y,z});
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",&cost[i]);
		for(ll j=1;j<=n;j++) scanf("%lld",&t[i][j]);
	}
	sort(q.begin(),q.end());
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
