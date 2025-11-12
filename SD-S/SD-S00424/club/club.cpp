#include<bits/stdc++.h>
#define N 100005
#define pb push_back
using namespace std;
int n,ans;
priority_queue<int> q[3];
struct node{
	int x,s;
	bool operator<(const node &p) {
		return s>p.s;
	}
};
vector<node> a[N];
void solve() {
	cin>>n;ans=0;int he,x;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<3;j++) {
			cin>>he;a[i].pb({j,he});
		} sort(a[i].begin(),a[i].end());
	}
	for(int i=1;i<=n;i++) {
		ans+=a[i][0].s;
		q[a[i][0].x].push(a[i][1].s-a[i][0].s);
		a[i].clear();
	}
	for(int i=0;i<3;i++) {
		while(q[i].size()>n/2) {
			ans+=q[i].top();q[i].pop();
		} while(q[i].size()) q[i].pop();
	} printf("%d\n",ans);
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);int t;
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;while(t--) {solve();}
	
	return 0;
} 
