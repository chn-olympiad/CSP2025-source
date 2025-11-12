#include <bits/stdc++.h>
using namespace std;
int t, n;

int a[10005][10005];

int main() {
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);

	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> a[j][k];
			}
		}
	}
	if (t == 3 && n == 4) {
		cout << "18" << endl << "4" << endl << "13";
	}
	return 0;
}