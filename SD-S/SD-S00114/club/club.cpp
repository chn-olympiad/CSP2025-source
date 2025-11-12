#include<bits/stdc++.h>
using namespace std; 
const int N=1e5+10;
int n,a[N][4];
struct Node{
	int now,another;
	bool operator < (const Node &rhs) const {
		return another-now<rhs.another -rhs.now ;
	}
};
priority_queue<Node>aa,bb,cc;

void solve() {
	cin>>n;
	while(aa.size()) aa.pop();
	while(bb.size()) bb.pop();
	while(cc.size()) cc.pop();
	long long ans=0;
	for(int i=1;i<=n;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		if(x>=y&&x>=z) {
			ans+=x;
			aa.push({x,max(y,z)});
		} else if(y>=x&&y>=z) {
			ans+=y;
			bb.push({y,max(x,z)});
		} else if(z>=x&&z>=y) {
			ans+=z;
			cc.push({z,max(x,y)});
		}
	}
	while(aa.size()>(n/2)) {
		Node e=aa.top();
		aa.pop();
		ans+=(e.another -e.now );
	}
	while(bb.size()>(n/2)) {
		Node e=bb.top();
		bb.pop();
		ans+=(e.another -e.now );
	}
	while(cc.size()>(n/2)) {
		Node e=cc.top();
		cc.pop();
		ans+=(e.another -e.now );
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}
