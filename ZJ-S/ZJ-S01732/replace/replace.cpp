#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; w *= (ch == '-') ? -1 : 1, ch = getchar());
	for (; ch >= '0' && ch <= '9'; s = s * 10 + (ch - '0'), ch = getchar());
	return s * w;
}

const int INF = 0x3f3f3f3f3f3f3f3f, N = 5e6 + 5, P = 13331;

int n, Q;
char s[2][N];
set<unsigned int> S;
map<unsigned int, map<unsigned int, map<unsigned int, int> > > mp;

signed main(){
//	freopon("../../csps/down/replace/replace3.in", "r", stdin);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), Q = read();
	for (int i = 1; i <= n; i++){
		scanf("%s%s", s[0] + 1, s[1] + 1);
		int L = strlen(s[0] + 1), l = 1, r = L;
		while (l <= L && s[0][l] == s[1][l]) l++;
		while (l <= r && s[0][r] == s[1][r]) r--;
		if (l <= r){
			unsigned int val1 = 0, val2 = 0, val3 = 0;
			for (int i = l - 1; i >= 1; i--) val1 = val1 * P + (s[0][i] - 'a' + 1);
			for (int i = l; i <= r; i++) val2 = val2 * P + (s[0][i] - 'a' + 1);
			for (int i = l; i <= r; i++) val2 = val2 * P + (s[1][i] - 'a' + 1);
			for (int i = r + 1; i <= L; i++) val3 = val3 * P + (s[0][i] - 'a' + 1);
			mp[val2][val3][val1]++;
//			mp[val2][val3].insert(val1);
		}
	}
	while (Q--){
		scanf("%s%s", s[0] + 1, s[1] + 1);
		int L = strlen(s[0] + 1), L2 = strlen(s[1] + 1);
		if (L != L2){
			puts("0");
			continue;
		}
		S.clear(), S.insert(0);
		int l = 1, r = L, ans = 0;
		unsigned int val = 0, val1 = 0;
		while (l <= L && s[0][l] == s[1][l]) l++;
		while (l <= r && s[0][r] == s[1][r]) r--;
		for (int i = l; i <= r; i++) val = val * P + (s[0][i] - 'a' + 1);
		for (int i = l; i <= r; i++) val = val * P + (s[1][i] - 'a' + 1);
		if (mp.find(val) == mp.end()){
			puts("0");
			continue;
		}
		for (int i = l - 1; i >= 1; i--){
			val1 = val1 * P + (s[0][i] - 'a' + 1);
			S.insert(val1);
		}
		val1 = 0;
		if (mp[val].find(0) != mp[val].end()){
			for (auto x : mp[val][0]){
				if (S.find(x.first) != S.end()) ans += x.second;
			}
		}
		for (int i = r + 1; i <= L; i++){
			val1 = val1 * P + (s[0][i] - 'a' + 1);
			if (mp[val].find(val1) == mp[val].end()) continue;
			for (auto x : mp[val][val1]){
				if (S.find(x.first) != S.end()) ans += x.second;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

