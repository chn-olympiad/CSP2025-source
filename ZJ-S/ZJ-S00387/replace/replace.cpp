#include <iostream>

int n = 0;
int q = 0;
std::string str[200001][2] = {};
int sum[200001] = {};
int next[5000001] = {};
bool is_sp = true;
int dir[200001][2] = {};

void init() {
	for (int i = 1; i <= n; ++i) {
		dir[i][0] = dir[i][1] = -1;
		for (int j = 0; j < str[i][0].size(); ++j) {
			if (str[i][0][j] != 'a' && str[i][0][j] != 'b') {
				is_sp = false;
				return;
			}
			if (str[i][0][j] == 'b') {
				if (~dir[i][0]) {
					is_sp = false;
					return;
				} else {
					dir[i][0] = j;
				}
			}
		}
		for (int j = 0; j < str[i][1].size(); ++j) {
			if (str[i][1][j] != 'a' && str[i][1][j] != 'b') {
				is_sp = false;
				return;
			}
			if (str[i][1][j] == 'b') {
				if (~dir[i][1]) {
					is_sp = false;
					return;
				} else {
					dir[i][1] = j;
				}
			}
		}
	}
}

bool sp(std::string st, std::string ed) {
	int cnt = 0;
	for (int i = 0; i < st.size(); ++i) {
		if (st[i] != 'a' && st[i] != 'b') {
			return false;
		}
		if (st[i] == 'b') {
			++cnt;
		}
	}
	if (cnt != 1) {
		return false;
	}
	
	cnt = 0;
	for (int i = 0; i < ed.size(); ++i) {
		if (ed[i] != 'a' && ed[i] != 'b') {
			return false;
		}
		if (ed[i] == 'b') {
			++cnt;
		}
	}
	if (cnt != 1) {
		return false;
	}
	
	return true;
}

int kmp(std::string st, std::string ed) {
//	int beg = -1;
//	int end = 0;
//	for (int i = 1; i < st.size(); ++i) {
//		if (st[i] != ed[i]) {
//			end = i;
//			if (beg == -1) {
//				beg = i;
//			}
//		}
//	}
//	
//	int ans = 0;
//	for (int i = 1; i <= n; ++i) {
//		bool flag = false;
//		for (int j = end - str[i][0].size(), k = 0; j <= end; ++j) {
//			if (k == str[i])
//			if (st[j] == str[i][0][k]) {
//				++k;
//			} else {
//				
//			}
//		}
//		ans += flag;
//	}
	return 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		std::cin >> str[i][0] >> str[i][1];
	}
	init();
	
	while (q--) {
		std::string st;
		std::string ed;
		std::cin >> st >> ed;
		
		if (st.size() != ed.size()) {
			std::cout << "0\n";
			continue;
		}
		
		if (is_sp) {
			if (sp(st, ed)) {
				int dst = 0;
				int ded = 0;
				for (int i = 0; i < st.size(); ++i) {
					if (st[i] == 'b') {
						dst = i;
						break;
					}
				}
				for (int i = 0; i < ed.size(); ++i) {
					if (ed[i] == 'b') {
						ded = i;
						break;
					}
				}
				
				int ans = 0;
				int diff = ded - dst;
				for (int i = 1; i <= n; ++i) {
					if (dir[i][1] - dir[i][0] == diff && 
						str[i][1].size() - dir[i][1] <= ed.size() - ded && dir[i][0] <= dst) {
						++ans;
					}
				}
				
				std::cout << ans << "\n";
				
				continue;
			}
		}
		std::cout << kmp(st, ed) << "\n";
	}
	
	return 0;
}
