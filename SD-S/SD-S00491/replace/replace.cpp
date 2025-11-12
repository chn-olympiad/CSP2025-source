#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
typedef pair<string, string> pss;
int n, q, sl[N], tl, sr[N], tr, ans;
pss h[N];
map<pss, int> mp;

string get(int l, int r, string s) {
	string str = "";
	for(int i = l; i <= r; i++)
		str += s[i];
	return str;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) {
		string a, b;
		cin >> a >> b;
		h[i] = {a, b};
		mp[h[i]]++;
	}
	for(string a, b; q; q--) {
		ans = 0;
		cin >> a >> b;
		int len = a.size();
		tl = 0, tr = 0;
		string s1 = "", s2 = "";
		sl[++tl] = -1, sr[++tr] = len;
		for(int i = 0; i < len; i++) {
			s1 += a[i], s2 += b[i];
			if(s1 == s2) sl[++tl] = i;
		}
		s1 = "", s2 = "";
		for(int i = len - 1; i >= 0; i--) {
			s1 += a[i], s2 += b[i]; 
			if(s1 == s2) sr[++tr] = i;
		}
		for(int i = 1; i <= tl; i++) {
			for(int j = 1; j <= n && (sr[j] > sl[i] + 1); j++)
				ans += mp[{get(sl[i] + 1, sr[i] - 1, a), get(sl[i] + 1, sr[i] - 1, b)}];
		}
		printf("%d\n", ans);
	}
	return 0;
}
