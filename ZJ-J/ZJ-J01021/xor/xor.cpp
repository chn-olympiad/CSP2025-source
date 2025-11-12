#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, target, ans = 0;
	cin >> n >> target;
	vector<int> a(n + 1);
	set<int> pre;
	pre.insert(0);
	int prev = 0;
	for (int i = 1; i <= n; i += 1) {
		cin >> a[i];
		prev = prev ^ a[i];
		if (pre.find(prev ^ target) != pre.end()) {
			pre.clear();
			pre.insert(0);
			prev = 0;
			ans += 1;
			continue;
		}
		pre.insert(prev);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
