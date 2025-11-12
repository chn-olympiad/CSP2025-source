#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5, L = 2005;
int n, q;
int fail[N][2][L];
string t[N][2];
string s[2];
int mrk[N][2][L];
void init() {
	for(int cur = 1; cur <= n; cur++) {
		for(int j = 0, i = 0; j < t[cur][0].size(); j++) {
			while(t[cur][0][j] != t[cur][0][i] && i != 0) i = fail[cur][0][i - 1];
			if(j && t[cur][0][j] == t[cur][0][i]) i++; 
			fail[cur][0][j] = i;
		}
		for(int j = 0, i = 0; j < t[cur][1].size(); j++) {
			while(t[cur][1][j] != t[cur][1][i] && i != 0) i = fail[cur][1][i - 1];
			if(j && t[cur][1][j] == t[cur][1][i]) i++; 
			fail[cur][1][j] = i;
		}
	}
}
int kmp() {
	int ans = 0;
	memset(mrk, 0, sizeof(mrk));
	for(int cur = 1; cur <= n; cur++) {
		for(int j = 0, i = 0; j < s[0].size(); j++) {
			while(s[0][j] != t[cur][0][i] && i != 0) i = fail[cur][0][i - 1];
			if(s[0][j] == t[cur][0][i]) i++;
			if(i == t[cur][0].size()) mrk[cur][0][j] = 1;
		}
		for(int j = 0, i = 0; j < s[1].size(); j++) {
			while(s[1][j] != t[cur][1][i] && i != 0) i = fail[cur][1][i - 1];
			if(s[1][j] == t[cur][1][i]) i++;
			if(i == t[cur][1].size()) mrk[cur][1][j] = 1;
		}
		for(int j = 0; j < s[1].size(); j++) {
			if(mrk[cur][0][j] & mrk[cur][1][j]) {
				string new1 = s[0].substr(0, j - t[cur][0].size() + 1) + t[cur][1] + s[0].substr(j + 1, s[0].size() - j - 1);
				if(new1 == s[1]) ans++;
			}
		}
	}
	
	return ans;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) {
		cin >> t[i][0] >> t[i][1];
	}
	init();
	while(q--) {
		cin >> s[0] >> s[1];
		int ans = 0;
		if(s[0].size() != s[1].size()) printf("0\n");
		else {
			ans = kmp();
			printf("%d\n", ans);
		}
	}
	return 0;
} 
