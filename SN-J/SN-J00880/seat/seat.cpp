#include<bits/stdc++.h>
using namespace std;
long long n,m,xim,s;
long long a[1000],f[110];
int cmp(long long x,long long y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
		if(i==1) {
			xim=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1,k=1; i<=m,k<=n*m; i++) {
		for(int j=1; j<=n; j++) {
			if(i%2==1) {
				if(a[k]==xim) {
					cout<<i<<" "<<j;
					return 0;
				}
			}
			if(i%2==0) {
				if(a[k]==xim) {
					cout<<i<<" "<<n-j+1;
					return 0;
				}
			}
			k++;
		}
	}
	return 0;
}
