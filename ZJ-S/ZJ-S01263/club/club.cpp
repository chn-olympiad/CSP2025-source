#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,t;
struct r {
	int x,y,z;
} a[10001];
prioruty_queue<node>qa,qb,qc;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=1; i<=n; i++) {
			bool f=0;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) {
				if(qa.size()<n/2) {
					qa.push({a[i].x,a[i].y,a[i].z});
				} else {
					if(a[i].y==a[i].x) {
						qb.push({a[i].x,a[i].y,a[i].z})
					} else if(a[i].x==a[i].z) {
						qc.push({a[i].x,a[i].y,a[i].z});
					} else {
						int l,id;
						auto q=qa.top;
						if(a[i].x-q.x+max(q.y,q.z)>=max(a[i].y,a[i].z)) {
							qa.pop();
							qa.push({});
						} else {
							if(a[i].y>a[i].z) {

							}
						}
					}
				}
			}

		}
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z) {
			if(qa.size()<n/2) {
				qa.push({a[i].x,a[i].y,a[i].z});
			} else {
				if(a[i].y==a[i].x) {
					qb.push({a[i].x,a[i].y,a[i].z})
				} else if(a[i].x==a[i].z) {
					qc.push({a[i].x,a[i].y,a[i].z});
				} else {
					int l,id;
					auto q=qa.top;
					if(a[i].x-q.x+max(q.y,q.z)>=max(a[i].y,a[i].z)) {
						qa.pop();
						qa.push({});
					} else {
						if(a[i].y>a[i].z) {

						}
					}
				}
			}
		}
	}

	return 0;
}
