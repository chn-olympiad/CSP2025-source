#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
struct trans {
	string a, b;
} tr[N];
int find (string m, string s, int bg) {
	int l = s.size (), lt = m.size (), flag;
	for (int i = bg; i < l - lt + 1; i ++ ) {
		if (s[i] == m[0]) {
			flag = 1;
			for (int j = 0; j < lt; j ++ ) {
				if (s[i + j] != m[j]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				return i;
			}
		}
	}
	return -1;
}
int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	int n, q, cnt = 0;
	string qa, qb, as;
	cin >> n >> q;
	for (int i = 0; i < n; i ++ ) {
		cin >> tr[i].a >> tr[i].b;
	}
	if (q > 2000) {
		for (int i = 0; i < q; i ++ ) {
			cout << 0 << endl;
		}
		return 0;
	}
	while (q -- ) {
		cnt = 0;
		cin >> qa >> qb;
		if (qa == qb) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < n; i ++ ) {
			int pl = 0;
			for (int k = 1; k <= qa.size (); k ++ ) {
				int l1 = find (tr[i].a, qa, pl);
				pl = l1 + 1;
				if (l1 == -1) {
					break;
				}
				as = "";
				for (int j = 0; j < l1; j ++ ) {
					as += qa[j];
				}
				as += tr[i].b;
				for (int j = l1 + tr[i].b.size (); j < qa.size (); j ++ ) {
					as += qa[j];
				}
				if (as == qb){
					cnt ++ ;
				}
			}
			
		}
		cout << cnt << endl;
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
