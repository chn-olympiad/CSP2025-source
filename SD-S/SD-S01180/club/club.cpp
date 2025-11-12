//T1
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

const ll INF=0x3f3f3f3f;
const ll mod=998244353;
const ll N=1e5+10;

struct Node1{
	ll idx,num;
};
struct Node2{
	ll idx; Node1 a[5];
}a[N];
bool cmp(Node1& x,Node1& y){
	return x.num>y.num;
}
ll cnt[5],used[N];
struct Node3{
	ll idx,x,y,w;
	bool operator>(const Node3& y) const{
		return w>y.w;
	}
};
priority_queue<Node3,vector<Node3>,greater<Node3> > pq;

void Solve(void) {
	ll n,k=0,sum=0; cin>>n;
	for(;!pq.empty();pq.pop());
	for(ll i=1;i<=n;i++) used[i]=0;
	for(ll j=1;j<=3;j++) cnt[j]=0;
	for(ll i=1;i<=n;i++) {
		for(ll j=1;j<=3;j++) cin>>a[i].a[j].num,a[i].a[j].idx=j;
		sort(a[i].a+1,a[i].a+4,cmp);
//		for(ll j=1;j<=3;j++) cout<<a[i].a[j].idx<<' ';
		a[i].idx=i;
		sum+=a[i].a[1].num;
		if(++cnt[a[i].a[1].idx]>(n>>1)) k=a[i].a[1].idx;
	}
	if(k==0) {
		cout<<sum<<'\n';
		return ;
	}
//	cout<<k<<' ';
	for(ll i=1;i<=n;i++) {
		if(a[i].a[1].idx!=k) used[i]=1;
		else for(ll j=2;j<=3;j++)
			pq.push({i,1,j,a[i].a[1].num-a[i].a[j].num});
	}
//	for(;!pq.empty();) {
//		//__x.x -> __x.y (idx)
//		Node3 __x=pq.top(); pq.pop();
////		cout<<__x.x<<' '<<__x.y<<' ';
//		cout<<__x.w<<' ';
//	}
	ll tra_cnt=0;
	for(;!pq.empty();) {
		//__x.x -> __x.y (idx)
		Node3 __x=pq.top(); pq.pop();
		if(used[__x.idx]) continue;
		else if(cnt[a[__x.idx].a[__x.y].idx]>=(n>>1)) continue;
		cnt[a[__x.idx].a[__x.y].idx]++;
//		cnt[__x.x]--;
		used[__x.idx]=1;
//		ll w=a[idx].a[x].num-a[i].a[y].num;
		sum-=__x.w;
		if(++tra_cnt==cnt[k]-(n>>1)) break;
	}
	cout<<sum<<'\n';
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	ll lqyily; cin>>lqyily; for(;lqyily--;)
	Solve();
	return 0;
}
