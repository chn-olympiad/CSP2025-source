#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 5000010
using namespace std;
struct Node {
	int end;
	int son[26];
};
Node tree1[MAXN], tree2[MAXN];
int cnt1 = 1, cnt2 = 1;
char str1[MAXN], str2[MAXN];
int tmp1[MAXN], tmp2[MAXN];
int len1[MAXN];
void insert(int len, int num) {
	int p = 0;
	for (int i = 0; i < len; i++) {
		if (tree1[p].son[str1[i] - 'a'] == 0) {
			tree1[p].son[str1[i] - 'a'] = cnt1++;
		}
		p = tree1[p].son[str1[i] - 'a'];
	}
	tree1[p].end = num;
	p = 0;
	for (int i = 0; i < len; i++) {
		if (tree2[p].son[str2[i] - 'a'] == 0) {
			tree2[p].son[str2[i] - 'a'] = cnt2++;
		}
		p = tree2[p].son[str2[i] - 'a'];
	}
	tree2[p].end = num;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int n, q, ans = 0, cnt_b = 0;
	bool is_b = true;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> str1 >> str2;
		len1[i] = strlen(str1);
		insert(len1[i], i);
		for (int j = 0; j < len1[i]; j++) {
			if (str1[j] == 'b') {
				tmp1[i] = j;
			}
			if (str2[j] == 'b') {
				tmp2[i] = j;
			}
			if ((str1[j] != 'a' && str1[j] != 'b') || (str2[j] != 'a' && str2[j] != 'b')) {
				is_b = false;
				break;
			}
		}
	}
	if (is_b) {
		while (q--) {
			int len, pos1 = -1, pos2 = -1;
			int ans = 0;
			cin >> str1 >> str2;
			len = strlen(str1);
			if (len != strlen(str2)) {
				cout << 0 << "\n";
				continue;
			}
			for (int i = 0; i < len; i++) {
				if (pos1 != -1 && pos2 != -1) {
					break;
				}
				if (str1[i] == 'b') {
					pos1 = i;
				}
				if (str2[i] == 'b') {
					pos2 = i;
				}
			}
			for (int i = 1; i <= n; i++) {
				if (pos1 >= tmp1[i] && len - pos1 >= len1[i] - tmp1[i] && pos1 - tmp1[i] + tmp2[i] == pos2) {
					ans++;
				}
			}
			cout << ans << "\n";
		}
		return 0;
	}
	while (q--) {
		int len, p1 = 0, p2 = 0, last;
		ans = 0;
		cin >> str1 >> str2;
		len = strlen(str1);
		last = len - 1;
		if (len != strlen(str2)) {
			cout << 0 << "\n";
			continue;
		}
		while (last >= 0 && str1[last] == str2[last]) {
			last--;
		}
		for (int i = 0; i < len && (i == 0 || str1[i - 1] == str2[i - 1]); i++) {
			p1 = 0;
			p2 = 0;
			for (int j = i; j < len; j++) {
				if (tree1[p1].son[str1[j] - 'a'] == 0 || tree2[p2].son[str2[j] - 'a'] == 0) {
					break;
				}
				p1 = tree1[p1].son[str1[j] - 'a'];
				p2 = tree2[p2].son[str2[j] - 'a'];
				if (tree1[p1].end > 0 && tree2[p2].end > 0 && tree1[p1].end == tree2[p2].end && j + 1 > last) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

