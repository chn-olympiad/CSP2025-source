#include <bits/stdc++.h>
using namespace std;
string s;
char ans[1000005];
int sum = 0;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < int(s.size()); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			ans[sum] = s[i], sum++;
	}
	sort(ans, ans + sum, cmp);
	if (ans[0] == '0')
		cout << 0;
	else {
		for (int i = 0; i <= sum; i++)
			cout << ans[i];
	}
	//啊~~~！喷气背包出故障啦！
	//诶？没事。幸好——，幸好我昨天—诶—买了一个星星礼盒。
	return 0;
}
