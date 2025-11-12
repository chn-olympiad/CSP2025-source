#include <bits/stdc++.h>
using namespace std;
struct e {
	int x,y;
};
e p[101];
bool cmp(e a,e b) {
	return a.x>b.x;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>p[i].x;
		p[i].y=i;
	}
	sort(p+1,p+n*m+1,cmp);
	int c=1,r=1;
	for(int i=1; i<=n*m;) {
		if(p[i].y==1) {
			cout<<c<<" "<<r;
			return 0;
		}
		if(c%2) {
			r++;
			if(p[i++].y==1) {
				cout<<c<<" "<<r;
				return 0;
			}
			if(r==n) {
				c++;
				if(p[i++].y==1) {
					cout<<c<<" "<<r;
					return 0;
				}
			}
		} else {
			r--;
			if(p[i++].y==1) {
				cout<<c<<" "<<r;
				return 0;
			}
			if(r==1) {
				c++;
				if(p[i++].y==1) {
					cout<<c<<" "<<r;
					return 0;
				}
			}
		}
	}
	return 0;
}
