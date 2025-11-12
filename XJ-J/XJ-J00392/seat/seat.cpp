#include<bits/stdc++.h>
using namespace std;
int a[105], d[15][15];
int cmp(int x, int y) {
	return x>y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	} int k=0, g=a[1], l=1;
	sort(a+1, a+n*m+1, cmp);
	/* 调试 
	for(int i=1; i<=n*m; i++) {
		cout<<a[i]<<" ";
	} cout<<g<<endl;
	*/
	for(int i=1; i<=m; i++) { //或用奇偶数 
		if(k>n) {
			for(k=n; k>=1; k--) {
				// cout<<a[l]<<" ";
				d[i][k]=a[l++];
			}
		} else if(k<1) {
			for(k=1; k<=n; k++) {
				// cout<<a[l]<<" ";
				d[i][k]=a[l++];
			}
		}
	} // cout<<endl;
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			// cout<<i<<" "<<j<<" "<<d[i][j]<<endl; 
			if(d[i][j]==g) {
				cout<<i<<" "<<j;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	} return 0;
}
