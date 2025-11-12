#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, ans;
string s;
int arr[1000086];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	if (s.find("0") == -1) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (m == n) {
		int unsuc = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j] <= unsuc ) {
				continue;
			}
			if (s[j] == '1')
				unsuc++;
			else
				ans++;
		}
	}
	if (ans != n)
		cout << 0;
	else
		cout << 1;
	return 0;
}
