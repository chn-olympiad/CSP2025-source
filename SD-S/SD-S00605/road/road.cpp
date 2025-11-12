#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+9,M=1e4+9,INF=1e18;
ll n,m,k,rt[M],minn=INF,cost[20];
struct node{
	ll l,r,num;
}a[N+20*M];
void Short(ll ddi,ll ddj,ll add){
	ll ans=add,cnt=1;
	for(int i=1;i<=n;i++){
		rt[i]=i;
	}
	for(int i=1;i<=m;i++){
		if(rt[a[i].l]!=rt[a[i].r]){
			rt[a[i].l]=rt[a[i].r];
			ans+=a[i].num;
			cnt++;
		}
		if(cnt==n){
			break;
		}
	}
	minn=min(minn,ans); 
}
bool cmp(node c,node b){
	return c.num<b.num;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].l>>a[i].r>>a[i].num;
	}
	sort(a+1,a+m+1,cmp);
	Short(0,1,0);
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		cost[i]+=cost[i-1];
		for(int j=1;j<=n;j++){
			cin>>a[m+].num;
			cst[i][j].l=j;
			cst[i][j].r=m+i;
		}
	}
	cout<<minn;
	return 0;
}
