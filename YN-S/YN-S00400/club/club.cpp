#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
int t;
int n;
int stu1[100000 + 5];
int stu2[100000 + 5];
int stu3[100000 + 5];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		long long ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> stu1[i] >> stu2[i] >> stu3[i];
		}
		sort(stu1 + 1, stu1 + n + 1, cmp);
		for (int i = 1; i <= n / 2; i++) {
			ans += stu1[i];
		}
		cout << ans << endl;
	}
	return 0;
}