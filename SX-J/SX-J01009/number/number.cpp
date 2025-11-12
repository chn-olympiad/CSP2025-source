#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];

bool cmp(int x, int y) {
	return x > y;
}
string ans;

int main() {
	freopen("number.in", "r", stdin);
	freopen("numdber.out", "w", stdout);
	cin >> s;
	int cnt = 1;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			a[cnt] = int(s[i] - '0');
			cnt++;
		}
	}
	sort(a + 1, a + cnt, cmp);
	for (int i = 1; i < cnt; i++) {
		ans = ans + char(a[i] + '0');
	}
	cout << ans;
	return 0;
}
/*
1.读入string
2.将数字存入数组
3.sort从大到小
4.整理成long long
*/