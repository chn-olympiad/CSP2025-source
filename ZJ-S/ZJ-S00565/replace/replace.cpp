#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
string s1[N], s2[N];
int len[N];
char cha[200];
int f[N * 3], e[N * 3];
	int n, T;
void st () {
	while(T--) {
		string t1, t2;
		cin >> t1 >> t2;
		int ans = 0;
		int lth = t1.size();
		if(lth != t2.size()) { printf("0\n"); continue; }
		for (int i = 1; i <= n; ++i) {
			for (int p = 0; p < lth; ++p) {
				if(t1[p] == s1[i][0]) {
					string t3 = t1;
					int q = p + 1, j;
					t3[p] = s2[i][0];
					for (j = 1; j < len[i] && q < lth; ++j, ++q)
						if(t1[q] != s1[i][j]) break;
						else {
							t3[q] = s2[i][j];
						}
					if(j < len[i]) continue;
					if(t3 == t2) {
						++ans;
						break;
					}
				}
			}
		}
		printf ("%d\n", ans);
	}
}
int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf ("%d %d", &n, &T);
	char stress = 'b';
	bool flag = 0;
	for (int i = 1; i <= n; ++i){
		cin >> s1[i] >> s2[i];
		len[i] = s1[i].size();
		if(!flag){
			int k = 0;
			for (int j = 0; j < len[i] && !flag; ++j){
				if(s1[i][j] != 'b' && s1[i][j] != 'a') flag = true;
				k +=(s1[i][j] == 'b');
				if(k >= 2) flag = true;
			}
			k = 0;
			for (int j = 0; j < len[i] && !flag; ++j){
				if(s2[i][j] != 'b' && s2[i][j] != 'a') flag = true;
				k +=(s2[i][j] == 'b');
				if(k >= 2) flag = true;
			}
		}
	}
	if(flag) { st(); return 0;}
	for (int i = 1; i <= n; ++i) {
		int k1 = 0, k2 = 0;
		for (int j = 0; j < len[i]; ++j)
			if(s1[i][j] == stress) { k1 = j; break; }
		for (int j = 0; j < len[i]; ++j)
			if(s2[i][j] == stress) { k2 = j; break; }
		if(k1 == k2 && k1 == 0) f[i] = -2e9;
		else f[i] = k1, e[i] = k2;
	}
	while(T--) {
		string t1, t2;
		cin >> t1 >> t2;
		int k1 = 0, k2 = 0;
		int lth1 = t1.size(), lth2 = t2.size();
		if(lth1 != lth2) { printf("0\n"); continue; }
		for (int i = 0; i < lth1; ++i)
			if(t1[i] == stress) { k1 = i; break; }
		for (int i = 0; i < lth2; ++i)
			if(t2[i] == stress) { k2 = i; break; }
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			if(k1 == k2 && k1 == 0 && f[i] == -2e9)
				++sum;
			else if(k1 + len[i] - f[i] <= lth1 && k1 >= f[i] && f[i] - e[i] == k1 - k2) {
				++sum;
			}
		}
		printf("%d\n", sum);
	}
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/
