#include <bits/stdc++.h>
using namespace std;

int n, q;
string a[1010][2];
int l[1010];

bool ch(string x, string y, int f) {
	int ll = y.size();
	for (int i = f, j = 0; i < f + ll && j < ll; i++, j++) {
		if (x[i] != y[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
		l[i] = a[i][0].size();
	}
	string zs1, zs2;
	for (int z = 0; z < q; z++) {
		int ans = 0;
		cin >> zs1 >> zs2;
		int zsl = zs1.size();
		for (int i = 0; i < n; i++) {
			//cout << a[i][0] << endl;
			for (int j = 0; j < zsl - l[i] + 1; j++) {
				if (ch(zs1, a[i][0], j) == true && ch(zs2, a[i][1], j) == true) {
					//cout << a[i][0] << " " << a[i][1] << endl;
					ans++;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
