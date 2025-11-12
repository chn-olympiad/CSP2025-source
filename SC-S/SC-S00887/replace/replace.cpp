#include<bits/stdc++.h>
using namespace std;
int n, q, ans;
struct node {
	string s1, s2;
} kmp[10005];
bool check(string s1, string s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	bool flag = 1;
	for (int l = 0, r = l + len2 - 1; l < len1 - len2; l++) {
		flag = 1;
		for (int i = l; i <= r; i++)
			if (s1[i] != s2[i]) {
				flag = 0;
				break;
			}
	}
	if (flag) return 1;
	else return 0;
}
int find(string s1, string s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	bool flag = 1;
	for (int l = 0, r = l + len2 - 1; l < len1 - len2; l++) {
		flag = 1;
		for (int i = l; i <= r; i++)
			if (s1[i] != s2[i]) {
				flag = 0;
				break;
			}
		if (flag) return l;
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> kmp[i].s1 >> kmp[i].s2;
	while (q--) {
		ans = 0;
		string s3, s4;
		cin >> s3 >> s4;
		for (int i = 1; i <= n; i++) {
			if (check(s3, kmp[i].s1) && check(s4, kmp[i].s2))
				if (find(s3, kmp[i].s1) == find(s4, kmp[i].s2))
					ans++;
		}
		cout << ans << endl;
	}
	return 0;
}