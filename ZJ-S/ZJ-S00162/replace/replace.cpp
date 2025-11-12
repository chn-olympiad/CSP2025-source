#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, q;
string s1[N], s2[N], t1[N], t2[N];
int ans[N], sta[N], en[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s1[i] >> s2[i];
	for (int i = 1; i <= q; i++)
		cin >> t1[i] >> t2[i];
	for (int i = 1; i <= q; i++) {
		bool flag = 0;
		for (int j = 0; j < t1[i].size(); j++) {
			if (flag == 1 && t1[i][j] != t2[i][j]) {
				ans[i] = -1;
				break;
			} 
			if (t1[i][j] != t2[i][j])
				sta[i] = j;
			while (j < t1[i].size() && t1[i][j] != t2[i][j]) {
				if (flag == 0)
					flag = 1;
				j++;
			}
			en[i] = j - 1;
			if (t1[i][j] != t2[i][j])
				en[i] = j;
		}
//		cout << ans[1] << " " << ans[2] << "\n";
		if (ans[i] != -1) {
			for (int j = 1; j <= n; j++) {
				bool xp = 0;
				for (int st = 0; st < t1[i].size(); st++) {
					if (st + s1[j].size() - 1 > t1[i].size())
						break;
					int k;
					for (k = st; k < st + s1[j].size(); k++)
						if (!(s1[j][k - st] == t1[i][k] && s2[j][k - st] == t2[i][k]))
							break;
					if (k >= st + s1[j].size() && k - 1 >= en[i] && st <= sta[i])
						 xp = 1;
				}
				ans[i] += xp;
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		if (ans[i] == -1)
			ans[i] = 0;
		cout << ans[i] << "\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
