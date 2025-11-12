#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
string str1;
int ans[MAXN], cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> str1;
	int n = str1.size();
	for (int i = 0; i < n; i++)
		if (str1[i] >= '0' && str1[i] <= '9')
			ans[++cnt] = str1[i] - '0';
	sort(ans + 1, ans + cnt + 1);
	if (ans[cnt] == 0)
		cout << "0";
	else
		for (int i = cnt; i >= 1; i--)
			cout << ans[i];
	return 0;
}
