#include <bits/stdc++.h>
using namespace std;

string a;
int j = 1, num[1000001];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> a;
	for (auto i : a) {
		if (i <= 58) {
			num[j] = i - 48;
			j++;
		}
	}
	sort(num + 1, num + j);
	if (num[j - 1] != 0)
		for (j; j > 1; j--) {
			cout << num[j - 1];
		} else
		cout << 0;

}
