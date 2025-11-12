//! 写挂了, 哈哈
#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 2e5 + 10, S = 5e6 + 10, P = 289253, Q = 1e9 + 7;

struct Node {
	int d{};
	std::unordered_map<int, int> h{};
	Node *fa{}, *to[26]{};
	auto count(int v) -> int {
		auto it = h.find(v);
		return it == h.end() ? 0 : it->second;
	}
};

int n, q, h[S], pw[S], iv[S];
char s[S], s2[S];
Node *rt = new Node{};

auto qpow(int b, int p) -> int {
	int v = 1;
	for (; p; p >>= 1, b = b * (i64)b % Q)
		if (p & 1) v = v * (i64)b % Q;
	return v;
}

void hash(char *s, int *h, int len) {
	for (int i = 1; i <= len; i++) h[i] = (h[i - 1] + s[i] * (i64)pw[i]) % Q;
}

auto find(Node *p, int k, Node *el) -> Node* {
	while (p && !p->to[k]) p = p->fa;
	return p ? p->to[k] : el;
}

void build() {
	std::deque<Node*> q{ rt };
	while (!q.empty()) {
		auto fa = q.front();
		q.pop_front();
		for (int k = 0; k != 26; k++) {
			auto p = fa->to[k];
			if (!p) continue;
			q.emplace_back(p);
			p->d = fa->d + 1, p->fa = find(fa->fa, k, rt);
		}
	}
}

void insert(char *s, int len, int h) {
	Node **p = &rt;
	for (int i = 1; i <= len; i++) {
		p = (**p).to + (s[i] - 'a');
		if (!*p) *p = new Node{};
	}
	(**p).h[h]++;
}

void init() {
	pw[0] = iv[0] = 1;
	for (int i = 1; i != S; i++) pw[i] = pw[i - 1] * (i64)P % Q, iv[i] = iv[i - 1] * (i64)pw[i] % Q;
	i64 v = qpow(iv[S - 1], Q - 2), r = 1;
	for (int i = S; --i; ) iv[i] = iv[i - 1] * v % Q * r % Q, r = r * pw[i] % Q;
}

auto query() -> int {
	int len, r, d, cnt = 0;
	scanf("%s", s2 + 1), hash(s2, h, len = std::strlen(s2 + 1));
	scanf("%s", s + 1);
	if ((int)std::strlen(s + 1) != len) return 0;
	for (d = 1; s[d] == s2[d]; d++);
	for (r = len; s[r] == s2[r]; r--);
	d = r - d + 1;
	Node *p = rt;
	for (int i = 1; i != r; i++) p = find(p, s[i] - 'a', rt);
	for (int i = r; i <= len; i++) {
		p = find(p, s[i] - 'a', rt);
		for (auto fa = p; fa && fa->d >= d; fa = fa->fa) {
			cnt += fa->count((h[i] - h[i - fa->d] + Q) * (i64)iv[i - fa->d] % Q);
		}
	}
	return cnt;
}

auto main() -> int {
	init();
	freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 0, len; i != n; i++) {
		scanf("%s", s + 1), hash(s, h, len = std::strlen(s + 1));
		scanf("%s", s + 1), insert(s, len, h[len]);
	}
	build();
	for (int i = 0; i != q; i++) printf("%d\n", query());
}
