#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>; 

#define lson (k << 1)
#define rson (k << 1 | 1)
#define endl '\n'

const int mod = 7 + 1e9;
const int N = 3 + 5e6;

#if CALC_SIZE 
bool st;
#endif


int sz[N];
vector<pair<short, int>> ne[N];
int id;
char s[N], t[N];

int suf[N];

int n, m;

void insert(const string &s, const string &t) {
	int rt = 0;
	for (int i = 0; i < s.size(); ++i) {
		short ch = s[i] * 128 + t[i];
		int p = 0;
		for (auto j : ne[rt]) {
			if (j.first == ch) {
				p = j.second;
				break;
			}
		}
		if (!p) {
			ne[rt].push_back({ch, ++id});
			p = id;
		}
		rt = p;
//		cout << p << endl;
	}
//	cout << endl;
	++sz[rt];
}

#if CALC_SIZE 
bool ed;
#endif

int main() {
	#if CALC_SIZE 
	cout << (&ed - &st) / 1024.0 / 1024 << endl;
	#endif
//	cout << log2(2e4) << endl;
//	return 0;
//	freopen("replace2.in", "r", stdin);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	
	while (n--) {
		string s, t;
		cin >> s >> t;
		insert(s, t);
	}
	
	while (m--) {
		cin >> s + 1;
		cin >> t + 1;
		
		int lens = strlen(s + 1), lent = strlen(t + 1);
		if (lens != lent) {
			cout << 0 << endl;
			continue;
		}
//		cout << "**** " << m << endl;
		
		
		for (int i = 1; i <= lens + 1; ++i) {
			suf[i] = 0;
		}
		suf[lens + 1] = 1;
		for (int i = lens; i >= 1; --i) {
			suf[i] = 1;
			if (s[i] != t[i]) {
				suf[i] = 0;
				break;
			}
		}
//		cout << "(((((((((())))))))))  " << lens << " " << suf[6] << endl;
//		cout << "???????" << endl;
		LL ans = 0;
		for (int i = 1; i <= lens; ++i) {
			int rt = 0;
			for (int j = i; j <= lens; ++j) {
				short ch = s[j] * 128 + t[j];
				int p = 0;
				for (auto k : ne[rt]) {
					if (k.first == ch) {
						p = k.second;
						break;
					}
				}
//				cout << "   " << i << " " << j << "    " << p << " ++++ " << suf[j +1] << "  " << sz[p] << endl;
				if (!p) {
					break;
				}
				rt = p;
				if (suf[j + 1]) {
					ans += sz[rt];
				}
			}
			if (s[i] != t[i]) {
				break;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}