#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll t;

struct st {
	ll x;
	ll y;
	ll z;
} a[N];

int ans,n,strict;

struct node {
	ll id;
	ll val;
	bool operator<(const node &v) const {
		return val>v.val;
	}
};

priority_queue<node> q1,q2,q3;


int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1; i<=t; i++) {
		cin>>n;
		strict=n/2;
		ans=0;
		while(!q1.empty()){
			q1.pop();
		}
		while(!q2.empty()){
			q2.pop();
		}
		while(!q3.empty()){
			q3.pop();
		}
		for(int j=1; j<=n; j++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) {
				ans+=a[i].x;
				if(a[i].y>=a[i].z) {
					q1.push({i,a[i].x-a[i].y});
				} else {
					q1.push({i,a[i].x-a[i].z});
				}
			} else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) {
				ans+=a[i].y;
				if(a[i].x>=a[i].z) {
					q2.push({i,a[i].y-a[i].x});
				} else {
					q2.push({i,a[i].y-a[i].z});
				}
			} else if(a[i].z>=a[i].x&&a[i].z>=a[i].y) {
				ans+=a[i].z;
				if(a[i].x>=a[i].y) {
					q3.push({i,a[i].z-a[i].x});
				} else {
					q3.push({i,a[i].z-a[i].y});
				}
			}
		}
		while(q1.size()>strict) {
			ans-=q1.top().val;
			q1.pop();
		}
		while(q2.size()>strict) {
			ans-=q2.top().val;
			q2.pop();
		}
		while(q3.size()>strict) {
			ans-=q3.top().val;
			q3.pop();
		}
		cout<<ans<<endl;
	}
}