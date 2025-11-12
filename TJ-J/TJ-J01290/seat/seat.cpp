#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15],b[105],c[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int num = n*m;
	int R;
	for (int i = 1;i<=num;i++) {
		cin >> b[i];
		if (i == 1)
			R = b[i];
	}
	int sum = 0;
	int e = 1;
	for (int i = 1;i<=num;i++) {
		if (b[i] > R) {
			c[e] = b[i];
			e++;
		}
	}
	c[e] = R;
	int d = 1;
	for (int i = 1;i<=m;i++) {
		if (i%2 == 1) {
			for (int j = 1;j<=n;j++) {
				a[j][i] = c[d];
				d++;
				if (a[j][i] == R) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
		else {
			for (int j = n;j>=1;j--) {
								a[j][i] = c[d];
				d++;
				if (a[j][i] == R) {
					cout << i << ' ' << j;
					return 0;
			}
		}
	}
}
}
