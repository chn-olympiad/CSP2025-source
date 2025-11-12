#include <cstdio>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MAXSZ = 1 << 20;
char ch, buf[MAXSZ], *p1, *p2;
#define ge() (p1 == p2 && (p2 = buf + fread(p1 = buf, 1, MAXSZ, stdin), p1 == p2) ? EOF : *p1++)
template <typename T_T>
inline void read(T_T &x) {
	x = 0;
	
	while (ch < '0' || '9' < ch) ch = ge();
	while ('0' <= ch && ch <= '9') {
		x = x * 10 + (ch ^ 48);
		ch = ge();
	}
}
template <typename T_T>
inline void write(T_T x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 | 48); 
}
template <typename T_T>
inline T_T max(T_T a, T_T b) {return a > b ? a : b;}
template <typename T_T>
inline T_T min(T_T a, T_T b) {return a < b ? a : b;}
template <typename T_T>
inline void swap(T_T &x, T_T &y) {
	x ^= y;
	y ^= x;
	x ^= y; 
}

const int N = 2e5 + 5;
int n, T;
std::string S[N][2];
std::unordered_map <std::string, std::unordered_map <std::string, int> > cnt;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	scanf("%d%d", &n, &T);
	if (1ll * n * T <= 10000000) {
		for (int i = 1; i <= n; i++)
			std::cin >> S[i][0] >> S[i][1];
		while (T --) {
			std::string s, t; std::cin >> s >> t;
			
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				size_t idx = s.find(S[i][0]);
				
				while (true) {
					auto p = s.find(S[i][0], idx);
					if (p == std::string::npos)
						break;
					
					std::string tmp = s;
					tmp = tmp.substr(0, p) + S[i][1] + tmp.substr(p + S[i][0].size());
					if (tmp == t) ++ ans;
					idx = p + 1;
				}
			}
			
			write(ans), putchar('\n');			
		}
		
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		std::string s, t; std::cin >> s >> t;
		
		while (!s.empty()) {
			if (s.back() == t.back())
				s.pop_back(), t.pop_back();
			else break;
		}
		std::reverse(s.begin(), s.end());
		std::reverse(t.begin(), t.end());
		while (!s.empty()) {
			if (s.back() == t.back())
				s.pop_back(), t.pop_back();
			else break;
		}
		std::reverse(s.begin(), s.end());
		std::reverse(t.begin(), t.end());
		
		cnt[s][t] ++;
	}
	
	while (T --) {
		std::string s, t; std::cin >> s >> t;
		
		while (!s.empty()) {
			if (s.back() == t.back())
				s.pop_back(), t.pop_back();
			else break;
		}
		std::reverse(s.begin(), s.end());
		std::reverse(t.begin(), t.end());
		while (!s.empty()) {
			if (s.back() == t.back()) s.pop_back(), t.pop_back();
			else break;
		}
		std::reverse(s.begin(), s.end());
		std::reverse(t.begin(), t.end());
		
		write(cnt[s][t]), putchar('\n');
	}
	return 0;
}