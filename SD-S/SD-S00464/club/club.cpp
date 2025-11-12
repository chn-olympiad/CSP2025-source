#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T,n,a[100005][5];
struct node {
	int x,id;
};
struct node2 {
	int x,id,idx,c;
};
bool operator<(node x,node y) {
	if(x.x==y.x)return x.id>y.id;
	return x.x<y.x;
}
priority_queue<node>q[100005];
bool operator<(node2 x,node2 y) {
	if(x.c==y.c)return x.x>y.x;
	return x.c>y.c;
}
priority_queue<node2>q2[5];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1; i<=n; i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1; i<=n; i++) {
			q[i].push({a[i][1],1});
			q[i].push({a[i][2],2});
			q[i].push({a[i][3],3});
		}
		for(int i=1; i<=n; i++) {
			int x=q[i].top().x,id=q[i].top().id;
			q[i].pop();
			q2[id].push({x,id,i,x-q[i].top().x});
		}
		while(1) {
			int f=0;
			for(int i=1; i<=3; i++) {
				while(q2[i].size()>n/2) {
					f=1;
					int j=q2[i].top().idx;
					q2[i].pop();
					int x=q[j].top().x,id=q[j].top().id;
					q[j].pop();
					q2[id].push({x,id,j,x-q[j].top().x});
				}
			}
			if(!f)break;
		}
		ll ans=0;
		for(int i=1; i<=3; i++) {
			while(!q2[i].empty())ans+=q2[i].top().x,q2[i].pop();
		}
		cout<<ans<<"\n";
		for(int i=1; i<=n; i++)while(!q[i].empty())q[i].pop();
	}
	return 0;
}
