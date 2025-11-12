#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
string s;
int arr[N], cnt, tot;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			arr[++cnt] = s[i] - '0';
		if (s[i] >= '1' && s[i] <= '9')
			tot++;
	}
	if (tot > 0) {
		sort(arr + 1, arr + 1 + cnt, cmp);
		for (int i = 1; i <= cnt; i++)
			cout << arr[i];
	} else
		cout << 0;
	return 0;
}

