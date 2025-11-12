#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a;
int num[20];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int i = 0;
	while (a[i]) {
		if (a[i] >= '0' && a[i] <= '9') {
			num[a[i] - '0']++;
		}
		i++;
	}
	for (int j = 9; j >= 0; j--) {
		while (num[j]) {
			cout << j;
			num[j]--;
		}
	}
	return 0;
}
