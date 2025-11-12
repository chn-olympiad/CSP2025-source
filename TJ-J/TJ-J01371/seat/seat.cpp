#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[101]= {};
	int m,n;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int xr=a[1],n1=n,x=m*n;
	sort(a+1,a+m*n+1);
	for(int i=1; i<=m; i++) {
		if(i%2!=0) {
			for(int j=1; j<=n1; j++) {
				if(a[x]==xr) {
					cout<<i<<" "<<j;
					return 0;
				}
				x--;
			}
		} else {
			n=n1;
			while(n) {
				if(a[x]==xr) {
					cout<<i<<" "<<n;
					return 0;
				}n--;
				x--;
			}
		}
	}
}
