#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define per(i, l, r) for (int i = (int)(r); i >= (int)(l); i--)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
using i64 = long long;
#define int i64
const int maxn = 1000050, mod = 998244353, B = 131;
int n, q;
namespace sub1 {
	struct node {
		string a, b;
		int preH, sufH, l, r;
	};
	int power(int a, int b) {
		int res = 1;
		for (; b; b /= 2, a = a * a % mod) {
			if (b % 2 == 1) {
				res = res * a % mod;
			} 
		}
		return res;
	}
	map<int, vector<node>> mp;
	int H1[maxn];
	int p[maxn];
	int dH(int l, int r) {
		return (H1[r] - H1[l - 1] * p[r - l + 1] % mod + mod) % mod;
	}
 	void solve() {
		
	p[0] = 1;
	rep(i, 1, maxn - 1) {
		p[i] = p[i - 1] * B % mod;
	}
		rep(i, 1, n) {
			string s[2];
			cin >> s[0] >> s[1];
			s[0] = ' ' + s[0];
			s[1] = ' ' + s[1];
			int len = s[0].size() - 1;
			int l = len, r = 1;
			rep(j, 1, len) {
				if (s[0][j] != s[1][j]) {
					l = j - 1;
					break;
				}
			}
			per(j, 1, len) {
				if (s[0][j] != s[1][j]) {
					r = j + 1;
					break;
				}
			}
			int H = 0;
			rep(j, l + 1, r - 1) {
				H = (H * B + s[0][j]) % mod;
				H = (H * B + s[1][j]) % mod;
			}
			int preH = 0, sufH = 0;
			rep(j, 1, l) {
				preH = (preH * B + s[0][j]) % mod;
			}
			rep(j, r, len) {
				sufH = (sufH * B + s[0][j]) % mod;
			}
			mp[H].push_back({s[0], s[1], preH, sufH, l, len - r + 1});
		}
		rep(i, 1, q) {
			string t[2];
			cin >> t[0] >> t[1];
			if (t[0].size() != t[1].size()) {
				cout << "0\n";
				continue;
			}
			t[0] = " " + t[0];
			t[1] = " " + t[1];
			int len = t[0].size() - 1, l = len, r = 1;
			rep(i, 1, len) {
				if (t[0][i] != t[1][i]) {
					l = i - 1;
					break;
				}
			}
			per(i, 1, len) {
				if (t[0][i] != t[1][i]) {
					r = i + 1;
					break;
				}
			}
			rep(i, 1, len) {
				H1[i] = (H1[i - 1] * B + t[1][i]) % mod;
//				cout << H1[i] << " ";
			}
//			cout << "\n";
			int H = 0;
			rep(i, l + 1, r - 1) {
				H = (H * B + t[0][i]) % mod;
				H = (H * B + t[1][i]) % mod;
			}
			vector<node> vec = mp[H];
			int ans = 0;
//			cout << l << " " << r << "\n";
			for (node _ : vec) {
//				cout << _.a << " " << _.b << "\n";
//				cout << _.l << " " << _.r << "\n";
//				cout << _.preH << " " << dH(l - _.l + 1, l) << " " << l - _.l + 1 << " " << l << "\n";
//				cout << _.sufH << " " << dH(r, r + _.r - 1) << "\n";
				
				if (dH(l - _.l + 1, l) == _.preH && dH(r, r + _.r - 1) == _.sufH) {
//					cout << "dfsgytrhuytru";
					ans++;
				}
			}
			cout << ans << "\n";
//			cout << "@@@@@@@@@" << ans << "\n";
		}
	}
}
//struct node {
//	vector<pair<int, pair<int, int>>> Q;
//	vector<pair<int, int>> a;
//};
//map<int, node> mp;
//int tr[maxn], ans[maxn];
//void add(int x, int k) {
//	for (; x < maxn; x += x & -x) {
//		tr[x] += k;
//	}
//}
//int ask(int x) {
//	int ans = 0;
//	for (; x; x -= x & -x) {
//		ans += tr[x];
//	}
//	return ans;
//}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
//	freopen("A.txt", "r", stdin);
//	freopen("B.txt", "w", stdout);
	cin >> n >> q;
