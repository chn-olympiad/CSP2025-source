#include <bits/stdc++.h>
using namespace std;
int mp[109][109], mpp[109][109];
int r;
priority_queue<int>q;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w".stdout);
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mp[i][j];
			q.push(mp[i][j]);
		}
	}
	r = mp[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x = q.top();
			q.pop();
			if (i % 2 == 1)
				mpp[j][i] = x;
			else
				mpp[n - j + 1][i] = x;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cout << mpp[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (mpp[i][j] == r) {
				cout << i << " " << j << " ";
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
