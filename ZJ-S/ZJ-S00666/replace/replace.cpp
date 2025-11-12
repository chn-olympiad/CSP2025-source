#include <bits/stdc++.h>
namespace acam {
	struct node {
		int to[27], fail, cnt;
	} t[8388608];
	int ndc = 0;
	void insert(const std::string &s) {
		if(s == "")
			return;
	//	printf("INSERT %s\n", s.c_str());
		int p = 0;
		for(char c : s) {
			int u = c - '`';
			if(t[p].to[u] == 0)
				t[p].to[u] = ++ndc;
			p = t[p].to[u];
		}
		t[p].cnt++;
	}
	void build() {
		std::queue<int> q;
		t[0].fail = 0;
		for(int i = 0; i < 27; i++)
			if(t[0].to[i] != 0)
				t[t[0].to[i]].fail = 0, q.push(t[0].to[i]);
		while(!q.empty()) {
			int u = q.front();
			t[u].cnt += t[t[u].fail].cnt, q.pop();
			for(int i = 0; i < 27; i++)
				if(t[u].to[i] != 0)
					t[t[u].to[i]].fail = t[t[u].fail].to[i],
					q.push(t[u].to[i]);
				else
					t[u].to[i] = t[t[u].fail].to[i];
		}
	//	for(int i = 0; i <= ndc; i++) {
	//		printf("i=%d F=%d C=%d ", i, t[i].fail, t[i].cnt);
	//		for(int j = 0; j < 27; j++)
	//			printf("%d ", t[i].to[j]);
	//		printf("\n");
	//	}
	}
	long long query(const std::string &s) {
		if(s == "")
			return 0;
		long long res = t[0].cnt;
		int p = 0;
		for(char c : s)
			p = t[p].to[c - '`'], res += t[p].cnt;
		return res;
	}
}
void trim(std::string s[3]) {
	if(s[0] == s[1] || s[0].size() != s[1].size())
		return s[0] = s[1] = s[2] = "", void();
	int l = 0, r = s[0].size() - 1;
	while(s[0][l] == s[1][l])
		l++;
	while(s[0][r] == s[1][r])
		r--;
	r++;
	std::string fr = s[0].substr(0, l), bk = s[0].substr(r);
	s[2] = fr + "`" + s[0].substr(l, r - l) + "`" + s[1].substr(l, r - l) + "`" + bk;
}
int n, q, ans[204800];
std::string s[204800][3], t[204800][3];
int main() {
	freopen("replace.in", "rb", stdin);
	freopen("replace.out", "wb", stdout);
	static char buf[5242880];
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%s", buf), s[i][0] = buf,
		scanf("%s", buf), s[i][1] = buf, trim(s[i]),
		acam::insert(s[i][2]);
	acam::build();
	for(int i = 1; i <= q; i++)
		scanf("%s", buf), t[i][0] = buf,
		scanf("%s", buf), t[i][1] = buf, trim(t[i]),
		printf("%lld\n", acam::query(t[i][2]));
	return 0;
}
