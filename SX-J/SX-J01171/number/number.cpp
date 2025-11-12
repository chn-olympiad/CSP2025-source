#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int N = 1e6+10;
int a[N];

int cmp(int aa, int b) {
	return aa > b;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int j = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[j] = s[i] - 48;
			j++;
		}
	}
	j--;
	sort(a + 1, a + 1 + j, cmp);
	for (int i = 1; i <= j; i++) {
		cout << a[i];
	}
	return 0;
}
