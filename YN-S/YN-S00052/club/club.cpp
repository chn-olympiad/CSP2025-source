#include <bits/stdc++.h>
using namespace std;

//14:43题太难了QAQ
//可能出现的笑话：
//t1暴力dfs 10分勇夺一等(*^_^)
//14:53 键盘好烂...
//16:10 我太弱了...现在才写完dfs

int t;
int a[100005][4];
int b[10000];
int m[5];
int ma[6];

void dfs(int i, int n, int k) {

	if (i > n) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += b[i];
		}
		ma[k] = max(ma[k], sum);
	}
	for (int j = 1; j <= 3; j++) {
		if (m[j] - 1 >= 0) {
			m[j]--;
			b[i] = a[i][j];
			dfs(i + 1, n, k);
			m[j]++;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		m[1] = n / 2;
		m[2] = n / 2;
		m[3] = n / 2;
		for (int j = 1; j <= n; j++) {
			cin >> a[j][1] >> a[j][2] >> a[j][3];
		}
		dfs(1, n, i);
		cout << ma[i] << endl;
	}
}