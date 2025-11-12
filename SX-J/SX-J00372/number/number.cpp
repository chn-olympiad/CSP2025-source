#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[1000005], tot;
bool b;

bool cmp(int a, int c) {
	return a > c;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			if (s[i] != '0')
				b = 1;
			arr[++tot] = s[i] - '0';
		}
	}
	sort(arr + 1, arr + tot + 1, cmp);
	if (b == 0) {
		cout << 0;
	} else {
		for (int i = 1; i <= tot; i++) {
			cout << arr[i];
		}
	}
	return 0;
}
