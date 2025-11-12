#include <bits/stdc++.h>
using namespace std;
int n;
int j;
int a[100005];//部门一好感度
int b[100005];//部门二好感度
int c[100005];//部门三好感度

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n;
	int x, y, z;

	for (int i = 1; i <= n; i++) {
		cin >> j;
		a[100005] = {0};
		for (int m = 1; m <= j; m++) {
			cin >> a[x] >> y >> z;
		}
		sort(a + 1, a + j + 1);
		cout << a[0] + a[1];
	}

	return 0;
}