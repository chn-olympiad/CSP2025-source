#include<bits/stdc++.h>
using namespace std;
int n,m;
struct point {
	int sum;
	bool f;
} a[105];
bool cmp(point x,point y) {
	return x.sum>y.sum;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i].sum;
		if(i==1) a[i].f=1;
		else a[i].f=0;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i].f) {
			int x=i%(2*n),y=i/(2*n)*2;
			if(x>n) {
				cout<<y+2<<' '<<n-(x-n)+1;
			}
			if(x<=n&&x!=0) {
				cout<<y+1<<' '<<x;
			}
			if(x==0) {
				cout<<y<<' '<<1;
			}
			break;
		}
	}
	return 0;
}