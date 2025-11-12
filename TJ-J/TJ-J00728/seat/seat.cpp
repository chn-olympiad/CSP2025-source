#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],h,l,r;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i]==r) {
			if(i%m==0)l=i/m;
			else l=i/m+1;
			if(l%2==1) {
				if(i%n==0)h=n;
				else h=i%n;
			} else {
				if(i%n==0)h=1;
				else h=i%n+n-1;
			}
			cout<<l<<' '<<h;
			return 0;
		}
	}
	return 0;
}
