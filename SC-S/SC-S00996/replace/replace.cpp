#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull qwq = 137;
int n, q;
ull hash_a[200005];
ull hash_b[200005];
ull h_fir;
ull h_ans;
ull qpow[5000005];
struct node {
	unordered_map<int, int> mp;
	int fail;
	vector<int> flag;
	int vis;
} trie[5000005];
int tot = 1;
void insert(string s, int num) {
	int len = s.size();
	int p = 1;
	for (int i = 0; i < len; i++) {
		int k = s[i] - 'a';
		if (!trie[p].mp.count(k)) trie[p].mp[k] = ++tot;
		p = trie[p].mp[k];
	}
	trie[p].flag.push_back(num);
}
int find(int x, int k) {
	for (; x > 1 && !trie[x].mp.count(k); x = trie[x].fail);
	if (!trie[x].mp.count(k)) return 1;
	return trie[x].mp[k];
}
void get_fail() {
	for (int i = 0; i < 26; i++) trie[0].mp[i] = 1;
	trie[1].fail = 0;
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		int fa_fail = trie[u].fail;
		for (auto &i : trie[u].mp) {
			int k = i.first, v = i.second;
			trie[v].fail = find(fa_fail, k);
			que.push(v);
		}
	}
}
int que = 2;
int query(char *s) {
	int len = strlen(s);
	que++;
	int p = 1;
	int res = 0;
	for (int i = 0; i < len; i++) {
		int k = s[i] - 'a';
		p = find(p, k);
		int v;
		for (v = p; v > 1 && trie[v].vis != que; v = trie[v].fail) {
			trie[v].vis = que;
			if (trie[v].flag.size()) {
				for (int o : trie[v].flag) {
					ull temp = hash_a[o];
					ull sum = hash_b[o];
					if (h_fir + (sum - temp) * qpow[len - i - 1] == h_ans) res++;
				}
			}
		}
	}
	return res;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	clock_t start = clock();
	scanf("%d%d", &n, &q);
	qpow[0] = 1;
	for (int i = 1; i <= 5000000; i++) qpow[i] = qpow[i - 1] * qwq;
	char s[5000005];
	int sp = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		ull sum = 0;
		int len = strlen(s);
		for (int j = 0; j < len; j++) {
			sum = sum * qwq + s[j];
		}
		hash_a[i] = sum;
		insert(s, i);
		cin >> s;
		sum = 0;
		len = strlen(s);
		for (int j = 0; j < len; j++) {
			sum = sum * qwq + s[j];
		}
		hash_b[i] = sum;
	}
	get_fail();
	char ss[5000005];
	for (int i = 1; i <= q; i++) {
		scanf("%s", s);
		scanf("%s", ss);
		int len = strlen(s);
		sp += len;
		h_fir = 0;
		for (int j = 0; j < len; j++) {
			h_fir = h_fir * qwq + s[j];
		}
		h_ans = 0;
		for (int j = 0; j < len; j++) {
			h_ans = h_ans * qwq + ss[j];
		}
		printf("%d\n", query(s));
	}
	clock_t end = clock();
	cout << end - start << '\n';
	cout << sp << '\n';
	return 0;
}