//	if ((n < 2000 || q == 1)) {
		sub1::solve();//nq
//	}
//	rep(i, 1, n) {
//		string s[2];
//		cin >> s[0] >> s[1];
//		s[0] = ' ' + s[0];
//		s[1] = ' ' + s[1];
//		int len = s[0].size() - 1;
//		int l = len, r = 1, o = 0;
//		rep(j, 1, len) {
//			if (s[0][j] != s[1][j]) {
//				if(s[0][j] == 'a') {
//					o = 1;
//				} 
//				l = j - 1;
//				break;
//			}
//		}
//		per(j, 1, len) {
//			if (s[0][j] != s[1][j]) {
//				r = j + 1;
//				break;
//			}
//		}
////		cout << (r - l + 1) * 2 + o << " ";
//		mp[(r - l + 1) * 2 + o].a.push_back({l, len - r + 1});//相同前后缀的长度 
//	}
//	rep(i, 1, q) {
//		string t[2];
//		cin >> t[0] >> t[1];
//		if (t[0].size() != t[1].size()) {
////			cout << "0\n";
//			continue;
//		}
//		t[0] = " " + t[0];
//		t[1] = " " + t[1];
//		int len = t[0].size() - 1, l = len, r = 1, o = 0;
//		rep(i, 1, len) {
//			if (t[0][i] != t[1][i]) {
//				if (t[0][i] == 'a') {
//					o = 1;
//				} 
//				l = i - 1;
//				break;
//			}
//		}
//		per(i, 1, len) {
//			if (t[0][i] != t[1][i]) {
//				r = i + 1;
//				break;
//			}
//		}
////		cout << (r - l + 1) * 2 + o << " ";
//		mp[(r - l + 1) * 2 + o].Q.push_back({i, {l, len - r}});
//	}
//	for (auto __ : mp) {
//cout << "fdgthg";
//		node _ = __.second;
//		if (_.a.size() == 0 || _.Q.size() == 0){
//			continue;
//		}
//		sort(_.a.begin(), _.a.end());
//		sort(_.Q.begin(), _.Q.end(), [&](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
//			return a.second < b.second;
//		});
////		cout << "fdhgryyr";
//		int i = 0;
////		cout << _.Q.size() << "\n";
//		for (pair<int, pair<int, int>> qq : _.Q) {
////			cout << qq.second.first << " " << qq.second.second << "\n";
//			while (i < _.a.size() && qq.second.first >= _.a[i].first) {
////				cout << _.a[i].first << " " << _.a[i].second << "\n";
//				add(_.a[i].second, 1);
//				i++;
//			}
//			ans[qq.first] = ask(qq.second.second);
//		}
////		cout << "dfhgtrh";
//		i = 0;
//		for (pair<int, pair<int, int>> qq : _.Q) {
//			while (i < _.a.size() && qq.second.first >= _.a[i].first) {
//				add(_.a[i].second, -1);
//			i++;
//			}
//		}
//	}
////	cout << "dfhgth";
//	rep(i, 1, q) {
//		cout << ans[i] << "\n";
//	}
	return 0;
} 
//T3
//不会是AC自动机吧
//发现这个好像是只能进行同义替换一次
//其实是一段前缀一段后缀相同，替换中间不同的部分，感觉可以hash 
//先快速找到需要替换的部分，然后在s中找个数就做完了？？神秘 
//那我可要
//高兴早了，s的前后缀相等不代表t的里面和s相等 
//不过大概思路是没错的
//对于t我们还是找出不一样的位置，s也一样，但是这里要储存下来前缀相等的值和后缀相等的值
//现在的问题是给出m个对 
//还是不会爆了，zhengrui出过类似的，但是没有补 
