#include<bits/stdc++.h>
using namespace std;
struct node {
	int x,y,z,fst,snd;
	bool operator<(const node &oth) const {
		return fst-snd>oth.fst-oth.snd;
	}
} a[200000];
int T,n,m,sum;
priority_queue<node> pq1,pq2,pq3;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		m=n/2;
		sum=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y && a[i].x>=a[i].z) {
				a[i].fst=a[i].x;
				a[i].snd=max(a[i].y,a[i].z);
				pq1.emplace(a[i]);
			} else if(a[i].y>=a[i].x && a[i].y>=a[i].z) {
				a[i].fst=a[i].y;
				a[i].snd=max(a[i].x,a[i].z);
				pq2.emplace(a[i]);
			} else if(a[i].z>=a[i].x && a[i].z>=a[i].y) {
				a[i].fst=a[i].z;
				a[i].snd=max(a[i].x,a[i].y);
				pq3.emplace(a[i]);
			}
			sum+=a[i].fst;
		}
		if(pq1.size()>n/2) {
			while(pq1.size()>n/2) {
				node now=pq1.top();
				pq1.pop();
				sum-=now.fst-now.snd;
			}
		}
		if(pq2.size()>n/2) {
			while(pq2.size()>n/2) {
				node now=pq2.top();
				pq2.pop();
				sum-=now.fst-now.snd;
			}
		}
		if(pq3.size()>n/2) {
			while(pq3.size()>n/2) {
				node now=pq3.top();
				pq3.pop();
				sum-=now.fst-now.snd;
			}
		}
		while(pq1.size())
			pq1.pop();
		while(pq2.size())
			pq2.pop();
		while(pq3.size())
			pq3.pop();
		cout<<sum<<endl;
	}
	return 0;
}
