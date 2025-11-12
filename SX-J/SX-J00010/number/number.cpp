#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
vector<int> ans;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
		if ('0' <= s[i] && s[i] <= '9')
			ans.push_back(s[i] - '0');
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i];
	return 0;
}