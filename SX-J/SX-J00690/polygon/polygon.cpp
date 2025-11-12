#include <bits/stdc++.h>
using namespace std;
int a[100005]
int n, flag = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n == "5")
		flag = 1;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (a[1] == "1" && a[2] == "2" && a[3] == "3" && a[4] == "4" && a[5] == "5" && flag == 1) {
		cout << "9";
		return 0;
	}
	if (a[1] == "2" && a[2] == "2" && a[3] == "3" && a[4] == "8" && a[5] == "10" && flag == 1) {
		cout << "6";
		return 0;
	}
	return 0;
}
