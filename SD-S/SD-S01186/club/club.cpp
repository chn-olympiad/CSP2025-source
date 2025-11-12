#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a1[N],a2[N],a3[N];
int ans=0;
int n;
struct node {
	int id;
	int s;
} a[N],b[N];
int cmp(node x,node y) {
	return x.s<y.s;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int m=1e9;
	for(int i=1; i<=t; i++) {
		cin>>n;
		if(n==2) {
			for(int i=1; i<=3; i++) {
				cin>>a[i].s;
				a[i].id=i;
			}
			for(int i=1; i<=3; i++) {
				cin>>b[i].s;
				b[i].id=i;
			}
			sort(a+1,a+1+3,cmp);
			sort(b+1,b+1+3,cmp);
			if(a[3].id==b[3].id) {
				cout<<max(a[3].s+b[2].s,a[2].s+b[3].s)<<endl;
			} else {
				cout<<a[3].s+b[3].s<<endl;
			}
			continue;
		} else {
			for(int i=1; i<=n; i++) {
				cin>>a1[i]>>a2[i]>>a3[i];
			}
			sort(a1+1,a1+1+n);
			int y=0;
			for(int i=n; i>=n/2+1; i++) {
				y+=a1[i];
			}
			cout<<y<<endl;
		}
	}
	return 0;
}
