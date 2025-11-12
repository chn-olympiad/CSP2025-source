#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30;
int cnt[MAXN];
char temp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	while (cin >> temp) {
		if (temp >= 'a' && temp <= 'z') {
			continue;
		}
		cnt[temp - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= cnt[i]; j++) {
			cout << i;
		}
	}
	cout << endl;
	return 0;
}
// AC