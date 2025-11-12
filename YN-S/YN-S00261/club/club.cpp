#include <bits/stdc++.h>
using namespace std;

bool f(vector<int> v, int n) {
	for (int i = 0; i < n; i++) {
		if (v[i] != 1) {
			return true;
			break;
		} else {
			return false;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	vector<int> ans(t, 0);
	int num = 0;
	while (t > 0) {
		int n;
		cin >> n;
		vector<vector<int>>  v;
		vector<int> temp;
		vector<int> v1(10001, 0);
		vector<int> v2(10001, 0);
		vector<int> v3(10001, 0);
		vector<int> vs(10001, 0);
		int a = 0;
		int b = 0;
		int c = 0;
		int q = 0;
		int w = 0;
		int e = 0;
		int y = 0;
		for (int i = 0; i < n; i++) {
			temp.clear();
			for (int j = 0; j < 3; j++) {
				int a;
				cin >> a;
				temp.push_back(a);
			}
			v.push_back(temp);
		}
		while (f(vs, n)) {
			for (int i = 0; i < 3; i++) {
				y = 0;
				for (int j = 0; j < n; j++) {
					if (v[y][i] < v[j][i]) {
						if (vs[j] < 1) {
							y = j;
						}
					}
				}
				if (vs[y] < 1) {
					vs[y] = 1;
					if (i == 0) {
						v1[v[y][0]]++;
						a++;
					} else if (i == 1) {
						v2[v[y][1]]++;
						b++;
					} else {
						v3[v[y][2]]++;
						c++;
					}
					v[y][i] = 0;
				}
			}
		}
		if (a <= n / 2 && b <= n / 2 && c <= n / 2) {
			for (int i = 0; i < 10001; i++) {
				if (v1[i] != 0) {
					q = q + v1[i] * i;
				}
				if (v2[i] != 0) {
					w = w + v2[i] * i;
				}
				if (v3[i] != 0) {
					e = e + v3[i] * i;
				}
			}
			ans[num] = w + q + e;
			num++;
		}
		t--;
	}
	for (int a : ans) {
		cout << a << endl;
	}

	fclose(stdin);
	fclose(stdout);
}