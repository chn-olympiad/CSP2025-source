#include<bits/stdc++.h>
using namespace std;
int m,n,maxn,w;
int a[105],b[12][12],c;

bool cmp(int x,int y) {
	return x>y;
}


int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>w;
	a[1]=w;
	for(int i=2; i<=n*m; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n*m,cmp);
	for(int i=1; i<=m; i++) {
		if(i%2) {
			for(int j=1; j<=n; j++) {
				b[j][i]=a[++c];
			}
		} else {
			for(int j=n; j>=1; j--) {
				b[j][i]=a[++c];
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(b[i][j]==w) cout<<j<<' '<<i;
		}
	}
	return 0;
}
