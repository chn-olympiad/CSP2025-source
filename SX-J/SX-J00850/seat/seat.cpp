#include <bits/stdc++.h>
using namespace std;
int n, m, s[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	memset(s, -1, sizeof(s));
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> s[i];
	int x = s[1];
	sort(s + 1, s + n *m + 1, cmp);
	//for (int i = 1; i <= n * m; i++)
	//	cout << "s[" << i << "]=" << s[i] << endl;
	for (int i = 1; i <= n * m; i++) {
		if (s[i] == x) {
			//cout << i << endl;
			if (i % n == 0) {
				//cout << "DEBUG A" << endl;
				cout << i / n << " ";
				if ((i / n) % 2 == 0) {
					//	cout << "DEBUG A-A" << endl;
					cout << 1;
				} else {
					//	cout << "DEBUG A-B" << endl;
					cout << n;
				}
			} else {
				//cout << "DEBUG B" << endl;
				cout << i / n + 1 << " ";
				if ((i / n + 1) % 2) {
					//cout << "DEBUG B-A" << endl;
					cout << i % n;
				} else {
					//cout << "DEBUG B-B" << endl;
					cout << (n - i % n) + 1;
				}
			}
			return 0;
		}
	}
	return 0;
}
