#include<bits/stdc++.h>
#define rep(_id, _st, _ed) for(int (_id) = (_st); _id <= (_ed); _id++)
#define per(_id, _st, _ed) for(int (_id) = (_st); _id >= (_ed); _id--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << " : " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

typedef long long i64;
typedef unsigned long long u64;

constexpr int maxn = 5000005;
constexpr int maxq = 200005;

int n, q;

namespace ctlqwq {
	constexpr i64 mod[] = { 998244353, 1e9 + 7, 1e9 + 9 };
	i64 base;
	i64 pw[3][maxn];
	
	inline void init() {
		std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
		base = rng() % mod[0];
		int N = 5000000;
		rep (j, 0, 2) {
			pw[j][0] = 1;
			rep (i, 1, N) pw[j][i] = pw[j][i - 1] * base;
		}
	} 
	
	typedef std::array<i64, 3> Hash;
	struct Hashs {
		std::vector<Hash> h;
		inline void gen(std::string s) {
			h = {};
			h.push_back({0, 0, 0});
			rep (i, 1, (int) s.size() - 1) {
				Hash h0; 
				rep (j, 0, 2) {
					h0[j] = (h.back()[j] * base % mod[j] + (s[i] - 'a')) % mod[j];
				}
				h.push_back(h0); 
			}
		}
		
		inline Hash sub(int l, int r) {
			Hash res = {0, 0, 0}; 
			if (l <= r) {
				rep (j, 0, 2) {
					res[j] = ((h[r][j] - h[l - 1][j] * pw[j][r - l + 1] % mod[j]) % mod[j] + mod[j]) % mod[j];
				}
			}
			return res;
		}
	};
	
	Hashs sh[maxq][2];
	std::string s[maxq][2], t[maxq][2];
	
	namespace Task0 {
		Hash suf[maxn], pre[maxn];
		inline void calc(const std::string &t0, const std::string &t1) {
//			dbg(t0); dbg(t1); 
			int Tl = 1; while (t0[Tl] == t1[Tl]) Tl++;
			int Tr = t0.size() - 1; while (t0[Tr] == t1[Tr]) Tr--;
			
//			dbg(Tl); dbg(Tr);

			Hashs th0; th0.gen(t0);
			Hashs th1; th1.gen(t1);
			
			Hash T0 = th0.sub(Tl, Tr);
			Hash T1 = th1.sub(Tl, Tr);
			
//			rep (i, 1, Tl) {
//				suf[i] = th0.sub(Tl - 1 - i + 1, Tl - 1);
//			}
//			
//			rep (i, Tr + 1, t0.size() - 1) {
//				pre[i - (Tr + 1) + 1] = th0.sub(Tr + 1, Tr + 1 + i - 1);
//			}
			
			int ans = 0;
			rep (i, 1, n) {
				int Sl = 1; while (s[i][0][Sl] == s[i][1][Sl]) Sl++;
				int Sr = s[i][0].size() - 1; while (s[i][0][Sr] == s[i][1][Sr]) Sr--;
				if (Sl > Sr) continue;
				
//				dbg(Sl); dbg(Sr);
				if (Sr - Sl == Tr - Tl and sh[i][0].sub(Sl, Sr) == T0 and sh[i][1].sub(Sl, Sr) == T1) {
//					db << "kkkkkk\n";
					if (sh[i][0].sub(1, Sl - 1) == th0.sub((Tl - 1) - (Sl - 1) + 1, Tl - 1)) {
//						db << "11111\n";
						int len = (s[i][0].size() - 1) - (Sr + 1) + 1;
//						dbg(len);
						if (sh[i][0].sub(Sr + 1, (Sr + 1) + len - 1) == th0.sub(Tr + 1, (Tr + 1) + len - 1)) {
//							db << "222222\n";
//							dbg(i);
							ans++;
						}
					}
				}
			}
			
			std::cout << ans << "\n";
		}
		
		inline void solve() {
			rep (i, 1, q) {
				calc(t[i][0], t[i][1]);
			}
		}
	}	
	
	inline void solve() {
		std::cin >> n >> q;
		rep (i, 1, n) {
			std::cin >> s[i][0] >> s[i][1];
			s[i][0] = " " + s[i][0];
			s[i][1] = " " + s[i][1];
			sh[i][0].gen(s[i][0]);
			sh[i][1].gen(s[i][1]);
		}
		
		rep (i, 1, q) {
			std::cin >> t[i][0] >> t[i][1];
			t[i][0] = " " + t[i][0];
			t[i][1] = " " + t[i][1];
		}
		
		Task0::solve(); 
	}
}

inline void solve() {
	ctlqwq::solve();
}

int main() {
	fastread

	file("replace")

	solve();

	return 0;
}


