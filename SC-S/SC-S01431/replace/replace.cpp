#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n, q;
string s[N][3], s1, s2;
int pos[N][3];

int solve1() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		string before = s[i][1], after = s[i][2];
		if (s1.size() - before.size() + after.size() != s2.size())	continue;
		for (int l = 0; l + before.size() <= s1.size(); l++) {
			if (s1.substr(l, before.size()) != before)	continue;
			string t1 = s1.substr(0, l) + after + s1.substr(l + before.size(), s1.size() - l + before.size());
			string t2 = s2.substr(0, l) + s2.substr(l, before.size()) + s2.substr(l + after.size(), s2.size() - l + after.size());
//			cout << t1 << " " << t2 << "\n";
			if (t1 == t2)	ans++;
		}
	}
	return ans;
}
int solve() {
	if (s1.size() + s2.size() <= 2000 || q == 1)	return solve1();
	int len1, len2, ans = 0;
	for (int j = 0; j < s1.size(); j++)
		if (s1[j] == 'b') {
			len1 = j;
			break;
		}
	for (int j = 0; j < s2.size(); j++)
		if (s2[j] == 'b') {
			len2 = j;
			break;
		}

	for (int i = 1; i <= n; i++) {
		string before = s[i][1], after = s[i][2];
		for (int j = 0; j < before.size(); j++)
			if (before[j] == 'b') {
				pos[i][1] = j;
				break;
			}
		for (int j = 0; j < after.size(); j++)
			if (after[j] == 'b') {
				pos[i][2] = j;
				break;
			}
	}
	for (int i = 1; i <= n; i++) {
		string before = s[i][1], after = s[i][2];
		for (int j = 0; j < before.size(); j++)
			if (before[j] == 'b') {
				pos[i][1] = j;
				break;
			}
		for (int j = 0; j < after.size(); j++)
			if (after[j] == 'b') {
				pos[i][2] = j;
				break;
			}
//		cout << pos[i][1] << " " << pos[i][2] << "\n";
		if (len1 - pos[i][1] + pos[i][2] == len2 && len1 >= pos[i][1] && s1.size() - len1 - 1 - (before.size() - pos[i][1] - 1) + (after.size() - pos[i][2] - 1) == s2.size() - len2 - 1 && s1.size() - len1 - 1 >= (before.size() - pos[i][1] - 1))	ans++;
	}
	return ans;
}

signed main() {
	cin.tie(0), cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)	cin >> s[i][1] >> s[i][2];
	while (q--) {
		cin >> s1 >> s2;
		cout << solve() << "\n";
	}
	/*
	2 2
	aab aba
	aba baa
	aab aba
	aaabaaaa aabaaaaa

	*/



	return 0;
}