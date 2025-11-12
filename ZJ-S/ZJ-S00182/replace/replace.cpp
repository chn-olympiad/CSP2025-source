#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
constexpr int MAXN = 2e5, MAXS = 5e6;
constexpr int B = 20081107;

int cnt = 1;
struct Node {
	int son[30], fail, cnt;
	std::string to;
} t[MAXS + 5];

void insert(char *a, int len, std::string to) {
	int p = 1;
	for (int i = 1; i <= len; i++) {
		int ch = a[i] - 'a';
		if (!t[p].son[ch]) t[p].son[ch] = ++cnt;
		p = t[p].son[ch];
	}
	t[p].cnt++;
	t[p].to = to;
}

void build() {
	std::queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int p = q.front(); q.pop();

		if (p > 1 && !t[p].fail) t[p].fail = 1;
		for (int i = 0; i < 26; i++) {
			if (!t[p].son[i]) continue;
			int tmp = p;
			while (tmp > 1 && !t[t[tmp].fail].son[i]) tmp = t[tmp].fail;
			t[t[p].son[i]].fail = t[t[tmp].fail].son[i];
			q.push(t[p].son[i]);
		}
	}
}

bool check(char *ch, int len, int end, std::string ins, std::string target) {
	int lenins = ins.length();
	for (int i = 1; i < end - lenins + 1; i++) {
		if (ch[i] != target[i - 1]) return false;
	}
	for (int i = end + 1; i <= len; i++) {
		if (ch[i] != target[i - 1]) return false;
	}
	int st = end - lenins + 1;
	for (int i = end - lenins + 1; i <= end; i++) {
		if (ins[i - st] != target[i - 1]) return false;
	}
	return true;
}

int statistic(char *ch, int len, std::string to) {
	int p = 1, ans = 0;
	for (int i = 1; i <= len; i++) {
		int c = ch[i] - 'a';
		while (p > 1 && !t[p].son[c]) p = t[p].fail;
		if (t[p].son[c]) {
			p = t[p].son[c];
			int tmp = p;
			while (tmp > 1) {
				if (t[tmp].cnt && check(ch, len, i, t[tmp].to, to)) ans += t[tmp].cnt;
				tmp = t[tmp].fail;
			}
		}
	}
	return ans;
}

int n, q;
char st[MAXS + 5];
std::string to;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf(" %s", st + 1);
		std::cin >> to;
		insert(st, std::strlen(st + 1), to);
	}
	build();

	while (q--) {
		scanf(" %s", st + 1);
		std::cin >> to;
		int lena = std::strlen(st + 1), lenb = to.length();
		if (lena != lenb) { printf("0\n"); continue; }

		int ans = statistic(st, lena, to);
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
constexpr int MAXN = 2e5, MAXS = 5e6;
constexpr int B = 20081107;

struct trie {
	int cnt = 1;
	struct Node {
		int son[30], cnt, fail;
	};
	std::vector<Node> t;

	void insert(std::string a) {
		if (t.empty()) t.resize(2);
		int len = a.size();
		int p = 1;
		for (int i = 1; i <= len; i++) {
			int ch = a[i] - 'a';
			if (!t[p].son[ch]) t[p].son[ch] = ++cnt, t.resize(t.size() + 1);
			p = t[p].son[ch];
		}
		t[p].cnt++;
	}

	void build() {
	std::queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int p = q.front(); q.pop();

		if (p > 1 && !t[p].fail) t[p].fail = 1;
		for (int i = 0; i < 26; i++) {
			if (!t[p].son[i]) continue;
			int tmp = p;
			while (tmp > 1 && !t[t[tmp].fail].son[i]) tmp = t[tmp].fail;
			t[t[p].son[i]].fail = t[t[tmp].fail].son[i];
			q.push(t[p].son[i]);
		}
	}
}

	bool find(std::string s) {
		int len = s.size(), p = 1;
		for (int i = 1; i <= len; i++) {
			int c = s[i] - 'a';
			while (p > 1 && !t[p].son[c]) p = t[p].fail;
			if (t[p].son[c]) { p = t[p].son[c]; }
			else return false;
		}
		return true;
	}
};

int cnt = 1;
struct Node {
	int son[30], fail, cnt, len;
	trie to;
} t[MAXS + 5];

void insert(char *a, int len, std::string to) {
	int p = 1;
	for (int i = 1; i <= len; i++) {
		int ch = a[i] - 'a';
		if (!t[p].son[ch]) t[p].son[ch] = ++cnt;
		p = t[p].son[ch];
	}
	t[p].cnt++;
	t[p].len = to.length();
	t[p].to.insert(to);
}

void build() {
	std::queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int p = q.front(); q.pop();

		if (p > 1 && !t[p].fail) t[p].fail = 1;
		for (int i = 0; i < 26; i++) {
			if (!t[p].son[i]) continue;
			int tmp = p;
			while (tmp > 1 && !t[t[tmp].fail].son[i]) tmp = t[tmp].fail;
			t[t[p].son[i]].fail = t[t[tmp].fail].son[i];
			q.push(t[p].son[i]);
		}
	}
}

bool check(char *ch, int len, int end, int lenins, trie ins, std::string target) {
	for (int i = 1; i < end - lenins + 1; i++) {
		if (ch[i] != target[i - 1]) return false;
	}
	for (int i = end + 1; i <= len; i++) {
		if (ch[i] != target[i - 1]) return false;
	}
	int st = end - lenins + 1;
	std::string tmp;
	for (int i = end - lenins + 1; i <= end; i++) {
		tmp += target[i - 1];
	}
	return ins.find(tmp);
}

int statistic(char *ch, int len, std::string to) {
	int p = 1, ans = 0;
	for (int i = 1; i <= len; i++) {
		int c = ch[i] - 'a';
		printf("%d\n", c);
		while (p > 1 && !t[p].son[c]) p = t[p].fail;
		if (t[p].son[c]) {
			p = t[p].son[c];
			int tmp = p;
			while (tmp > 1) {
				if (t[tmp].cnt && check(ch, len, i, t[tmp].len, t[tmp].to, to)) ans += t[tmp].cnt;
				tmp = t[tmp].fail;
			}
		}
	}
	return ans;
}

int n, q;
char st[MAXS + 5];
std::string to;

int main() {
	freopen("replace/replace3.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf(" %s", st + 1);
		std::cin >> to;
		int lena = std::strlen(st + 1);
		insert(st, std::strlen(st + 1), to);
		for (int i = 1; i <= lena; i++) st[i] = '\0';
	}
	build();

	while (q--) {
		scanf(" %s", st + 1);
		std::cin >> to;
		int lena = std::strlen(st + 1), lenb = to.length();
		if (lena != lenb) { printf("0\n"); continue; }


		int ans = statistic(st, lena, to);
		printf("%d\n", ans);
		for (int i = 1; i <= lena; i++) st[i] = '\0';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/