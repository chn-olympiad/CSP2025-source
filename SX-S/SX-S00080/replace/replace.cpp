#include <bits/stdc++.h>
using namespace std;
const long long p1 = 1e9+40, p2 = 1e9+411;
const int maxl = 5e6+5, maxn = 2e5+5;

struct H {
	long long h1, h2;
	bool operator==(H x) {
		return h1 == x.h1&&h2 == x.h2;
	}
};

struct node {
	int c[26] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	            last
	            = 0, fa;
	list<int> str;
} act[maxl];

struct strpair {
	vector<char> s1, s2;
	int s, t, l;
	H h;
} sps[maxn];
int n, q, actl = 2, spl = 0;
char str[maxl], t1[maxl], t2[maxl];

inline H vmakeh(vector<char>::iterator s, vector<char>::iterator t) {
	H h = {0, 0};
	for (vector<char>::iterator i = s; i != t; i++)
		h.h1 = (h.h1 * 26 + *i - 'a') % p1, h.h2 += (h.h2 * 26 + *i - 'a') % p2;
	return h;
}

inline H cmakeh(char *s, char *t) {
	H h = {0, 0};
	for (char * i = s; i != t; i++)
		h.h1 = (h.h1 * 26 + *i - 'a') % p1, h.h2 += (h.h2 * 26 + *i - 'a') % p2;
	return h;
}

inline bool msps() {
	strpair sp;
	int l = 0;
	scanf(" %s", str);
	while (str[l] != 0)
		sps[spl].s1.push_back(str[l]), str[l] = 0, l++;
	l = 0;
	scanf(" %s", str);
	while (str[l] != 0)
		sps[spl].s2.push_back(str[l]), str[l] = 0, l++;
	for (sps[spl].s = 0; sps[spl].s < l && sps[spl].s1[sps[spl].s] == sps[spl].s2[sps[spl].s];)
		sps[spl].s++;
	if (sps[spl].s == l) {
		sps[spl].s1.clear(), sps[spl].s2.clear(), sps[spl].s = 0;
		return 0;
	}
	for (sps[spl].t = l - 1; sps[spl].s1[sps[spl].t] == sps[spl].s2[sps[spl].t];)
		sps[spl].t--;
	sps[spl].l = l;
	sps[spl].h = vmakeh(sps[spl].s2.begin() + sps[spl].s, sps[spl].s2.begin() + sps[spl].t);
	spl++;
	return 1;
}

inline void mact(int fa, char c) {
	act[actl].fa = fa, act[fa].c[c - 'a'] = actl;
	for (act[actl].last = act[fa].last; act[act[actl].last].c[c - 'a'] == -1;)
		act[actl].last = act[act[actl].last].last;
	act[actl].last = act[act[actl].last].c[c - 'a'];
	actl++;
}

inline void makeac() {
	int k = 1, l = sps[spl - 1].l;
	for (int i = 0; i < l; i++)
		if (act[k].c[sps[spl - 1].s1[i] - 'a'] == -1)
			mact(k, sps[spl - 1].s1[i]), k = act[k].c[sps[spl - 1].s1[i] - 'a'];
		else
			k = act[k].c[sps[spl - 1].s1[i] - 'a'];
	act[k].str.push_back(spl - 1);
}

inline void init() {
	for (int	i = 0; i < 26; i++)
		act[0].c[i] = 1;
	act[0].fa = act[0].last = act[1].fa = act[1].last = 0;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		if (msps())
			makeac();
}

int main() { //t1!=t2
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	init();
	for (int i = 0; i < q; i++) {
		scanf(" %s %s", t1, t2);
		int l1, l2, s, t, k = 1, ans = 0;
		for (l1 = 0; t1[l1] != 0;)
			l1++;
		for (l2 = 0; t2[l2] != 0;)
			l2++;
		if (l1 != l2) {
			printf("0\n");
			continue;
		}
		for (s = 0; t1[s] == t2[s];)
			s++;
		for (t = l1 - 1; t1[t] == t2[t];)
			t--;
		H h = cmakeh(t2 + s, t2 + t);
		for (int j = 0; j < l1; j++) {
			while (act[k].c[t1[j] - 'a'] == -1)
				k = act[k].last;
			k = act[k].c[t1[j] - 'a'];
			if (act[k].str.size() != 0) {
				for (list<int>::iterator l = act[k].str.begin(); l != act[k].str.end(); l++)
					if (j + sps[*l].s - sps[*l].l + 1 == s && j + sps[*l].t - sps[*l].l + 1 == t && sps[*l].h == h)
						ans++;
				j = j - sps[act[k].str.front()].l + 1, k = 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
