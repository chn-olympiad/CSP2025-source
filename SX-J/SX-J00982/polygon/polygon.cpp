#include <bits/stdc++.h>
using namespace std;
int a[5005], n;
bool v[5005];
vector<int> arr;
int ans;

void dfs(int side, int step, int last) {
	if (step == side) {
		int maxn = 0, sum = 0;
		for (int i = 0; i < arr.size(); i++) {
			maxn = max(maxn, arr[i]);
			sum += maxn;
//			cout << arr[i];
		}
//		cout << endl;
		if (sum > maxn * 2)
			ans++;
		return;
	}
	for (int i = last; i <= n; i++) {
		if (v[i] == 0) {
			v[i] = 1;
			arr.push_back(a[i]);
			dfs(side, step + 1, i);
			v[i] = 0;
			arr.pop_back();
		}
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 3; i <= n; i++) {
		dfs(i, 0, 1);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
