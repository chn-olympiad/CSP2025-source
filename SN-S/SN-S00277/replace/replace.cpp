#include<bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 114, A = 5e6 + 114;
int n, t;
string a[N][2];
void solve0() {
	while(t--) {
		string x, y; cin >>x >>y;
		if(x.size() != y.size()) {cout <<"0\n"; continue;}
		const int sz = x.size();
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			const int asz = a[i][0].size();
			for(int j = 0; j + asz - 1 < sz && (!j || x[j - 1] == y[j - 1]); ++j) {
				int p = 0;
				while(p < asz && a[i][0][p] == x[j + p] && a[i][1][p] == y[j + p]) ++p;
				if(p == asz) {
					while(j + p < sz && x[j + p] == y[j + p]) ++p;
					if(j + p == sz) ++ans;
				}
			}
		}
		cout <<ans <<'\n';
	}
}
bool check() {
	for(int i = 1; i <= n; ++i) for(int j = 0; j < 2; ++j) {
		bool flag = false;
		for(int k = 0; k < a[i][j].size(); ++k)
			switch(a[i][j][k]) {
				case 'a': break;
				case 'b':
					if(flag) return false;
					flag = true;
				break;
				default: return false;
			}
		if(!flag) return false;
	}
	return true;
}
int cnt[A << 1 | 1];
void solve1() {
	for(int i = 1; i <= n; ++i) {
		int d0 = 0, d1 = 0;
		for(int j = 0; j < a[i][0].size(); ++j)
			if(a[i][0][j] == 'b') {d0 = j; break;}
		for(int j = 0; j < a[i][1].size(); ++j)
			if(a[i][1][j] == 'b') {d1 = j; break;}
		++cnt[d0 - d1 + A];
	}
	while(t--) {
		string x, y; cin >>x >>y;
		if(x.size() != y.size()) {cout <<"0\n"; continue;}
		const int sz = x.size();
		int dx = 0, dy = 0;
		for(int j = 0; j < sz; ++j) if(x[j] == 'b') {dx = j; break;}
		for(int j = 0; j < sz; ++j) if(y[j] == 'b') {dy = j; break;}
		cout <<cnt[dx - dy + A] <<'\n';
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >>n >>t;
	int sum = 0;
	for(int i = 1; i <= n; ++i) cin >>a[i][0] >>a[i][1], sum += a[i][0].size() + a[i][1].size();
	if(check()) solve1();
	else solve0();
	return 0;
}
