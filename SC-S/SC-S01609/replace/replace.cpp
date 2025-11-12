#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, q;
int tr[N][150];
set<int> st[N];
int txs;
string s2[N];
string p1, p2;

void ins(string s1, int pos) {
	int p = 0;
	for (int i = 0; i < s1.length(); ++i) {
		if (!tr[p][s1[i]]) {
			tr[p][s1[i]] = ++txs;
		}
		p = tr[p][s1[i]];
	}
	st[p].insert(pos);
//	cout<<p<<" "<<pos<<endl;
}

int fd(string s, string ak) {
	int p = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (!tr[p][s[i]]) {
			return 0;
		}
		p = tr[p][s[i]];
	}
	int _ans = 0;
	for (auto ltt : st[p]) {
//		cout << s2[ltt] << " " << ak << endl;
		if (s2[ltt] == ak) {
			++_ans;
		}
	}
	return _ans;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		string s1;
		cin >> s1 >> s2[i];
		ins(s1, i);
	}
	for (int i = 1; i <= q; ++i) {
		int ans = 0;
		cin >> p1 >> p2;
		if (p1.length() != p2.length() || p1 == p2) {
			printf("0\n");
			continue;
		}
		int l = p1.length(), r = 0;
		for (int j = 0; j < p1.length(); ++j) {
			if (p1[j] != p2[j]) {
				l = min(l, j);
				r = max(r, j);
			}
		}
		for (int j = l; j >= 0; --j) {
			for (int k = r; k < p1.length(); ++k) {
				string t1 = p1.substr(j, k - j + 1);
				string t2 = p2.substr(j, k - j + 1);
//				cout << "*" << t1 << " " << t2 << endl;
				ans += fd(t1, t2);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}