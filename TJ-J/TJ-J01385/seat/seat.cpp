#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+5];
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1; i<=n*m/2; i++) {
		swap(a[i],a[n*m-i+1]);
	}
	for(int i=1; i<=m; i++) {
		if((i+2)%2==1) {
			for(int j=1; j<=n; j++) {
				if(a[n*(i-1)+j]==R) {
					cout<<i<<' '<<j;
					return 0;
				}
			}
		} else {
			for(int j=n; j>0; j--) {
				if(a[i*n-j+1]==R) {
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
}
