#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 100;
int n, q;
char s1[N], s2[N];
struct Trie {
	int ch[26][N], fail[N], dep[N], rt, cnt;
	vector<int> v[N];
	void ins(char s[], int id) {
		int p = rt, len = strlen(s + 1);
		for (int i = 1; i <= len; i++) {
//			cerr << p << ' ';
			if (ch[s[i] - 'a'][p]) p = ch[s[i] - 'a'][p];
			else ch[s[i] - 'a'][p] = ++cnt, dep[cnt] = dep[p] + 1, p = cnt;
//			cerr << s[i] << ' ' << p << endl;
		}
		v[p].push_back(id);
		return;
	}
	void get_fail(int p) {
//		cerr << p << ' ' << fail[p] << endl;
		if (p == rt) {
			for (int i = 0; i < 26; i++) 
				if (ch[i][p])
					fail[ch[i][p]] = rt;
			for (int i = 0; i < 26; i++)
				if (ch[i][p])
					get_fail(ch[i][p]);
			return;
		}
		for (int i = 0; i < 26; i++)
			if (ch[i][p]) {
				int t = p;
				while (fail[t] && !ch[i][fail[t]])
					t = fail[t];
				
				if (ch[i][fail[t]]) fail[ch[i][p]] = ch[i][fail[t]];
//				else fail[ch[i][p]] = fail[t];
			}
		for (int i = 0; i < 26; i++)
			if (ch[i][p])
				get_fail(ch[i][p]);
		return;
	}
}T1, T2;
inline int read() {
	int now = 0, nev = 1;
	char ch = getchar();
	while (ch < '0' || '9' < ch) {
		if (ch == '-') nev = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		now = (now << 1) + (now << 3) + (ch & 15);
		ch = getchar();
	}
	return nev * now;
}
int Count(vector<int> x, vector<int> y) {
	int cnt = 0;
	if (x.size() < y.size()) 
		for (int v : x){
			auto it = lower_bound(y.begin(), y.end(), v);
			if (it == y.end()) continue;
			cnt += (*it == v);
		}
	else
		for (int v : y) {
			auto it = lower_bound(x.begin(), x.end(), v);
			if (it == x.end()) continue;
			cnt += (*it == v);
		}
	return cnt; 
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(); q = read();
	for (int i = 1; i <= n; i++) {
		scanf ("%s", s1 + 1);
		scanf ("%s", s2 + 1);
		T1.ins(s1, i);
		T2.ins(s2, i);
	}
	T1.get_fail(T1.rt); T2.get_fail(T2.rt);
	for (int _ = 1; _ <= q; _++) {
		scanf ("%s", s1 + 1);
		scanf ("%s", s2 + 1);
		if (strlen(s1 + 1) != strlen(s2 + 1)) { puts("0"); continue; }
		int p1 = T1.rt, p2 = T2.rt, len = strlen(s1 + 1);
		int st = 0, ed = 0, res = 0, la = 0;
		for (int i = 1; i <= len; i++) 
			if (s1[i] != s2[i]) {
				if (!st) st = i;
				ed = i;
			}
		la = ed - st + 1;
		for (int i = 1; i < ed; i++) {
			int v1 = s1[i] - 'a';
			
//			cerr << p1 << ' ';
			
			if (T1.ch[v1][p1]) p1 = T1.ch[v1][p1];
			else {
				while (T1.fail[p1] && !T1.ch[v1][T1.fail[p1]])
					p1 = T1.fail[p1];
				p1 = T1.ch[v1][T1.fail[p1]];
			}
			int v2 = s2[i] - 'a';
			if (T2.ch[v2][p2]) p2 = T2.ch[v2][p2];
			else {
				while (T2.fail[p2] && !T2.ch[v2][T2.fail[p2]])
					p2 = T2.fail[p2];
				p2 = T2.ch[v2][T2.fail[p2]];
			}
			
//			cerr << s1[i] << ' ' << p1 << endl;
		}
		for (int i = ed; i <= len; i++) {
			int v1 = s1[i] - 'a';
			if (T1.ch[v1][p1]) p1 = T1.ch[v1][p1];
			else {
				while (T1.fail[p1] && !T1.ch[v1][T1.fail[p1]])
					p1 = T1.fail[p1];
				p1 = T1.ch[v1][T1.fail[p1]];
			}
			
//			cerr << s1[i] << ' ' << p1 << endl;
			
			int v2 = s2[i] - 'a';
			if (T2.ch[v2][p2]) p2 = T2.ch[v2][p2];
			else {
				while (T2.fail[p2] && !T2.ch[v2][T2.fail[p2]])
					p2 = T2.fail[p2];
				p2 = T2.ch[v2][T2.fail[p2]];
			}
//			if (T1.dep[p1] != T2.dep[p2]) continue;
//			cout << p1 << ' ' << p2 << endl;
			int tmp1 = p1, tmp2 = p2;
			while (tmp1 && tmp2) {
				if (T1.dep[tmp1] < la || T2.dep[tmp2] < la) break;
				if (T1.dep[tmp1] == T2.dep[tmp2] && T1.dep[tmp1] >= la)
					res += Count(T1.v[tmp1], T2.v[tmp2]);
				if (T1.dep[tmp1] > T2.dep[tmp2]) tmp1 = T1.fail[tmp1];
				else tmp2 = T2.fail[tmp2];
			}
		}
		printf("%d\n", res);
	} 
	return 0;
}
