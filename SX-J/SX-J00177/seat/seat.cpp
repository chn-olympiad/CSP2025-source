#include <bits/stdc++.h>
using namespace std;

bool cmp (int a,int b) {
	return a > b;
}
int x,y;
int j = 1;


int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[100005] = {0};
	cin >> y >> x;
	int z = x * y;
	for (int i = 1;i <= z;i++) {
		cin >> a[i];
	}
	const int R = a[1];
	sort(a + 1,a + 1 + z,cmp);
	int seat[15][15] = {};

	int k = 1;
	for (int i = 1;i <= x;i++) {
		if (j != y) {
		for (;j <= y;j++) {
			seat[i][j] = a[k];
			k++;
		}
	}
	j--;
	i++;
		if (j >= y) {
			for (;j >= 1;j--) {
				seat[i][j] = a[k];
				k++;
			}
			j++;
		}
	}




	for (int i = 1;i <= x;i++) {
		for (int j = 1;j <= y;j++) {
			if (seat[i][j] == R) {
				cout << i << " " << j;
				return 0;
			}
		}
	}


	return 0;
}



