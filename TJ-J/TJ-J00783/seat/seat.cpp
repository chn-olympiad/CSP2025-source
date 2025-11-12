#include<bits/stdc++.h>
using namespace std;
int n,m;

struct sum {
	int v;
};
sum num [105];
bool cmp (sum x,sum  y ) {
	return x.v > y.v;

}
int seat[15][15];
int numi;
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >>m;
	for (int i=0; i<n*m; i++) {
		cin >> num[i].v;
	}
	int ending=num[0].v;
	sort (num,num+n*m,cmp);

	for (int i=1; i<=n; i++) {
		if (i%2==1) {
			for (int j=1; j<=m; j++) {
				seat[i][j]=num[numi].v;
				numi++;
			}
		} else {
			for (int j=m; j>=1; j--) {
				seat[i][j]=num[numi].v;
				numi++;
			}
		}

	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (seat[i][j]==ending) {
				cout << i << " "<< j;
				return 0;
			}
			
		}
	}
	return 0;
}
