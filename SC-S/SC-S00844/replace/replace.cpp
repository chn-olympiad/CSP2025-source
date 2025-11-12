#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define LL long long
#define PII pair<int, int>
#define ULL unsigned long long 
const int N = 2e5 + 5, M = 5e6 + 5, Base = 131;
ULL p[M], h[M], hs[2][N];
vector<ULL> a[2][M];
inline ULL gethash(int l, int r){
	if(l > r) return 0;
	return h[r] - h[l - 1] * p[r - l + 1];
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	freopen("replace4.in", "r", stdin);
//	freopen("mine.ans", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		string s1, s2;
		cin >> s1 >> s2;
		for(int j = 0; j < s1.size(); ++j){
			hs[0][i] = hs[0][i] * Base + s1[j];
		}
		a[0][s1.size()].emplace_back(hs[0][i]);
		for(int j = 0; j < s2.size(); ++j){
			hs[1][i] = hs[1][i] * Base + s2[j];
		}
		a[1][s1.size()].emplace_back(hs[1][i]);
	}
	p[0] = 1;
	for(int i = 1; i <= M; ++i){
		p[i] = p[i - 1] * Base;
	}
	while(q--){
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size()){
			cout << "0\n";
			continue;
		}
		int l = t1.size(), r = 0, m = t1.size();
		ULL tmp = 0;
		for(int i = 0; i < m; ++i){
			h[i + 1] = h[i] * Base + t1[i];
			tmp = tmp * Base + t2[i];
			if(t1[i] != t2[i]){
				l = min(l, i);
				r = max(r, i);
			}
		}
//		cerr << l << ' ' << r << endl;
		LL ans = 0;
		for(int i = 0; i <= l; ++i){
			for(int j = r; j < m; ++j){
				int o = j - i + 1;
				for(int k = 0; k < a[0][o].size(); ++k){
					if(a[0][o][k] != gethash(i + 1, j + 1)) continue;
//					cerr << "HELLO! " << i << ' ' << j << '\n' ;
//					cerr << h[i] * p[m - i] << ' ' << a[1][o][k] * p[m - j - 1] << ' ' << gethash(j + 2, m) << '\n';
					if(h[i] * p[m - i] + a[1][o][k] * p[m - j - 1] + gethash(j + 2, m) == tmp){
						++ans;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
