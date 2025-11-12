#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
const int BASE = 13331;


map<string, vector<string> > E;
int n, q;
string A[MAXN];


void Solve_1_1(string a, string b) {
	int len = a.size();
	a = " " + a; b = " " + b;
	int ans = 0;
	for(int l = 1; l <= len; l ++) {
		for(int r = l; r <= len; r ++) {
			bool bj = true;
			for(int i = 1; i < l; i ++) if(a[i] != b[i]) {
				bj = false; break ;
			}
			for(int i = r + 1; i <= len; i ++) if(a[i] != b[i]) {
				bj = false; break ;
			}
			if(!bj) continue ;
			string c = "", chan = "";
			for(int i = l; i <= r; i ++) chan += b[i];
			for(int i = l; i <= r; i ++) c += a[i];
			for(string x : E[chan]) if(x == c) ans ++;
		}
	}
	cout << ans << "\n";
	return ;
}

void Solve_1() {
	for(int i = 1; i <= n; i ++) {
		string a, b; cin >> a >> b;
		A[i] = b;
		E[b].push_back(a);
	}
	while(q --) {
		string a, b; cin >> a >> b;
		if(a.size() != b.size()) {
			cout << 0 << "\n"; continue ;
		}
		Solve_1_1(a, b);
	}
	for(int i = 1; i <= n; i ++) E[A[i]].clear();
}

struct _C{
	string aa, bb;
} C[MAXN];

void Solve_2() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		string a, b; cin >> a >> b;
		C[i] = {a, b};
	}
	while(q --) {
		int ans = 0;
		string a, b; cin >> a >> b;
		if(a.size() != b.size()) {
			cout << 0; continue ;
		}
		int l = 0, r = 0, L = 0, R = 0;
		for(int i = 0; i < a.size(); i ++) if(a[i] == 'b') l = i;
		for(int i = 0; i < b.size(); i ++) if(b[i] == 'b') r = i;
		for(int i = 1; i <= n; i ++) {
			string x = C[i].aa, y = C[i].bb;
			for(int j = 0; j < x.size(); j ++) {
				if(x[j] == 'b') L = j;
				if(y[j] == 'b') R = j;
			}
			if(L > l) continue ;
			if(R - L != r - l) continue ;
			if(x.size() - L > a.size() - l) continue ;
			ans ++;
		}
		cout << ans << "\n";
	}
}

int main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	if(n <= 100) {
		Solve_1(); return 0;
	}
	Solve_2();
	
	return 0;
	
}

