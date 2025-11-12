#include <bits/stdc++.h>
using namespace std;
int a[10005][5], n[10005];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n[i];
		for (int j = 0; j < n[i]; j++) {
			for (int y = 0; y < 3; y++)
				cin >> a[j][y];
		}
	}
	for (int h = 0; h < c; h++) {
		int ans = 0;
		for (int j = 0; j < n[h]; j++) {
			if (a[j][0] > a[j][1] || a[j][0] > a[j][2])
				ans += a[j][0];
			else if (a[j][1] > a[j][0] || a[j][0] > a[j][2])
				ans += a[j][1];
			else if (a[j][2] > a[j][1] || a[j][2] > a[j][0])
				ans += a[j][2];
		}
		cout << ans << endl;
		ans = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}